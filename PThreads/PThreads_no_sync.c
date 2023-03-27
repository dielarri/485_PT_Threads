#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


unsigned int count = 0;

void *counter(void *x){
	long limit = (long) x;
	for (int i=0; i < limit; i++){
		count ++;
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
	printf("%u\n", count);
	pthread_exit(NULL);
}