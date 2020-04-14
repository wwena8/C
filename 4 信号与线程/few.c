#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pid_t pid;
    puts("begin");

    fflush(NULL);
    pid = fork();

    if(pid < 0) {
        perror("fork()");
        exit(1);
    }

    if(pid == 0)
    {
        execl("/bin/date", "date", "+%s", NULL);    //execl会代替父进程
        perror("execl()");
        exit(1);
    }

    wait(NULL);
    puts("end");
    exit(0);
}