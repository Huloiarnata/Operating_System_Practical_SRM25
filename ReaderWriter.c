#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
sem_t x, y;
pthread_t tid;
pthread_t readerthread[100], writerthread[100]; 
int readercount =0;
void* reader(void* args){
    sem_wait(&x);
    readercount++;
    if(readercount==1){
        sem_wait(&y);
    }
    sem_post(&x);
    printf("%d Reader Entering...\n",readercount);
    sleep(3);
    sem_wait(&x);
    readercount--;
    if(readercount==0){
        sem_post(&y);
    }
    sem_post(&x);
    printf("%d Reader is leaving...\n",readercount+1);
    return NULL;
}
void* writer(void* args){
    printf("Writer trying to write..\n");
    sem_wait(&y);
    printf("Write is done..\n");
    sem_post(&y);
    printf("Writer exiting..\n");
    return NULL;
}
int main(){
    int n1,i;
    printf("Enter number of reader: ");
    scanf("%d",&n1);
    int n2[n1];
    sem_init(&x,0,1);
    sem_init(&y,0,1);
    for(i=0;i<n1;i++){
        pthread_create(&writerthread[i],NULL,reader,NULL);
        pthread_create(&readerthread[i],NULL,writer,NULL);
    }
    for(i=0;i<n1;i++){
        pthread_join(writerthread[i],NULL);
        pthread_join(readerthread[i],NULL);
    }

}