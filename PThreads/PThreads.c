#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

int counter = 0;
int x = 4;
int y = 10000;
pthread_mutex_t count_mutex;

void *print_thread(void *tid){
	/*this function prints the threads identifier and then exits. */
	printf("Greetings from thread %d\n", tid, counter);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){
	/* The main program creates 10 threads and then exits */
	pthread_t threads[NUMBER_OF_THREADS];
	int status, i;
	//counter += y;
	counter = strtol(argv[1], NULL, 10);
	pthread_mutex_lock(&count_mutex);
	counter = counter + 1;
	pthread_mutex_unlock(&count_mutex);
	//counter = y * counter;
	for (i=0;i< NUMBER_OF_THREADS; i++){
		printf("Creating thread %d\n", i);
		status = pthread_create(&threads[i], NULL, print_thread, (void *)i);
		
		if (status != 0){
			printf("Oops. pthread_create returned error code %d\n", status);
			exit(-1);
		}
	}
	printf("Counter = %d\n", counter);
	exit(NULL);
	
}