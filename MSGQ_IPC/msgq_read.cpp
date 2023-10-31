#include<iostream>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/msg.h>
using namespace std;
struct msgbuff{
    long mtype;
    char mtext[100];
}message;
int main(){
    key_t key = ftok("progfile",65);
    int msgid = msgget(key,0666|IPC_CREAT);
    msgrcv(msgid,&message,sizeof(message),1,6);
    printf("Data in message queue is %s : ",message.mtext);
    msgctl(msgid,IPC_RMID,NULL);
    return 0;
}