# 六 指针

1 变量与地址

    1）变量名是用户对某块内存空间的抽象表示
    
    2）指针不等于地址   指针是一种特殊的数据类型    地址是内存字节编号   指针变量保存地址

2 指针与指针变量

    1）指针是常量不变   指针变量可以改变指向的指针位置

3 直接访问与间接访问

    1）inti=1; int *p=&i; int **q=&p; i=*p=**q   4：30
    
    i=? &i=? p=? &p=? *p=?      &p与*p   指针变量的地址与指针变量指向地址的值  
    
    i直接访问   p一级间接访问     指针类型变量所占字节数长度取决于机器字长    做运算能力取决于数据类型    *与&可以同时抵消

4 空指针与野指针

    1) int *p = NULL;  //空指针        int *q;     //野指针
    
    2）void* 是一个万金油

5 空类型指针

6 指针定义与初始化书写规则

7 指针运算

    & * 关系运算(指向连续的同一块内存空间) ++ --

8 指针与数组关系

    1）指针与一维数组
    
    2）指针与二维数组
    
    3）指针与字符数组
    
        charr.c
    
9 const与指针  const.c

    cost int a  变量保存常量值容易被修改掉
    
    const后面的内容当做一个整体来看，是不能发生改变的 从变量往前数 先const念常量   先*念指针    
    
    函数封装有用

10 指针数组与数组指针

    数组指针：【存储类型】 数据类型 （*指针名） 【下标】 = 值
    
    数组指针    int (*p) [3]     指针指向二维数组首地址  int[3] *p;
      
    指针数组    int *p[3]        数组里面元素是指针

11 多级指针