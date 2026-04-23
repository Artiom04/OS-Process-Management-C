#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main(){
    int status;
    pid_t pid = fork();
    if(pid == 0){
        pid_t p = getpid();
        printf("%i\n",p);
    }else{
        pid_t p = getpid();
        printf("%i\n",p);
    }
    wait(&status);
    return 0;
}