/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-04 10:51:32
 * @FilePath: \week1\ThreadPool\test.cpp
 * @Description:
 *********************************/
// ThreadpoolTest.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include "ThreadPool.h"

void Test(void *arg)
{
    printf("\nEnterTest\tThreadID:%u\n", GetCurrentThreadId());
    Sleep(5);

    Sleep(5);
    printf("ExitTest\n");
}

void Test2(void *arg)
{
    printf("\nEnterTest2\t");
    printf("ThreadID:%u\n", GetCurrentThreadId());
    Sleep(5);
    int a = *(int *)arg;
    // printf("Test2:%d\tThreadID:%u\n", a, GetCurrentThreadId());
    printf("\nExitTest2\n");
}

void Test3(void *arg)
{
    printf("\nEnterTest3\t");
    printf("ThreadID:%u\n", GetCurrentThreadId());
    Sleep(5);
    int a = *(int *)arg;
    // printf("a=%d\tThreadID:%u\n", a, GetCurrentThreadId());
    printf("\nExitTest3\n");
}

void Test4(void *arg)
{
    printf("\nEnterTest4\t");
    printf("ThreadID:%u\n", GetCurrentThreadId());
    Sleep(5);
    int a = 33 * 55;
    // printf("a=%d\tThreadID:%u\n", a, GetCurrentThreadId());
    printf("\nExitTest4\n");
}

int main()
{
    ThreadPool pool(3);
    int i = 938;
    int t = 836;
    pool.AddTask(Test, (void *)NULL);
    pool.AddTask(Test4, (void *)NULL);
    pool.AddTask(Test2, &i);
    pool.AddTask(Test3, &t);
    pool.AddTask(Test4, (void *)NULL);

    Sleep(100);

    return 0;
}
