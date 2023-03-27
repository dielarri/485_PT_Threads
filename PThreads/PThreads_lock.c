#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


pthread_mutex_t count_mutex;
long long count = 0;

void *counter(){
	pthread_mutex_lock(&count_mutex);
	count += 1;
	pthread_mutex_unlock(&count_mutex);
}

long long get_count(){
	long long a;
	pthread_mutex_lock(&count_mutex);
	a = count;
	pthread_mutex_unlock(&count_mutex);
	return(a);
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