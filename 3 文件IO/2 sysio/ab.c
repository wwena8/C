#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
int main(int argc, char **argv)
{
    putchar('a');//标准io
    write(1, "b", 4);//文件io
    putchar('a');
    write(1, "b", 4);
    putchar('a');
    write(1, "b", 4);
    write(2, "b", 4);
    write(0, "b", 4);
    putchar('\n');
    exit(0);
}