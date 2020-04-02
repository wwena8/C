#include<stdio.h>
#include<stdlib.h>

void func1(int *p, int n)
{
    p = malloc(n);
    if(p == NULL) {
        exit;
    }
    return ;
}

void func2(int **p, int n)
{
    *p = malloc(n);
    if(*p == NULL) {
        exit;
    }
    return ;
}

void *func3(int **p, int n)
      {
          *p = malloc(n);
          if(*p == NULL) {
              exit;
          }
          return p;
      }

int main(int argc, char *argv[])    //argc 参数个数     argv字符指针数组的其实位置 参数内容    argv是个数组，数组元素是char*
{

    int *p = NULL;
    p = malloc(sizeof(int));    //void * 百搭的类型

    if(p == NULL) {
        puts("malloc error\n");
    }
    int *q = NULL;
    int n = 100;
    int n1 = 1001;
    func1(q,n);
    free(q);    //内存已经泄露，因为拿不到内存块首地址

    func2(&q, n);   //可以回收内存
    free(q);

    q= func3(q, n);
    free(q);

    int *r =NULL;
    r = malloc(sizeof(int));
    *r =10;
    printf("%p --> %d\n", r, *r);
    free(r);    //r对内存空间再也没有引用权限
//    r = NULL;   //free与pointer==NULL必须成对出现
    *r = 100;   //不加r=NULL r就是野指针
    printf("%p --> %d\n", r, *r);
    exit(0);
}