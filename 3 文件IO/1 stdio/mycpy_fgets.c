#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

#define BUFFER_SIZE 1024
int main(int argc, char **argv)
{
    FILE *fps, *fpd;

    char *buf[BUFFER_SIZE];
    const char *ch;
    fps = fopen(argv[1], "r"); //创建形式追加

    if(argc < 3)
    {
        fprintf(stderr,"Usage:%s <src_file> <dest_file>\n", argv[0]);
        exit(1);
    }
    if(fps == NULL)
    {
        perror("fopen()");  // perror
        exit(1);
    }
    fpd = fopen(argv[2], "w");

    if(fpd == NULL)
    {
        fclose(fps);    //目标文件打开失败，需要释放已经打开的资源
        perror("fopen()");  // perror
        exit(1);
    }

    while(1) {
        ch = fgets(buf, BUFFER_SIZE, fps);
        if(ch == NULL)   //end of file
            break;
        fputs(buf, fpd);
    }       //diff 查看两个文件是否相同
    fclose(fpd);
    fclose(fps);
    puts("OK!");
    exit(0);
}