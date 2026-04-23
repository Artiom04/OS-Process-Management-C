#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main(){
    int status;
    int fd[2];
    pipe(fd);
    
    pid_t pid = fork();
    if(pid == 0){
        char buffer[1024];
        read(fd[0],&buffer, sizeof(buffer));
        printf("%s\n", buffer);
        close(fd[0]);

        execlp("mv","mv" ,"esempio.c", buffer, NULL);
        
    }else{
        write(fd[1], "esempio2.c", 11);
        close(fd[1]);
    }
    wait(&status);
    return 0;
}