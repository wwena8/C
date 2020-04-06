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


int main(int argc, char **argv)
{
    char *str;

    if(argc <2)
    {
        fprintf(stderr,"Usage:%s <src_file> <dest_file>\n", argv[0]);
        exit(1);
    }
    str = getenv(argv[1]);//PATH
    puts(str);
    exit(0);
}