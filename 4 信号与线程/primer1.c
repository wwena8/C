#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

#define LEFT 30000000
#define RIGHT 30000500
int main(int argc, char **argv)
{

    int i,j,mark,count;
    pid_t pid;
    for(i= LEFT;i<=RIGHT;i++)
    {

        pid = fork();

        if(pid <0)
        {
            perror("fork()");
            exit(1);
        }

        if(pid==0)
        {
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
                count++;
            }
            exit(0);
        }


    }
    exit(0);
}