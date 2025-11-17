#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
int main(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);

    printf("TIME: %ld.%06ld\n", tv.tv_sec, tv.tv_usec);
    gettimeofday(&tv, NULL);
    printf("TIME: %ld.%06ld\n", tv.tv_sec, tv.tv_usec);
    gettimeofday(&tv, NULL);
    printf("TIME: %ld.%06ld\n", tv.tv_sec, tv.tv_usec);
    gettimeofday(&tv, NULL);
    printf("TIME: %ld.%06ld\n", tv.tv_sec, tv.tv_usec);
    gettimeofday(&tv, NULL);
    printf("TIME: %ld.%06ld\n", tv.tv_sec, tv.tv_usec);
    gettimeofday(&tv, NULL);
    printf("TIME: %ld.%06ld\n", tv.tv_sec, tv.tv_usec);
    

    return 0;
}