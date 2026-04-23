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
        close(fd[1]);
        int ra;
        read(fd[0],&ra,sizeof(ra));
        printf("Il numero random è: %d\n", ra);
        close(fd[0]);
        wait(0);
    }
    return 0;
}