#include<stdio.h>
#include<stdlib.h>

// TYPE NAME = VALUE

int main()
{
    int a[3] = {1,2,3};
    int *p = a; //a数组名表示数组的常量   p变量存放地址的变量
    //a++;//错误
//    p++; // p=p+1
//    p+1;
//    for(int i =0; i< sizeof(a)/sizeof(a[0]); i++) {
//        printf("%p --> %d\n", a+i, a[i]);
//        printf("%p --> %d\n", &a[i], a[i]);
//        printf("%p --> %d\n", p+i, *(p+i));
//    }
    p++;
    *p = 100;   //指针变量可以修改内容
    printf("%d\n", a[1]);


    exit(0);
}