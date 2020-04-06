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

void f1(void)
{
    puts("f1() is working");
}

void f2(void)
{
    puts("f2() is working");
}

void f3(void)
{
    puts("f3() is working");
}

int main(int argc, char **argv)
{

    puts("begin");
    atexit(f1);
    atexit(f2);
    atexit(f3);

    puts("end");
//    exit(0);
//    _exit(0);
    _Exit(0);
}