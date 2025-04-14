#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFFER_SIZE 15
char c_queue[BUFFER_SIZE];  //shared between consumer + producer
int prod_write_in = 0;
int cons_read_out = 0;
int count = 0; //supposed to tell amount of items in buffer


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;

void main(){

//used to declare thread values
pthread producer consumer;

//declare the 

//create the pthread variables

int producer_thread ;
int consumer__thread ;

//create the pthread variables
pthread_create(&producer_thread,NULL,producer_func,NULL);
pthread_create(&consumer__thread,NULL,consumer_func,NULL);


pthread_mutex_destroy(&mutex);
pthread_cond_destroy(&not_empty);
pthread_cond_destroy(&not_full);
    
printf("\nProgram completed successfully.\n");

}//end main



//function has to look like this when declaring
void* producer_func(void* arg) {
    FILE *fileptr = fopen("string.txt", "r");
    if (fileptr == NULL) {
        printf("Could not open file\n");
        return NULL;
    }

    char character;
    while ((character = fgetc(fileptr)) != EOF) {
        pthread_mutex_lock(&mutex);

        // Wait while buffer is full
        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&not_full, &mutex);
        }

        // Write character to buffer
        buffer[prod_write_in] = character;
        prod_write_in = (prod_write_in + 1) % BUFFER_SIZE; // Update index
        count++;

        // Signal consumer that buffer is not empty
        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);
    }

    // After EOF, you might want to signal the consumer that production is done
    pthread_mutex_lock(&mutex);
   
    fclose(fileptr);
    return NULL;
}//producer_func


void* consumer_func(void* arg) {

  char character;
    while (1) { //infinite loop needs to be brocken <----Remember
        pthread_mutex_lock(&mutex);

        // Wait while buffer is empty
        while (count == 0) {
            pthread_cond_wait(&not_empty, &mutex);
        }

	
        // Write character to buffer
        buffer[cons_read_out] = character;
        cons_read_out = (cons_read_out + 1) % BUFFER_SIZE; // Update index
        count--;

        // Signal consumer that buffer is not empty and producer is availiab;e
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);
    }

	//prints character
	putchar(character);

    // After EOF, you might want to signal the consumer that production is done
    pthread_mutex_lock(&mutex);
   
    fclose(fileptr);
    return NULL;
}



}//consumer_func

