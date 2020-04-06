#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define GB (1024LL*1024LL*1024LL)
int main(int argc, char **argv)
{
    if(argc <2)
    {
        fprintf(stderr,"Usage:%s <src_file> <dest_file>\n", argv[0]);
        exit(1);
    }
    int fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0600);
    if(fd < 0)
    {
        perror("open()");
        exit(1);
    }
    lseek(fd, GB*5LL-1LL, SEEK_SET);
    write(fd,"",1);
    close(fd);

    exit(0);
}