#include<stdio.h>
#include<stdlib.h>
#include <signal.h>
#include <unistd.h>

void int_handler()
{
    write(1,"!",1);
}

int main(int argc, char **argv)
{

    int i;
    signal(SIGINT,SIG_IGN);   //可以忽略2号信号对进程的中断
//    signal(SIGINT,int_handler); //程序未结束且信号过来了就中断执行该函数    void (*signal(int sig, void (*func)(int)))(int);
    for(i=0;i<1000;i++)
    {
        write(1,"*",1);
        sleep(1);
    }
    putchar('\n');
    exit(0);
}