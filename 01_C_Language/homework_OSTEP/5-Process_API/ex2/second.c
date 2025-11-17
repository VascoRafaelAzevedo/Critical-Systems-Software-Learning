#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(void)
{

    int fd = open("data.txt", O_RDWR);

    int p = fork();
    if (p > 0) {
        puts("parent");

        char word[5];

        int size = read(fd, word, 5);
        if (size <= 0) {
            perror("error in read");
            exit(1);
        }

        char *str = "PARENTTT";
        write(fd, str,8);

        printf("read from file: %s\n", word);
    }else if (p == 0) {
        puts("child");

        char word[7];

        int size = read(fd, word,6);
        if (size <= 0) {
            perror("error in read");
            exit(1);
        }
        
        char *str2 = "CHILLLDD";
        write(fd, str2,8);

        
        word[6] = '\0';

        printf("read from file: %s\n", word);
    }


   return 0;
}
