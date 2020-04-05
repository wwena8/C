#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main()
{
    char str[] = "123456";

    fprintf(stderr, "%d\n", atoi(str));

    exit(0);
}