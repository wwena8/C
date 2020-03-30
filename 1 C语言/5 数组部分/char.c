#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define M 40
#define N 3
#define SEC_YEAR (60LL*60LL*24LL*365LL)

int main()
{
//    char arr[M] = {'a'};
    char arr[M] = "abcdede";
    for(int i=0;i<M;i++) {
        printf("%c ", arr[i]);
    }
    char arr2[] = "abcdede";
    printf("\n");
    printf("%lu\n", sizeof(arr));
    printf("%lu\n", sizeof(arr)/sizeof(arr[0]));
    printf("%lu\n", strlen(arr));
    printf("%lu\n", strlen(arr2));
    printf("%lu\n", sizeof(arr2));
    strcpy(arr, "12");
    strcat(arr, arr2);
    strcmp(arr, arr2);
    puts(arr);
    exit(0);    //程序结束前，刷新当前IO流
}