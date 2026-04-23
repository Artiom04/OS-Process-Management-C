#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main(){
    int fd[2];
    pipe(fd);

    pid_t pid = fork();

    if(pid == 0){
        close(fd[0]);

        pid = getpid();

        write(fd[1], &pid, sizeof(pid));
        printf("Figlio manda PID: %d\n", pid);

        close(fd[1]);
    }else{
        close(fd[1]);

        pid_t bufPid;

        read(fd[0],&bufPid,sizeof(bufPid));
        printf("Il pid ricevuto è: %d", bufPid);
        
        close(fd[0]);
        wait(0);
    }
}