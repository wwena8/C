# 1 数据类型

1 所占字节数

2 存储区别

3 不同数据类型之间的转换

4 特殊性：

布尔型 stdbool.h；

float类型不一定准确；

char型不一定有符号；

不同形式的0：'0',"0",0,'\0'

数据类型前后输入输出要保持一致
    
# 2 常量与变量

1 常量：程序执行过程不会变化的量 

分类：整型、实型、字符、字符串、标识  

字符常量：由单引号引起来的单个字符和转义字符、转义字符：空格符、制表符等

字符串常量：由双引号引起来的一个或多个字符组成的序列

标识常量：#define 只做宏体不检查语法 define2.c 宏体需要加括号
    
2 变量：程序执行过程随时会变化的量，用来保存一些特定内容  

定义：[存储类型] 数据类型 标识符  = 值 TYPE NAME = VALUE

存储类型：auto、static、register、extern
    auto：默认 自动分配，自动回收 栈 随机值
    register：寄存器型类型 register int i=0 建议编译器将i的存储空间放到寄存器
    只能定义局部变量，大小有限制；寄存器无地址所以变量无法打印地址查看或使用；
    static：静态型，自动初始化0值或空值，且变量值有继承性 只用一块空间 funs 常用来修饰变量或者函数
    extern：说明型，不能改变被说明的变量的类型
    
变量的生命周期与作用范围：
    1）全局变量：
    
# 3 运算符与表达式

1 表达式与语句的区别

运算符：

    1）每个运算符需要操作数的个数
    
    2）结合性、优先级
    
    3）运算符的特殊用法
        逻辑运算可以短路
    4）位运算的重要意义 luoji.c