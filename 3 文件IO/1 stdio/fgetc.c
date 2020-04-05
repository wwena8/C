#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main(int argc, char **argv)
{
    FILE *fps, *fpd;

    int ch,count;
    fps = fopen(argv[1], "r"); //创建形式追加

    if(argc < 2)
    {
        fprintf(stderr,"Usage:%s <src_file> <dest_file>\n", argv[0]);
        exit(1);
    }
    if(fps == NULL)
    {
        perror("fopen()");  // perror
        exit(1);
    }

    while(1) {
        ch = fgetc(fps);
        if(ch == EOF)   //end of file
            break;
        count++;
    }       //diff 查看两个文件是否相同
    fprintf(stderr, "count = %d\n", count);
    fclose(fps);
    exit(0);
}