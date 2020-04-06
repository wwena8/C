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

int ftype(const char *fname)
{
    struct stat statress;
    if (stat(fname, &statress) < 0)
    {
        perror("stat()");
        exit(1);
    }
    if(S_ISREG(statress.st_mode))
        return '-';
    if(S_ISDIR(statress.st_mode))
        return 'd';
}

int main(int argc, char **argv)
{
    if(argc <2)
    {
        fprintf(stderr,"Usage:%s <src_file> <dest_file>\n", argv[0]);
        exit(1);
    }
    printf("%c\n", ftype(argv[1]));
    exit(0);
}