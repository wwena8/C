#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include  <string.h>

#define LEFT  30000000
#define RIGHT 30000200
#define THRUNM (RIGHT-LEFT+1)

typedef struct thread_argv{
    int n;
}thr_arg_st;

void *func(void *p)
{
    int i,mark,j;
    i = ((thr_arg_st *)p)->n;
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
    pthread_exit(p);
}
int main(int argc, char **argv)
{

    int i,err;
    pthread_t tid[THRUNM];
    thr_arg_st *p;
    void *ptr;
    for(i=LEFT;i<=RIGHT;i++)
    {
        p = malloc(sizeof(*p));
        if(p==NULL)
        {
            perror("malloc()");
            exit(1);
        }
        p->n = i;
        err = pthread_create(tid+(i-LEFT), NULL, func, p); //i一个地址被201个指针指向
        if(err)
        {
            fprintf(stdout,"pthread_create %s\n", strerror(err));
            exit(1);
        }
    }

    for(i=LEFT;i<=RIGHT;i++)
    {
        pthread_join(tid[i-LEFT], &ptr);
        free(ptr);
    }
    exit(0);
}