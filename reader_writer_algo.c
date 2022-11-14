
/***********Implementation of reader-writer algorithm in C using semaphore and*************** ******************************multithreading....********************************************/


#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>

sem_t wrt; //semaphore variable
int count=0;
int cnt=1;
pthread_mutex_t mutex;


void *read(void *r){
	pthread_mutex_lock(&mutex);
	count=count+1;
	//printf("\treader:%d\n",count);
	if(count==1){
		sem_wait(&wrt);
		//break;
	}
	pthread_mutex_unlock(&mutex);
	printf("%d Reader is reading the content\n",cnt);
	//sleep(1);
	pthread_mutex_lock(&mutex);
	printf("%d Reader leaving ",cnt);
	count=count-1;
	if(count==0){
		sem_post(&wrt);
	}
	pthread_mutex_unlock(&mutex);
}

void *writer(void *w){
	sem_wait(&wrt);
	cnt=cnt+1;
	printf("\nWriting  the content\n");
	sem_post(&wrt);	
}
int main(){
pthread_t r[100],w[100];
pthread_mutex_init(&mutex,NULL);
sem_init(&wrt,0,1);
int num;
//printf("\nEnetr the no of reader you want\n");
//scanf("%d",&num);
for(int i=0;i<4;i++){
	pthread_create(&r[i],NULL,(void *)read,(void *)&r[i]);
	//printf("%d",i);
	pthread_create(&w[i],NULL,(void *)writer,(void *)&w[i]);
	pthread_join(r[i],NULL);
	pthread_join(w[i],NULL);
	}

}

