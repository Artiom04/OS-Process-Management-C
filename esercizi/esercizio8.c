#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main(){
    int fd[2];pipe(fd);

    pid_t pid = fork();
    if(pid == 0){
        int n;
        printf("Inserisci un numero tra 0 e 35: ");
        scanf("%d" &n);

        write(fd[1], &n, sizeof(n));
        close(fd[1]);
        
    }else{

        int fd2[2];
        int n2;
        pipe(fd2);
        pid = fork()

        if(pid == 0){
            read(fd2[0], &n2, sizeof(n2));
            close(fd2[0]);
            
            printf("Inseirsci un PID valido: ");
            pid_t pid_r; scanf("%d", pid_r);
            kill(pid_r, n2);

        }else{
            read(fd[0], &n2, sizeof(n2));
            close(fd[0]);

            write(fd2[1], &n2, sizeof(n2));
            close(fd2[1]);
        }
    }
    wait(0);
    wait(0);
    return 0;
}