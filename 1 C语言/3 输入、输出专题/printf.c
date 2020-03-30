#include<stdio.h>
#include<stdlib.h>

#define STRSIZE 32
#define SEC_YEAR (60LL*60LL*24LL*365LL)

int main()
{
    char ch = 65;

    printf("ch = %d\n", ch);
    printf("ch = %c\n", ch);
//    printf("ch = %s\n", ch);  //Segmentation fault: 11

    int i =123;
    printf("i = %14d\n", i); //修饰符
    printf("i = %x\n", i); //16进制
    printf("i = %o\n", i); //8进制

    float f = 123.456782678267826782;
    printf("i = %d %e\n", i, f); //科学技术
    printf("f = %24.18f\n", f); //浮点型处理器 m.n 宽度与有效字符
    char str[STRSIZE] = "hello world";
    printf("%.5s\n", str);

    printf("[%s:%d]before while().",__FUNCTION__,__LINE__); //缓冲区 函数名 行号
//    while(1);
    printf("[%s:%d]after while().",__FUNCTION__,__LINE__);
    exit(0);    //程序结束前，刷新当前IO流
}