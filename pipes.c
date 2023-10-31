#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    char buff[25];
    int p[2];pipe(p);
    pid_t pid = fork();
    if(pid<0){
        printf("Error creating process\n");
    }else if(pid==0){
        printf("Writting into pipe");
        write(p[1],"Welcome",8);
        printf("Writting Complete. Exiting child\n");
    }else{
        wait(NULL);
        printf("Reading pipe\n");
        read(p[0],buff,8);
        printf("Pipe contents are : %s", buff);
    }
}