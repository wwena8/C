#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main()
{
    FILE *fp;

    fp = fopen("tep", "a"); //创建形式追加
    if(fp == NULL)
    {
        fprintf(stderr, "fopen() failed! errno=%d\n", errno);
        perror("fopen()");  // perror
        puts(strerror(errno));  // strerror
        exit(1);
    }
    puts("OK!");
    exit(0);
}