# 进程基本知识

1 进程标识符pid

    pid_t   有符号16位整型数   最多3万多个进程    LL类型输出
    
    命令 ps | 组合 axf
    
    进程pid依次向下使用不会回头使用旧的与fd不同
    
    getpid（）、 getppid（）
    
    
2 fork父子进程的产生   vfork（近乎弃用）

    fork:fork返回值不一样、pid不同、ppid不同、未决信号和文件锁不继承、资源利用量清0    cow 写时复制    谁改谁复制新内容
        
            fork之前只有父进程执行，fork之后父子进程都会运行    
        
            fork重定向后berin会执行两次，终端一次 fork之前需要刷新流fflush(NULL);     终端默认行缓冲模式、文件默认全缓冲模式
        
            fflush的重要性：
            
            控设备 /dev/null
        
        init进程 1号进程 所有进程的祖先进程
    
    调度器的调度策略来决定哪个进程先运行
    
    vfork：
   
3 进程的消亡与释放资源

    僵尸进程：父进程暂停，子进程执行完毕不能回收资源
        
    孤儿进程：父进程死亡，子进程的父进程变为init进程
    
    wait()  man 2   回收所有子进程资源   收尸函数        终端命令行会阻断输出
    waitpid()       回收特定子进程的资源
    waitid()
    wait3()
    
    进程上限    
    
        分块法一个进程负责一部分

        交叉分配：依然分配不均匀
        
        进程池思想
        
        for循环创建进程，最后进程总数是2^N次方
        
4 exec函数族

    fork    每个进程执行的任务一样 执行的任务是规定好的  shell可以创建非shell子进程
    
    execl
    execle
    execlp
    execv
    execp

    shell命令:    内部命令、外部命令
    
5 用户权限与组权限

    r e s
    u+s
    g+s
    getuid() geteuid() getgid() getegid()

6 观摩课程：解释器文件

7 system()

    few

8 进程会计

9 进程时间  times()

10 守护进程(精灵进程)   

    mydaemon.c

11 系统日志 syslog

    /var/log/
    
    openlog closelog syslog
    
******************************************************************************

# 并发

同步

异步  事件的处理方法：查询法(发生稠密)、通知法(发生稀疏) 捕鱼

## 一 信号

    1 信号的概念     信号！=中断
    
        信号就是软中断（初步异步）
        信号的响应依赖于中断
    
    2 signal
    
        kill -l 1~31标准信号    其余实时信号  ulimit -a
        
        ctrl+c SIGINT
        
        信号会打断阻塞的系统调用 star.c
    
    3 信号的不可靠
    
        信号行为不可靠
    
    4 可重入函数
    
        所有的系统调用都是可重入的，一部分库函数也是可重入的 memcpy
    
    5 信号的响应过程
    
        信号从收到到响应有一个不可避免的延迟  中断是进入内核的唯一途径
        
        如何忽略掉一个信号？SIG_IGN
        
        标准信号为何丢失？位图mask与pending 10-->11-->00-->01   mask为0的时候就会丢掉信号
        
        标准信号的响应没有严格的顺序
    
    6 相关常用函数
    
        kill    raise   pause   sleep
        
        alarm   定时器 无法实现多任务定时
        
        pause   等待信号来打断自己   sleep -> alarm+pause
        
    7 信号集
    
    8 信号屏蔽字的处理/pending集的处理
    
    9 sig*
    
    10 实时信号，前面都是标准信号

## 二 线程

ps -T -p pid
ps ax -L

posix标准

    1 线程的概念
    
        一个正在运行的函数   main作为进程唯一的入库与出口    main线程
        
        多个线程公用相同地址空间
    
    2 线程的创建、终止、取消、栈清理
    
        pthread_t   pthread_self
        
        创建 pthread_create() 线程调度取决于调度器策略
        
        线程终止3种方式：
        
            1）线程从启动例程中返回，返回值是线程的退出码
            
            2）线程可以被同一进程中的其他线程取消
            
            3）pthread_exit
        
        pthread_join相当于进程中的wait
        
        栈清理：pthread_cleanup_push();
        
               pthread_cleanup_pop();   需要成对出现
    
        线程的取消选项
        
            pthread_cancel  先取消后收尸  不需要让主线程盲等
            
            允许取消包括：异步取消、推迟cancel（默认推迟至cancel点再响应）   posix定义的cancel点都可以引发阻塞的系统调用
            
            pthread_setcancelstate（）设置是否允许被取消
            
            pthread_setcanceltype 设置取消方式
            
            pthread_detach() 线程分离
    
    3 线程同步
    
        多线程计算质数：primer0.c primer0_e.c
        
        线程竞争
        
        互斥量：希望有顺序拿数据而不是蜂拥而至 谁抢到谁执行
        
            pthread_mutex_t
            pthread_mutex_init()
            pthread_mutex_destroy()
            pthread_mutex_lock()
            pthread_mutex_trylock()
            pthread_mutex_unlock()
            
        临界区：只要跳转想去临界区外一定是先解锁后跳转
        
        条件变量：
            pthread_cond_t
            pthread_cond_init
            pthread_cond_destroy
            pthread_cond_broadcast  广播线程
            pthread_cond_signal  广播线程
    
    4 线程属性、线程同步的属性
    
    5 线程可重入、线程与信号、线程与fork