#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <time.h>

int main(){
    int fd[2];
    int fd2[2];

    pipe(fd);
    pipe(fd2);

    pid_t pid = fork();
    
    if(pid == 0){
        close(fd[1]);
        close(fd2[0]);

        read(fd[0],&pid, sizeof(pid));
        printf("Il figlio riceve il PID: %d\n", pid);
        close(fd[0]);


        write(fd2[1], &pid, sizeof(pid));
        close(fd2[1]);

    }else{

        pid = fork();
        if(pid == 0){
            close(fd[0]);
            close(fd[1]);
            close(fd2[1]);

            read(fd2[0],&pid, sizeof(pid));
            printf("Il secondo figlio riceve PID: %d\n", pid);

            close(fd2[0]);

        }else{
            close(fd2[0]);
            close(fd2[1]);
            close(fd[0]);
            
            pid_t pid = getpid();

            write(fd[1],&pid, sizeof(pid));
            printf("Il padre manda il suo PID: %d\n", pid);
            
            close(fd[1]);
            wait(0);
            wait(0);
        }
    }
}