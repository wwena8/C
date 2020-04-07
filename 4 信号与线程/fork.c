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
//        exit(1);
//        sleep(60);
    }

    if(pid > 0)
    {
        printf("%d i am parent\n", getpid());

    }

    printf("%d end\n", getpid());
    exit(0);
}