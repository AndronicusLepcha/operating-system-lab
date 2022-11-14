/***************************Producer and consumer in C****************************************/

#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include<pthread.h>

#define MaxItems 5
#define BufferSize 5
sem_t empty;
sem_t full;
int in=0;
int out=0;
int buffer[BufferSize];
pthread_mutex_t mutex;
void producer(void *pno){

	int item;
	for(int i=0;i<MaxItems;i++){
		item=rand(); //produce and item randomly
		sem_wait(&empty);//empty -1
		pthread_mutex_lock(&mutex);//Decrementing mutex
		buffer[in]=item;
		printf("Producer produced :%d\n",buffer[in]);
		in = (in+1)%BufferSize;
		pthread_mutex_unlock(&mutex); //unlock thr mutex
		sem_post(&full);//increment the full
	}
}

void *consumer(void *cno){
	for(int i=0;i<MaxItems;i++){	
		sem_wait(&full); //Decrement Full
		pthread_mutex_lock(&mutex);
		int item=buffer[out];
		printf("Consumer consumed : %d\n",item);
		out=(out+1)%BufferSize;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}

int main(){
	pthread_t pro[5],con[5];
	pthread_mutex_init(&mutex,NULL);
	sem_init(&empty,0,BufferSize);
	sem_init(&full,0,0);
	int a[5]={1,2,3,4,5}; //numbering the consumer and producer
	
	for(int i=0;i<5;i++){
		pthread_create(&pro[i],NULL,(void *)producer,(void *)&a[i]);
	}		
	for(int i=0;i<5;i++){
		pthread_create(&con[i],NULL,(void *)consumer, (void *)&a[i]);
	}
	for(int i=0;i<5;i++){
		pthread_join(pro[i],NULL);
	}
	for(int i=0;i<5;i++){
		pthread_join(con[i],NULL);
	}
//	pthread_mutex_destroy(&mutex);
//	sem_destroy(&empty);
//	sem_destroy(&full);
	return 0;
}
