#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{

    int N = atoi(argv[1]);
    pid_t pid;
    for(int n=0; n<N; n++)
    {
        pid = fork();
        if(pid == 0)
        {
            printf("n=%d,father=%d,self=%d\n", n,getppid(), getpid());
            exit(0);
        }
    }
    for(int n=0; n<N; n++)
        wait(NULL);
    exit(0);
}