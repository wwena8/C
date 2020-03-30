#include<stdio.h>
#include<stdlib.h>

void funs()
{
    static int x = 0;
    x+=1;
    printf("%p->%d\n", &x, x);
}

void funa()
{
    int x = 0;
    x+=1;
    printf("%p->%d\n", &x, x);
}

int main()
{
    auto int i;
    int j;
    static int k;
    printf("i=%d\n", i);
    printf("j=%d\n", j);
    printf("k=%d\n", k);
    funs();
    funs();
    funs();
    funa();
    funa();
    funa();
    exit(0);
}