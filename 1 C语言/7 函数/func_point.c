#include<stdio.h>
#include<stdlib.h>

int add (int i,int j)
{
    return i+j;
}

int main(int argc, char *argv[])    //argc 参数个数     argv字符指针数组的其实位置 参数内容    argv是个数组，数组元素是char*
{

    int (*p)(int ,int);

    p = add;
    printf("%d\n", p(3,4));
    exit(0);
}