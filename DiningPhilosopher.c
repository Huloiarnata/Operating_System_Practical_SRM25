#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
sem_t chopsticks[5];
sem_t room;
void eat(int n){
    printf("Philosopher %d is trying to eat\n",n);
}
void* philosopher(void* n){
    int ph = *(int*)n;
    printf("Philosopher waiting to eat\n");
    printf("Philosopher %d tries to pick left chopstick\n",ph);
    sem_wait(&chopsticks[ph]);
    printf("Philosopher %d pick left chopstick\n",ph);
    printf("Philosopher %d tries to pick right chopstick\n",ph);
    sem_wait(&chopsticks[(ph+1)%5]);
    printf("Philosopher %d pick right chopstick\n",ph);
    eat(ph);
    sleep(3);
    printf("Philosopher %d has finished eating\n",ph);
    sem_post(&chopsticks[(ph+1)%5]);
    printf("Philosopher %d leaves right chopstick\n",ph);
    sem_post(&chopsticks[ph]);
    printf("Philosopher %d leaves left chopstick\n",ph);
}
int main(){
    int n[5],i;
    pthread_t t[5];
    for(i=0;i<5;i++){
        sem_init(&chopsticks[i],0,1);
    }
    for(i=0;i<5;i++){
        n[i] = i;
        pthread_create(&t[i],NULL,philosopher,(void*)&n[i]);
    }
    for(i=0;i<5;i++){
        pthread_join(t[i],NULL);
    }


}