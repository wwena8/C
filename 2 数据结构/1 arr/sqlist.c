#include<stdio.h>
#include"sqlist.h"

sqlist *sqlist_create() //利用函数返回值
{
    sqlist *me;
    me = malloc(sizeof(*me));
    if(me == NULL)
        return NULL;
    me->last = -1;
    return me;
}

void sqlist_create1(sqlist **ptr)   //利用二级指针传参
{
    *ptr = malloc(sizeof(**ptr));
    if(*ptr == NULL)
        return;
    (*ptr)->last=1;
    return;
}

/*
    插入数据
*/
int sqlist_insert(sqlist *me, int i, datatype *data)
{
    int j;
    if(me->last == DATASIZE-1)
        return -1;

    if(i<0 || i>me->last+1)
        return -2;

    for (j = me->last; i<=j; j++) {
        me->data[j+1]  = me->data[j];
    }

    me->data[i] = *data;
    me->last++;
    return 0;
}

/*
    删除数据
*/
int sqlist_delete(sqlist *me, int i)
{
    int j;
    if(i<0 || i>me->last)
        return -1;
    for (j=i+1; j<=me->last; j++)
        me->data[j-1] = me->data[j];

    me->last--;
    return 0;
}

int sqlist_find(sqlist *me, datatype *data)
{
}

int sqlist_isempty(sqlist *me)
{
}

int sqlist_setempty(sqlist *me)
{
}

int sqlist_getnum(sqlist *me)
{
}

int sqlist_union(sqlist *list1, sqlist *list2)
{
}

void sqlist_display(sqlist *me)
{
    if(me->last == -1)
        return;
    for(int i=0; i<me->last; i++)
        printf("%d ", me->data[i]);
    putchar('\n');
    return;
}
