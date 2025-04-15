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

//Initialiaes all the thread variables that will be used further down
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;

void* producer_func(void* arg) {
    //opens the file for reading
    FILE *fileptr = fopen("string.txt", "r");
    if (fileptr == NULL) {
        printf("Could not open file\n");
        return NULL;
    }

    char character;

    //read until you go to end of file <- lock mutex so nothing else can use the variables
    while ((character = fgetc(fileptr)) != EOF) {
        pthread_mutex_lock(&mutex);

        //checks if buffer is full to tell producer to wait
        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&not_full, &mutex);
        }

        //stores the character in the queue at current index
        c_queue[prod_write_in] = character;
        //FORMULA that helps save index in a circular queue
        prod_write_in = (prod_write_in + 1) % BUFFER_SIZE;

        //increment count -> will help with checking if buffer is full or not
        count++;

        //tells consumer that thread is not empty so wake up 
        pthread_cond_signal(&not_empty);

        //unlock mutex so we can access everthing
        pthread_mutex_unlock(&mutex);
    }

    //this chunk is a final flag that tells the consumer we are dones
    pthread_mutex_lock(&mutex);
    done = 1; // <Kind of like a chek: Signal that production is done
    pthread_cond_signal(&not_empty); // Wake up consumer if waiting (General idea)
    pthread_mutex_unlock(&mutex);

    fclose(fileptr);
    return NULL;
}

void* consumer_func(void* arg) {
    //reason why one is here is to signify an infinite loop until uffer is empty
    while (1) {
        pthread_mutex_lock(&mutex);

        //checks if buffer is empty and if the producer is dne
        while (count == 0 && !done) {
            pthread_cond_wait(&not_empty, &mutex);
        }

        //looks at if there is antything to get if not it breaks
        if (count == 0 && done) {
            pthread_mutex_unlock(&mutex);
            break; 
        }

        //updates index into buffer and decrement the count -> one less thing in the buffer
        char character = c_queue[cons_read_out];
        cons_read_out = (cons_read_out + 1) % BUFFER_SIZE;
        count--;

        //tells producer there is space in the buffer
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);

        putchar(character); // Print the character outside the lock
        fflush(stdout);
    }

    return NULL;
}

int main() {
    //declares threads here
    pthread_t producer_thread;
    pthread_t consumer_thread;

    //creates threads here
    pthread_create(&producer_thread, NULL, producer_func, NULL);
    pthread_create(&consumer_thread, NULL, consumer_func, NULL);

    //join threads here
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    //erases threads here
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_empty);
    pthread_cond_destroy(&not_full);

    //basically a portion that tells us that the function is complete
    printf("\nProgram completed successfully.\n");
    return 0;
}
