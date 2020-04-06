#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <uuid/uuid.h>

#define BUFFER_SIZE 1024


int main(int argc, char **argv)
{
    char *input_pass;
    char *crypted_pass;
    struct spwd *showline;
    if(argc <2)
    {
        fprintf(stderr,"Usage:%s <src_file> <dest_file>\n", argv[0]);
        exit(1);
    }

    input_pass = getpass("passwd");
    showline = getspnam(argv[1]);
    crypted_pass = crypt(input_pass, showline->sp_pwdp);

    if(strcmp(showline->sp_pwdp, crypted_pass) == 0)
        puts("ok!");
    else
        puts("fail!");

    exit(0);
}