#include<stdio.h>
#include<stdlib.h>

#define STRSIZE 32
#define SEC_YEAR (60LL*60LL*24LL*365LL)

int main()
{
    int ch;
    ch = getchar(); //从标准输入、输出读写内容
    putchar(ch);
    putchar('\n');

    exit(0);    //程序结束前，刷新当前IO流
}