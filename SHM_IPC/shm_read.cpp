#include<iostream>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(){
    key_t key = ftok("shmfile",65);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    char* str = ((char*)shmat(shmid,(void*)0,0));
    printf("Data Written in shm is: %s",str);
    shmdt(str);
    shmctl(shmid,IPC_RMID,NULL);


}