#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

#define LEFT 30000000
#define RIGHT 30000200
int main(int argc, char **argv)
{

    int i,j,mark,count;
    for(i= LEFT;i<=RIGHT;i++)
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
    }
    printf("count = %d\n", count);
    exit(0);
}