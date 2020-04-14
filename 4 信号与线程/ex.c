#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

/*
date +%s
*/

int main(int argc, char **argv)
{

    puts("begin");
    printf("begin\n");
//    fflush(NULL);
    execl("/bin/date", "date", "+%s", NULL);    //execl会代替父进程
    puts("end");
    exit(0);
}