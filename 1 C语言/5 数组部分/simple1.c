#include<stdio.h>
#include<stdlib.h>

#define M 3
#define SEC_YEAR (60LL*60LL*24LL*365LL)

/*
冒泡排序
*/
static void sort1(void)
{

}

int main()
{
//    int arr[M];
    int arr[M] = {1,2,3};
    for(int i=0;i<M;i++) {
        printf("%p --> %d\n", &arr[i], arr[i]);
    }
    printf("%lu\n", sizeof(arr));
    printf("%lu\n", sizeof(arr)/sizeof(arr[0]));
    exit(0);    //程序结束前，刷新当前IO流
}