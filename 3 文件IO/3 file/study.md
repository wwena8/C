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
    
    8）utime
    
    9）目录的创建于销毁
    
    10）更改当前工作路径
    
    11）分析目录

2 系统数据文件和信息

3 进程环境