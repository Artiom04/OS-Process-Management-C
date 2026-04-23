#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main(){
    pid_t pid = fork();
    if(pid == 0){
        pid_t p = getpid();
        printf("Processo Figlio: %i\n",p);
    }else{
        fork();
        pid_t p = getpid();
        printf("%i\n",p);
    }
    wait(0);
    wait(0);
    return 0;
}