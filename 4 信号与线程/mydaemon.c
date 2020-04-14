#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE_NAME "/tmp/out"

int daemonize()
{
    pid_t pid;

    int fd;

    pid = fork();

    if(pid < 0)
    {
       perror("fork()");
       return -1;
    }

    if(pid>0)
    {
        exit(0);
    }

    fd = open("/dev/null", O_RDWR);
    if(fd<0)
    {
        perror("open()");
        return -1;
    }
    dup2(fd, 0);
    dup2(fd, 1);
    dup2(fd, 2);
    if(fd>2)
        close(fd);
    setsid();
    chdir("/");
    umask(0);
    return 0;
}

int main(int argc, char **argv)
{

    if (daemonize()){
        exit(1);
    }
    FILE *fp;
    fp = fopen(FILE_NAME, "w");

    if(fp==NULL)
    {
        perror("fopen()");
        exit(1);
    }

    for(int i=0;;i++)
    {
        fprintf(fp, "%d\n", i);
        fflush(fp);
        sleep(1);
    }

    exit(0);
}