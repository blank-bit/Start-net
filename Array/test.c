/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-01 16:55:55
 * @FilePath: /Start_net/Array/test.c
 * @Description:
 *********************************/

#include "ArrayWrapper.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct VLArray *array;
    array = Init();

    printf("------init--------\n");
    printf("------push1-------\n");
    for (int i = 0; i < 20; i++)
    {
        if (i % 2)
        {
            PushBack(array, &i);
        }
        else
        {
            PushFront(array, &i);
        }
        Traverse(array);
    }

    printf("-------delete-------\n");
    for (int i = 0; i < 11; i++)
    {
        DeleteIndex(array, 1);
    }

    Traverse(array);

    printf("-------delete1-------\n");
    DeleteIndex(array, 1);
    Traverse(array);

    printf("-------push3-------\n");
    int i = 7;
    PushBack(array, &i);
    Traverse(array);

    printf("-------pushf11-------\n");
    i = 11;
    PushFront(array, &i);
    Traverse(array);

    printf("index2:%d\n", *(int *)GetIndex(array, 2));

    printf("-------INSERT2-------\n");
    i = 93;
    Insert(array, 0, &i);
    printf("index2:%d\n", *(int *)GetIndex(array, 2));

    Traverse(array);

    Deinit(&array);
}