#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <glob.h>

#define PATH "/Users/apple/WORK"
int main(int argc, char **argv)
{

    glob_t globres;
//    char *PATH = argv[1];
    int err = glob(PATH,0,NULL,&globres);

    if(err)
    {
        perror("glob()");
        exit(1);
    }
    printf("gl_pathc = %zu\n", globres.gl_pathc);
    for(int i=0; i<globres.gl_pathc;i++){
        puts(globres.gl_pathv[i]);
    }
    exit(0);
}