#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main(int argc, char **argv)
{
    FILE *fps, *fpd;

    char *linebuf = NULL;
    size_t linesize = 64;
    size_t ch;
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
        ch = getline(&linebuf, &linesize, fps);

        if(ch <= 0)
            break;

        printf("%lu\n", strlen(linebuf));
        printf("%lu\n", linesize);
    }       //diff 查看两个文件是否相同
    fclose(fps);
    exit(0);
}