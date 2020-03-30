#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i;
    float f;
    printf("please enter :\n");
    scanf("%d%f",&i,&f);    //可以用空格、回车、tab键
    printf("i = %d\n", i);
    printf("f = %f\n", f);
    exit(0);    //程序结束前，刷新当前IO流
}