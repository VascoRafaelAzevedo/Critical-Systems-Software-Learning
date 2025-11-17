#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
    puts("I discovered right now about puts!");

    int x = 100;

    int p = fork();
    if (p == -1) {
        perror("error in fork");
        exit(1);
    }else if (p > 0){
        puts("this is the parent at least I think");
        printf("[%d]\n", getpid());
        x = 11;
        printf("number: [%d]\n", x);
        wait(NULL);
        puts("Parent dies");
    }else{
        puts("this is the child yoo");
        printf("[%d]\n", getppid());
        x = 1;
        printf("number: [%d]\n", x);
        puts("Child dies");
    }





    return 0;
}