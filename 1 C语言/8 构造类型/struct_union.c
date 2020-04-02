#include<stdio.h>
#include<stdlib.h>

struct student
{
    int a;
    float f;
    char c;
    char c2;
};//__attribute__((packed));

union test_un
{
    int i;
    double d;
    float f;
    char c;
};

typedef union test_un1  //重命名
{
    int i;
    double d;
    float f;
    char c;
}tu;

enum day
{
    MON,
    TUS,
    THR
};

int main(int argc, char *argv[])    //argc 参数个数     argv字符指针数组的其实位置 参数内容    argv是个数组，数组元素是char*
{

    struct student s;
    struct student *p;
    p=&s;

    printf("%lu\n", sizeof(s)); //字节对齐  4个4个分配 方便编译器取指
    printf("%lu\n", sizeof(p)); //64位系统

    union test_un u;
    tu u1;
    printf("%lu\n", sizeof(u)); //64位系统
    printf("%lu\n", sizeof(u1)); //64位系统
    enum day a = TUS;
    printf("%d\n", a);
    exit(0);
}