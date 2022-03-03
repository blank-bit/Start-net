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
    char* name;
};

int main(void)
{
    struct tagLlink* pLlink;
    pLlink = Init();

    if (isEmpty(pLlink))
    {
        printf("isEmpty\n");
    }

    // int s.name = 7;
    // char *s.name = "777g";
    struct test s;
    s.name = "hhdua";
    s.num = 13;

    addAtHead(pLlink, &s);
    printf("addhead.......%s\n", (*(struct test*)(getHead(pLlink))).name);
    printf("addhead.......%d\n", (*(struct test*)(getHead(pLlink))).num);

    s.name = "fsf";
    addAtHead(pLlink, &s);
    printf("addhead.......%s\n", (*(struct test*)(getHead(pLlink))).name);
    printf("addhead.......%d\n", (*(struct test*)(getHead(pLlink))).num);

    s.num = 45;
    addAtTail(pLlink, &s);
    // printf("addtail.......%s\n", *(char **)(getTail(pLlink)));
    printf("addhead.......%s\n", (*(struct test*)(getTail(pLlink))).name);
    printf("addhead.......%d\n", (*(struct test*)(getTail(pLlink))).num);

    // s.name = "32";
    // addAtTail(pLlink, &s);
    // printf("addtail.......%s\n", *(char **)(getTail(pLlink)));

    // printf("GET0.......%s\n", *(char **)(getIndex(pLlink, 0)));
    // printf("GET1.......%s\n", *(char **)(getIndex(pLlink, 1)));
    // printf("GET2.......%s\n", *(char **)(getIndex(pLlink, 2)));
    // printf("GET3.......%s\n", *(char **)(getIndex(pLlink, 3)));

    if (!isEmpty(pLlink))
    {
        printf("notEmpty\n");
    }

    struct test stu;
    stu.name = "stuname";
    stu.num = 58;
    addAtIndex(pLlink, 2, &stu);
    printf("addindex.......\n");
    printf("addhead.......%s\n", (*(struct test*)(getIndex(pLlink, 2))).name);
    printf("addhead.......%d\n", (*(struct test*)(getIndex(pLlink, 2))).num);

    // s.name = "endofjahfk";
    // addAtIndex(pLlink, 1, &s);
    // printf("addindex.......\n");

    // traverse(pLlink);

    deleteAtIndex(pLlink, 4);
    printf("delete4.......\n");

    // deleteAtIndex(pLlink, 0);
    printf("delete0.......\n");

    // char *s = "dhjskfsf";
    // addAtHead(pLlink, &s);
    // traverse(pLlink);

    deinit(&pLlink);

    return 0;
}