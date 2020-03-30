#include<stdio.h>
#include<stdlib.h>

#define STRSIZE 3
int main()
{
    int i;
    float f;
    char str[STRSIZE];
    printf("please enter :\n");
    scanf("%d%f",&i,&f);    //可以用空格、回车、tab键
    printf("i = %d\n", i);
    printf("f = %f\n", f);
    scanf("%s", str);
    printf("%s\n", str);    //超出字符串长度 越界

//    while(1) {
//        scanf("%d",&i);     //放在循环很危险
//        printf("i = %d\n", i);
//    }

    exit(0);    //程序结束前，刷新当前IO流
}