#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{

    pid_t pid;
    int i =10;
    printf("%d begin\n", getpid());

    fflush(NULL);

    pid = fork();

    if(pid < 0) {
        perror("fork()");
        exit(1);
    }

    if(pid == 0)
    {
        printf("%d i am child\n", getpid());
        i = 1000;
        printf("i=%d i am child\n", i);
    }

    if(pid > 0)
    {
        printf("%d i am parent\n", getpid());
        i=100;
        printf("i=%d i am parent\n", i);

    }

    printf("%d end\n", getpid());
    exit(0);
}