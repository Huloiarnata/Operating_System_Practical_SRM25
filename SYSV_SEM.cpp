#include<iostream>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/ipc.h>
using namespace std;
int main(){
    int semid = semget((key_t)6,1,0666|IPC_CREAT);
    pid_t pid = fork();
    struct sembuf sop;
    sop.sem_flg = 0;
    sop.sem_num =0;
    sop.sem_op =0;
    if(pid!=0){
        sleep(1);
        cout<<"Parent waits for wait signal\n";
        semop(semid,&sop,1);
        cout<<"The parent waked up & doing her job\n";
        sleep(10);
        cout<<"Parent over\n";
    }else{
        cout<<"Child set wait signal & doing her job\n";
        semctl(semid,0,SETVAL,1);
        sleep(10);
        cout<<"Child sets wake singal & doing her job\n";
        semctl(semid,0,SETVAL,0);
        cout<<"Child over\n";
    }
    return 0;
}