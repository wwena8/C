#include<stdio.h>
#include<stdlib.h>

void print_array(int *p, int n);
int main(int argc, char *argv[])    //argc 参数个数     argv字符指针数组的其实位置 参数内容    argv是个数组，数组元素是char*
{
    printf("argc = %d\n", argc);    //shell可以解释通配符

    int i=0;
    while(argv[i] != NULL) {
            puts(argv[i++]);
    }
    int a[] = {1,2,2,3,4,5};
    print_array(a, 6);
    exit(0);
}

void print_array(int *p, int n)     // int p[]定义是数组，形参是指针
{
    int i = 0;
    while(i<n) {
        printf("%d ",*(p+i));
        i++;
    }
    putchar('\n');
}