#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])    //argc 参数个数     argv字符指针数组的其实位置 参数内容    argv是个数组，数组元素是char*
{
    printf("argc = %d\n", argc);    //shell可以解释通配符
    for(int i=0;i<argc;) {
        puts(argv[i++]);
    }
    int i=0;
    while(argv[i] != NULL) {
            puts(argv[i++]);
    }

    exit(0);
}