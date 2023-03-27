#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
long long count = 0;

void *counter(){
	for (int z=0; z < 50000; z++){
		pthread_mutex_lock(&count_mutex);
		count ++;
		pthread_mutex_unlock(&count_mutex);
	}
pthread_exit(NULL);
}

int main(int argc, char *argv[]){
	int status, i;
	long x, y;
	
	if(argc>2){
		i = atoi(argv[1]);
		x = (long)atoi(argv[2]);
	}else{
		x = 1000;
		i = 4;
	}
	pthread_t threads[x];
	for(y=0; y < i; y++){
		status = pthread_create(&threads[y], NULL, counter, (void *)x);
		if (status != 0){
			printf("pthread_create return error code %d\n", status);
			exit (-1);
		}
	}
	printf("Result: %d\n", count);
	pthread_exit(NULL);
}