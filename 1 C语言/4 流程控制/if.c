#include<stdio.h>
#include<stdlib.h>

#define STRSIZE 32
#define SEC_YEAR (60LL*60LL*24LL*365LL)

int main()
{
    int i =0;
    int sum=0;
loop:
    if (i <= 100) {
        sum+=i;
        i++;
        goto loop;
    }
    printf("sum = %d\n", sum);
    exit(0);    //程序结束前，刷新当前IO流
}