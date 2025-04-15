#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 15
char c_queue[BUFFER_SIZE];  //  circular buffer will be represeted by this
int prod_write_in = 0;
int cons_read_out = 0;
int count = 0; // <----DO NOT FORGET (ME): Number of items in buffer
int done = 0;  // Help tells me the EOF

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;

void* producer_func(void* arg) {
    FILE *fileptr = fopen("string.txt", "r");
    if (fileptr == NULL) {
        printf("Could not open file\n");
        return NULL;
    }

    char character;
    while ((character = fgetc(fileptr)) != EOF) {
        pthread_mutex_lock(&mutex);

        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&not_full, &mutex);
        }

        c_queue[prod_write_in] = character;
        prod_write_in = (prod_write_in + 1) % BUFFER_SIZE;
        count++;

        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_lock(&mutex);
    done = 1; // <Kind of like a chek: Signal that production is done
    pthread_cond_signal(&not_empty); // Wake up consumer if waiting
    pthread_mutex_unlock(&mutex);

    fclose(fileptr);
    return NULL;
}

void* consumer_func(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        while (count == 0 && !done) {
            pthread_cond_wait(&not_empty, &mutex);
        }

        if (count == 0 && done) {
            pthread_mutex_unlock(&mutex);
            break; 
        }

        char character = c_queue[cons_read_out];
        cons_read_out = (cons_read_out + 1) % BUFFER_SIZE;
        count--;

        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);

        putchar(character); // Print the character outside the lock
        fflush(stdout);
    }

    return NULL;
}

int main() {
    pthread_t producer_thread;
    pthread_t consumer_thread;

    pthread_create(&producer_thread, NULL, producer_func, NULL);
    pthread_create(&consumer_thread, NULL, consumer_func, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_empty);
    pthread_cond_destroy(&not_full);

    printf("\nProgram completed successfully.\n");
    return 0;
}
