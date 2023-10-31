 #include<stdio.h>
 #include<unistd.h>
 #include<pthread.h>
 #include<semaphore.h>
 sem_t mutex;
 void* thread(void* args){
    sem_wait(&mutex);
    printf("Entering into critical section....\n");
    sleep(4);
    printf("Exiting...\n");
    sem_post(&mutex);

 }
 int main(){
    pthread_t t1,t2;
    sem_init(&mutex,0,1);
    pthread_create(&t1,NULL,thread,NULL);
    sleep(2);
    pthread_create(&t2,NULL,thread,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    return 0;
 }