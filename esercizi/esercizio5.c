#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <time.h>


int main(){
    int fd[2];
    pipe(fd);

    pid_t pid = fork();

    if(pid == 0){
        srand(time(NULL));
        close(fd[0]);
        int r = random() % 101;
        
        write(fd[1], &r, sizeof(r));
        printf("Figlio manda numero random: %d\n", r);

        close(fd[1]);
    }else{
        int fd2[2];
        pipe(fd2);
        pid = fork();

        if(pid == 0){
            close(fd[0]);
            close(fd[1]);
            close(fd2[1]);

            int ran;

            read(fd2[0],&ran,sizeof(ran));
            printf("IL secondo figlio ha ricevuto: %d\n", ran);

            close(fd2[0]);
        }else{
            close(fd[1]);
            close(fd2[0]);

            int ra;
            read(fd[0],&ra,sizeof(ra));
            close(fd[0]);

            printf("Il numero random ricevuto dal padre è: %d\n", ra);

            write(fd2[1],&ra, sizeof(ra));
            close(fd2[1]);
            
            wait(0);
            wait(0);

        }
    }
    return 0;
}