#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// TYPE NAME = VALUE

int main()
{
    char str[] = "hello";   //串常量
    char *p = "hello";
//    str = "hello";    array type 'char [6]' is not assignable
    strcpy(str, "world");//Illegal instruction: 4
//    strcpy(p, "world");//Bus error: 10    不允许被覆盖
    p = "world";
    printf("length = %lu\n", strlen(str));
    printf("length = %lu\n", strlen("\0"));
    printf("length = %lu\n", sizeof(""));
    printf("length = %lu\n", sizeof(str));  //字符串以'\0'结尾
    puts(str);
    exit(0);
}