#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n = 5;
    pid_t pid = fork();
    
    if (pid < 0) {
        printf("Error: fork() failed.\n");
        exit(1);
    } else if (pid == 0) {
        // child process calculates the factorial of n
        int result = factorial(n);
        printf("Factorial of %d is %d.\n", n, result);
    } else {
        // parent process calculates the Fibonacci sequence up to n
        for(int i=0;i<n;i++){
            printf("%d ",fibonacci(i));
        }
        wait(NULL); // wait for child process to finish
    }
    
    return 0;
}
