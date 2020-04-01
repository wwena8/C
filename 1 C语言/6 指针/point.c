#include<stdio.h>
#include<stdlib.h>

// TYPE NAME = VALUE
int main()
{
    int i = 129;
    int *p = &i;

    printf("%d\n", i);
    printf("&i = %p\n", &i);
    printf("p = %p\n", p);
    printf("&p = %p\n", &p);
    printf("*p = %d\n", *p);
    printf("sizeof(p) = %lu\n", sizeof(p)); //指针类型长度取决于机器字长
    printf("sizeof(i) = %lu\n", sizeof(i));
    char *c = &i;
    printf("*c = %d\n", *c);//取指能力
    int *q = 0x7ffee1d06ae8;
    printf("q = %p\n", q);
    printf("*q = %d\n", *q);    //Segmentation fault: 11
    exit(0);
}