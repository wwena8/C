#include<stdio.h>
#include<stdlib.h>
#include <signal.h>
#include <unistd.h>


int main(int argc, char **argv)
{

    alarm(5);
    while(1)
        pause();
    putchar('\n');
    exit(0);
}