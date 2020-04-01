#include<stdio.h>
#include<stdlib.h>

// TYPE NAME = VALUE

int main()
{
    int a[2][3] = {5,1,7,2,8,3};    //a是第0行的首地址 a+1是第1行首地址
    for(int i=0;i<2;i++) {
       for(int j=0;j<3;j++) {
                   printf("%d ",a[i][j]);//a[i][j] == *(*(a+i)+j)
       }
       putchar('\n');
    }
    int *p;
    p=a;    //p和a的本质不同
    p=&a[0][0];
    for(int i=0;i<sizeof(a)/sizeof(a[0][0]);i++,p++){
        printf("%d ", *p);
    }
    putchar('\n');
    int (*q) [3] = a;   // q与a保持一致
    exit(0);
}