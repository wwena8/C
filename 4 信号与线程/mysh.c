#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

#define DELIMS "\t\n"

void prompt(void);
void parse(const char *line);

int main(int argc, char **argv)
{
    char *linebuf = NULL;
    size_t linebuf_size = 0;

    while(true)
    {
        prompt();

        if (getline(&linebuf, &linebuf_size, stdin) < 0)    //getline拿进来一行放入linebuf中
            break;

        parse(linebuf);
        if() {

        } else {

        }
    }
    exit(0);
}

void prompt(void)
{
    printf("mysh -0.1$");
}

void parse(const char *line)
{
    char *tok;
    glob_t globress;
    int i;
    while(1)
    {
        tok = strsep(&line);
        if(tok == NULL)
            break;
        if(tok[0] == '\0')
            continue;
        glob(tok, GLOB_NOCHECK|GLOB_APPEND*i, NULL, &globress);
        i = 1;
    }

}