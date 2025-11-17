#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {

  int p = fork();
  if (p > 0) {
    puts("parent");
    usleep(1);
    puts("goodbey");
    wait(NULL);
  } else if (p == 0) {
    puts("CHILD");
    puts("hello");
  }

  return 0;
}
