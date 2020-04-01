#include<stdio.h>
#include<stdlib.h>

void swap(int i, int j)//swap中的两个形参，需要从swap中伸手处理main中的值
{
    int tmp;
    tmp = i;
    i = j;
    j = tmp;
}

void swap2(int *i, int *j)//swap2交换指针指向的值
{
    int tmp;
    tmp = *i;
    *i = *j;
    *j = tmp;
}

int main()
{

    int i=3, j=5;   //main函数地址
    swap(i,j);
    printf("%d %d\n", i, j);
    swap2(&i,&j);
    printf("%d %d\n", i, j);
    exit(0);
}