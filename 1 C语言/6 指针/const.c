#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PI 3.14
int main()
{
    /*
        const int a;    常量
        int const a;

        const int *p;   常量指针   p可以变(*p)不能变常量不能出现在等号左边 从变量往前数先const念常量   先*念指针
        int const *p;

        int *const p;   指针常量    p不可以变 *p可以变化
        const int *const p; 既是指针常量又是常量指针    const后面的内容当做一个整体来看，是不能发生改变的
    */
    const float pi = 3.142;
//    pi = 3.141;   //直接报错
//    float *p = &pi;
//    *p = 3.14156;   //仍然不能修改
//    printf("%.61f\n", pi);

    int i=0;
    int j=10;
//    int k=10;
    const int *p1 = &i;
    int *const p2 = &j;
    const int *const p3 = &j;

//    *p1 = 10;
    (*p2)=1000;
    p3++; *p3=100;  //都是无效的
    printf("%d\n", *p1);
    printf("%d\n", *p2);
    printf("%d\n", *p3);
    exit(0);
}