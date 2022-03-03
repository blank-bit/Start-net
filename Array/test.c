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
    struct VLArray* array;
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

        // Traverse(array);
    }
    // int i = 7;
    // PushBack(array, &i);
    // int j = 8;
    // PushBack(array, &j);
    // char *s = "djkg";
    // PushBack(array, &s);
    // printf("index0:%d\n", *(int *)GetIndex(array, 0));
    // printf("index1:%d\n", *(int *)GetIndex(array, 1));
    // printf("index2:%s\n", *(char **)GetIndex(array, 2));
    // Traverse(array);

    // printf("capacity:%d\n", Capacity(array));

    printf("-------cut-------\n");
    // cutCapacity(array);
    for (int i = 0; i < 11; i++)
    {
        DeleteIndex(array, 1);
    }
    // printf("capacity:%d\n", Capacity(array));

    Traverse(array);

    printf("-------delete1-------\n");
    DeleteIndex(array, 1);
    // printf("capacity:%d\n", Capacity(array));
    Traverse(array);

    // printf( "capacity:" << Capacity() );

    printf("-------push3-------\n");
    int i = 7;
    PushBack(array, &i);
    Traverse(array);
    // printf("capacity:%d\n", Capacity(array));

    printf("-------pushf11-------\n");
    i = 11;
    PushFront(array, &i);
    Traverse(array);

    printf("index2:%d\n", *(int*)GetIndex(array, 2));

    printf("-------INSERT2-------\n");
    i = 93;
    Insert(array, 0, &i);
    printf("index2:%d\n", *(int*)GetIndex(array, 2));

    Traverse(array);

    // for (int i = 0; i < 4; i++)
    // {
    //     DeleteIndex(array, 0);
    // }
    // Traverse(array);
    // printf("capacity:%d\n", Capacity(array));

    Deinit(&array);
}