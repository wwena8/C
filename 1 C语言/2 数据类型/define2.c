#include<stdio.h>
#include<stdlib.h>
#define PI 3.14159
#define ADD 2+3
#define MAX(a,b) (a>b ? a:b)

void main()
{
    printf("a=%d\n", ADD*ADD);
//    int i=3, j=4;
    printf("a=%d\n", MAX(3,4));
    exit(0);
}