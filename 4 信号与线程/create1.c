#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>

void * func()
{
    puts("thread is working!");
    sleep(10);
    puts("thread is working!");
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    return NULL;
}

int main(int argc, char **argv)
{
    puts("begin!");
    pthread_t tid;
    int err;

    err = pthread_create(&tid, NULL, func, NULL);
    //pthread_setcanceltype(int type, int *oldtype);
    if(err)
    {
        fprintf(stderr,"pthread_create():%s\n", strerror(err));
        exit(1);
    }
    pthread_cancel(tid);
    pthread_join(tid, NULL);
    puts("end!");

    exit(0);
}