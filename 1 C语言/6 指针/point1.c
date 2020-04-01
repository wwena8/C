#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p = NULL;  //空指针 NULL 0号地址
    int *q;     //野指针 指向空间不确定

    printf("%p\n", p);
    printf("%p\n", ++p);
    printf("%d\n", *p);
    printf("%d\n", *q);


    exit(0);
}