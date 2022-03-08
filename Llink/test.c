/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-01 14:03:19
 * @FilePath: /Start_net/Llink/test.c
 * @Description:
 *********************************/

#include "LlinkWrapper.h"
#include <stdio.h>
#include <stdlib.h>

struct test
{
    int num;
    char *name;
};

int main(void)
{
    struct tagLlink *pLlink;
    pLlink = Init();

    if (isEmpty(pLlink))
    {
        printf("isEmpty\n");
    }

    char *s = "svhj";
    addAtTail(pLlink, &s);
    printf("addtail.......%s\n", *(char **)(getTail(pLlink)));

    char *t = "ttttt";
    addAtHead(pLlink, &t);

    char *a = "aaaa";
    addAtIndex(pLlink, 0, &a);

    char *b = "bbbb";
    addAtIndex(pLlink, 3, &b);

    printf("GET0.......%s\n", *(char **)(getIndex(pLlink, 0)));
    printf("GET1.......%s\n", *(char **)(getIndex(pLlink, 1)));
    printf("GET2.......%s\n", *(char **)(getIndex(pLlink, 2)));
    printf("GET3.......%s\n", *(char **)(getIndex(pLlink, 3)));

    printf("Size:.......%d\n", getSize(pLlink));
    traverse(pLlink);

    deleteAtIndex(pLlink, 2);
    printf("delete2.......\n");

    deleteAtIndex(pLlink, 0);
    printf("delete0.......\n");

    traverse(pLlink);

    deinit(&pLlink);

    return 0;
}