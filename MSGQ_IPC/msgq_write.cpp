#include<iostream>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/msg.h>
#define MAX 10
struct mesgbuff{
    long metype;
    char mtext[100];
}message;
int main(){
    key_t key = ftok("progfile",65);
    int msgid = msgget(key,0666|IPC_CREAT);
    message.metype = 1;
    std::cout<<"Enter data : ";
    fgets(message.mtext,MAX,stdin);
    msgsnd(msgid,&message,sizeof(message),0);
    return 0;
}