#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include  <string.h>

#define LEFT  30000000
#define RIGHT 30000200
#define THRUNM (RIGHT-LEFT+1)

void *func(void *p)
{
    int i,mark,j;
    i = (int) p;
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
        printf("%d is primer\n", i);
    }
    return NULL;
}
int main(int argc, char **argv)
{

    int i,err;
    pthread_t tid[THRUNM];
    for(i=LEFT;i<=RIGHT;i++)
    {
        err = pthread_create(tid+(i-LEFT), NULL, func, (void *)i); //i一个地址被201个指针指向
        if(err)
        {
            fprintf(stdout,"pthread_create %s\n", strerror(err));
            exit(1);
        }
    }

    for(i=LEFT;i<=RIGHT;i++)
    {
        pthread_join(tid[i-LEFT], NULL);
    }
    exit(0);
}