#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include  <string.h>

#define FNAME "/tmp/out"
#define LINESIZE 1024

static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void *func(void *p)
{
    FILE *fp;
    char linebuf[LINESIZE];
    int i = (int) p;
    fp = fopen(FNAME, "r+");
    if(fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }
    pthread_mutex_lock(&mut);
    fgets(linebuf, LINESIZE, fp);   //多个线程同时拿到数值一样，后面的写操作会覆盖旧的值
//    fprintf(stdout,"%d号线程拿到的数值是%s\n",i, linebuf);
    fseek(fp, 0, SEEK_SET);
    fprintf(fp,"%d\n",atoi(linebuf)+1);
//    fprintf(stdout,"%d号线程写入的数值是%d\n",i, atoi(linebuf)+1);
    fclose(fp);
    pthread_mutex_unlock(&mut);
    pthread_exit(NULL);
}
int main(int argc, char **argv)
{

    int i,err;
    if(argc<2)
    {
        fprintf(stderr,"argv not enough!\n");
        exit(1);
    }
    int num = atoi(argv[1]);
    pthread_t tid[num];

    for(i=0;i<num;i++)
    {
        err = pthread_create(tid+i, NULL, func, (void *)i); //i一个地址被201个指针指向
        if(err)
        {
            fprintf(stdout,"pthread_create %s\n", strerror(err));
            exit(1);
        }
    }

    for(i=0;i<num;i++)
    {
        pthread_join(tid[i], NULL);
    }
    pthread_mutex_destroy(&mut);
    exit(0);
}