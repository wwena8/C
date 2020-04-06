# 文件系统

类似于ls的实现

    ls -a~z -A~Z 0~9    touch -a -> touch -- -a

1 目录和文件

    1）如何获取文件属性
        
        stat    flen.c  
        
        空洞文件 big.c          cp /tmp/bigfile  /tmp/bigfile.bck
    
    2) 文件访问权限
    
        ls -l   文件类型 user权限 同组权限 其他组的权限 
        
        文件类型有7种 
            d：目录    c：字符设备      b：块设备   -：常规文件      l：符号（软）链接文件
            s: 套接字      p：管道文件
            
        st_mode是一个16位的位图，用于表示文件类型、文件访问权限、特殊权限位
    
    3）umask 防止产生权限过松的文件 0666 & ~umask
        
    4）文件权限
    
        chmod/fchmod    chmod a+x big.c     chmod()
    
    5）粘着位
    
        t位
    
    6）文件系统：FAT、UFS  （ext2，ext3）
    
        文件或数据的存储格式问题
        
            FAT 16/32 静态存储的单链表  windows int size[n] char data[n][size]  依赖于n
            
            windows硬盘分区？FAT承载能力有限   
            
            内存吃紧：换入率和换出率双高  清理工具都是垃圾
            
            内存碎片、磁盘碎片       整理的都是映射关系
            
            UFS：分区-->柱面组-->块组   1*12*1K+1*256*1k+1*256*256*1K。。。。   位图思想
    
    7）目录：硬链接、符号链接
    
        目录项：
            
            硬链接:ln 两个指针指向同一块空间 inode不同  不能给分区与目录建立硬链接         
            
            符号链接:快捷方式   inode不同 可以跨分区、可以给目录建立
           
        link函数、unlink、remove、rename
        
    8）utime
    
        可更改文件最后读写时间
    
    9）目录的创建于销毁
    
        mkdir rmdir
    
    10）更改当前工作路径
    
        cd chdir
    
    11）分析目录
    
        递归思想：
        
        glob
        opendir()
    
    实现一个目录解析

2 系统数据文件和信息 username.c

    1）/etc/passwd   getpwuid getpwnam
    
    2）/etc/group    ls -n
    
    3）/etc/shadow
    
    4）时间戳   time gmtime localtime mktime strftime

3 进程环境

    1) main函数
    
        main(int argc, char **argv)
    
    2) 进程的终止情况
        
        正常终止    
        
            从main返回、
            
            exit、_exit或_Exit、   -128~127        _exit不执行钩子函数与io清零
            
            最后一个线程从其启动例程返回
            
            最后一个线程调用了pthread_exit
        
        异常终止
        
            调用abort函数 
            
            接到一个信号并终止
            
            最后一个线程对其取消请求并作出响应 
            
        atexit（）：钩子函数       atexit.c    一个进程挂32个函数，逆序执行
    
    3）命令行参数分析
    
        getopt()
        
        getopt_long()
    
    4）环境变量
    
        export  getenv
    
    5）C程序的存储空间布局
    
        pmap pid
    
    6）库
    
        动态库
        
        静态库
        
        手工装载库
    
    7）函数跳转
    
        setjmp
    
    8）资源的获取与控制