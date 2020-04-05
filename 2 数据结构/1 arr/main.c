#include<stdio.h>
#include<stdlib.h>
#include"sqlist.h"

int main()
{
    sqlist *list;
    datatype arr[] = {12,23,34,45,56};
    list = sqlist_create();
    int i,err;
    if(list == NULL)
    {
        fprintf(stderr, "sqlist_create() failed!\n");
        exit(1);
    }

    for(i=0; i<sizeof(arr)/sizeof(*arr); i++) {
        if((err = sqlist_insert(list,20,&arr[i]))!=0)
        {
            if(err == -1)
                fprintf(stderr, "The arr is full\n");
            if(err == -2)
                fprintf(stderr, "The pos is wrong\n");
            exit(-1);
        }
    }
    sqlist_display(list);
    exit(0);
}