#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include  <string.h>

static pthread_mutex_t mut[4];

int next(int n)
{
    if(n+1 == 4)
        return 0;
    return n+1;
}

void *func(void *p)
{
    int i = (int) p;
    while(1){
        pthread_mutex_lock(mut+i);  //锁自己接下一个人的锁
        switch (i)
            {
                case 0:
                    putchar('a');
                    break;
                case 1:
                    putchar('b');
                    break;
                case 2:
                    putchar('c');
                    break;
                case 3:
                    putchar('d');
                    break;
                default:
                    break;
            }
        pthread_mutex_unlock(mut+next(i));
    }
    putchar('\n');

    pthread_exit(NULL);
}
int main(int argc, char **argv)
{

    int i,err;

    int num = 4;
    pthread_t tid[num];

    for(i=0;i<num;i++)
    {
        pthread_mutex_init(mut+i, NULL);
        pthread_mutex_lock(mut+i);
        err = pthread_create(tid+i, NULL, func, (void *)i); //i一个地址被201个指针指向
        if(err)
        {
            fprintf(stdout,"pthread_create %s\n", strerror(err));
            exit(1);
        }
    }
    alarm(2);   //定时杀死进程
    pthread_mutex_unlock(mut);
    for(i=0;i<num;i++)
    {
        pthread_join(tid[i], NULL);
    }
    pthread_mutex_destroy(&mut);

    exit(0);
}