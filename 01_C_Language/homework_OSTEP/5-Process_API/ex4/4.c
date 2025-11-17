#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {

  int p = fork();
  if (p > 0) {
    puts("parent");
    wait(NULL);
    puts("goodbey");
  } else if (p == 0) {
    puts("CHILD");
    char *arg[] = {"ls", NULL};
    execvp(arg[0], arg);
  }

  puts("NEXT");
  //nao vai fazer nada porque nao procura no $PATH ou seja nao vai encontrar ls1
  p = fork();
  if (p > 0) {
    puts("parent");
    wait(NULL);
    puts("goodbey");
  } else if (p == 0) {
    puts("CHILD");
    char *arg[] = {"ls", NULL};
    execv(arg[0], arg);
  }

  p = fork();
  if (p > 0) {
    puts("parent");
    wait(NULL);
    puts("goodbey");
  } else if (p == 0) {
    puts("CHILD");
    char *arg[] = {"ls", NULL};
    execvp(arg[0], arg);
  }

  p = fork();
  if (p > 0) {
    puts("parent");
    wait(NULL);
    puts("goodbey");
  } else if (p == 0) {
    puts("CHILD");
    char *arg[] = {"ls", NULL};
    execvp(arg[0], arg);
  }

  p = fork();
  if (p > 0) {
    puts("parent");
    wait(NULL);
    puts("goodbey");
  } else if (p == 0) {
    puts("CHILD");
    char *arg[] = {"ls", NULL};
    execvp(arg[0], arg);
  }

  return 0;
}
