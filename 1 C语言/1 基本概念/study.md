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

# 3 
