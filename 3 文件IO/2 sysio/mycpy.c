#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int sfd, dfd;
    int BUFFER_SIZE = atoi(argv[3]);
    char buf[BUFFER_SIZE];
    int len,ret,pos;

    if(argc < 4)
    {
        fprintf(stderr,"Usage:%s <src_file> <dest_file>\n", argv[0]);
        exit(1);
    }

    sfd = open(argv[1], O_RDONLY); //创建形式追加
    if(sfd < 0)
    {
        perror("open()");  // perror
        exit(1);
    }

    dfd = open(argv[2],O_RDWR|O_CREAT,0600);

    if(dfd < 0)
    {
        close(sfd);
        perror("open()");  // perror
        exit(1);
    }

    while(1) {
        len = read(sfd, buf, BUFFER_SIZE);   //返回真正读到的字节数
//        fprintf(stdout,"%d\n", len);
        if(len <= 0)   //end of file
        {
            perror("read()");
            break;
        }
        pos = 0;
        while(len > 0)
        {
            ret = write(dfd, buf+pos, len);
            if(len <= 0)   //end of file
            {
                perror("write()");
                exit(1);
            }
            pos += ret;
            len -= ret;
        }

    }       //diff 查看两个文件是否相同
    close(sfd);
    close(dfd);
    puts("OK!");
    exit(0);
}