# IO

一切实现的基础

man手册 2 系统函数 3 标准函数 7

1 标准IO  stdio   printf  优先使用：移植性好，合并系统调用，读写加速

    FILE类型贯穿始终
    
    errno-base.h
    
    fopen() fclose()/   fopen() mode r、a、w 追加与覆盖~~~~
    
    fgetc() fputc()/    一个一个字符读入
    
    fgets() fputs()/    设置一个缓冲区，缓冲区满再操作 fgets(buf, BUFFER_SIZE, fps);
    
    fread() fwrite()/ fread(buf, 1, BUFFER_SIZE, fps)
    
    printf() scanf()/   fprintf()重定向
    
    fseek() ftell() 
    
    rewind() fflush()
    
    getline()
    
    char *p="abc"; *p[0]='x'; "xbc"?
    
    临时文件：tmpnam、tmpfile

2 系统调用IO    sysio 穿透内核 栈、静态区、堆  E S c o

    1)文件描述符 fd贯穿始终的类型 整型数的数组下标  
    
        1024个 stdin 0 stdout 1 stderr 2 优先使用当前可用范围内最小的
        
        一个进程一个独立的进程描述符数组
        
        文件引用计数器
        
        r -> O_RDONLY       位图
        r+ -> O_RDWR 
        w -> O_WRONLY|O_CREAT|O_TRUNC
        w+ -> O_RDWR|O_CREAT|O_TRUNC
    
    2）文件IO操作：open、close、read、write、lseek
    
    3）标准io与文件io的区别
    
        标准io加缓冲区    响应速度（文件IO）与吞吐量 （标准IO）   如何使一个程序变快？
        
        不可混用    fileno 文件指针->文件描述符 fdopen   两个pos不一致    ab.c    
        
        strace跟踪系统调用
    
    4）IO效率
    
        time real    0m0.004s real = user+sys+调度时间
             user    0m0.001s
             sys     0m0.002s
    
    5）文件共享
    
        删除文件第10行
    
    6）原子操作
    
    7）程序重定向：dup dup2
    
    8）同步：sync、fsync、fdatasync、
    fcntl、 ioctl    /dev/fd：目录