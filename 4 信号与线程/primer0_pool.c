#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include  <string.h>

#define LEFT  30000000
#define RIGHT 30000205
#define THRUNM 2

static int num=0;
static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void *func(void *p)
{
    int i,mark,j;
    int number = (int) p;
    while(1)
    {
        pthread_mutex_lock(&mut);
        while(num == 0)
        {
            pthread_mutex_unlock(&mut);
            sched_yield();  //超级短的sleep
            pthread_mutex_lock(&mut);
        }
        if(num == -1)
        {
            pthread_mutex_unlock(&mut);
            break;
        }

        i = num;
        num = 0;
        pthread_mutex_unlock(&mut);
        mark =1;
        for(j=2; j<i/2;j++)
        {
            if(i%j == 0)
            {
                mark =0;
                break;
            }
        }
        if(mark) {
            printf("%d号线程计算出来：%d is primer\n", number,i);
        }
    }

    pthread_exit(NULL);
}
int main(int argc, char **argv)
{

    int i,err;
    pthread_t tid[THRUNM];
    for(i=0;i<THRUNM;i++)
    {
        err = pthread_create(tid+i, NULL, func, (void *)i); //i一个地址被201个指针指向
        if(err)
        {
            fprintf(stdout,"pthread_create %s\n", strerror(err));
            exit(1);
        }
    }

    for(i=LEFT;i<=RIGHT;i++)
    {
        pthread_mutex_lock(&mut);
        while(num != 0)
        {
            pthread_mutex_unlock(&mut);
            sched_yield();  //超级短的sleep
            pthread_mutex_lock(&mut);
        }
        num = i;
        pthread_mutex_unlock(&mut);
    }
    sched_yield();
    pthread_mutex_lock(&mut);
    num = -1;
    pthread_mutex_unlock(&mut);
    for(i=0;i<THRUNM;i++)
    {
        pthread_join(tid[i], NULL);
    }
    pthread_mutex_destroy(&mut);
    exit(0);
}