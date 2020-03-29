# 1 编译执行
hello.c
c源文件->预处理->编译->汇编->链接->可执行文件

预处理 #开头的都要解决：
gcc -E hello.c > hello.i

编译：
gcc -S hello.i

汇编：
gcc -c hello.s

链接：
gcc hello.o -o hello

一步走：
gcc hello.c -o h

make hello 会寻找hello.c并编译、汇编、链接、执行

# 2 vim

1 vim 按v选择行，再按=会自动对齐

2 ctrl+p自动补齐 shift+k函数 vim快捷方式

# 3 基本概念

一 写程序要求

1 gcc hello.c -Wall 所有警告都打出来 把所有警告清除掉
段错误 空指针引起

2 所有头文件都需要引入

3 以函数为单位进行编程 大功能打散成小模块 声明部分+实现部分

4 echo $?打印上一条指令的返回值 printf函数有返回值

5 多用空格、空行、添加注释 #if 0 #endif

二 算法：流程图、NS图、有限状态机FSM

三 程序：用某种编程语言实现算法

四 进程：运行中的程序、防止内存泄漏、写越界

谁打开谁关闭；谁申请谁释放；