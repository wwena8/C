#include<stdio.h>
#include<stdlib.h>

#define M 2
#define N 3
#define SEC_YEAR (60LL*60LL*24LL*365LL)

int main()
{
    int arr[M][N] = {{1,2,3},{4,5,6}};
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            printf("%d ", arr[i][j]);
        }
        putchar('\n');
    }
    printf("%lu\n", sizeof(arr));
    printf("%lu\n", sizeof(arr)/sizeof(arr[0][0]));
    exit(0);    //程序结束前，刷新当前IO流
}