# 8 构造类型

1 结构体

    1 产生的意义 成员共存
    
    2 类型描述
    
    3 嵌套定义
    
    4 定义变量（变量、数组、指针） 初始化以及成员引用
    
        struct student s;        struct student *p = &s;
    
    5 占用内存空间    字节对齐情况
    
2 共用体

    1 产生以及意义
    
        同时多个成员，实际某时刻成员只能生效一个
    
    2 类型描述
    
    3 嵌套定义使用
    
    4 定义变量，初始化与成员引用
        变量名.成员名  指针->成员名
    
    5 占用内存大小
    
    6 位域
    
3 枚举

    1 enum 标识符