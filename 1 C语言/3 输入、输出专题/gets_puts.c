#include<stdio.h>
#include<stdlib.h>

#define STRSIZE 32
#define SEC_YEAR (60LL*60LL*24LL*365LL)

int main()
{
    char str[STRSIZE];

//    gets(str);  //warning: this program uses gets(), which is unsafe.   scanf("%s")同理
    gets(str);
    puts(str);

    exit(0);    //程序结束前，刷新当前IO流
}