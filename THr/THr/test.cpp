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

void taskTest(void* arg)
{
    printf("\nEnterTaskTest\tThreadID:%u\n", GetCurrentThreadId());
    Sleep(5);

    Sleep(5);
    printf("ExitTaskTest\n");
}

void sumTest1(void* arg)
{
    printf("\nEnterSumtest1\t");
    printf("ThreadID:%u\n", GetCurrentThreadId());
    Sleep(5);
    int a = 33 * 55;
    // printf("a=%d\tThreadID:%u\n", a, GetCurrentThreadId());
    printf("\nExitSumtest1\n");
}

void taskTest2(void* arg)
{
    printf("\nEntertaskTest2\t");
    printf("ThreadID:%u\n", GetCurrentThreadId());
    Sleep(5);
    int a = *(int*)arg;
    // printf("taskTest2:%d\tThreadID:%u\n", a, GetCurrentThreadId());
    printf("\nExittaskTest2\n");
}

void sumTest3(void* arg)
{
    printf("\nEntersumTest3\t");
    printf("ThreadID:%u\n", GetCurrentThreadId());
    Sleep(5);
    int a = *(int*)arg;
    // printf("a=%d\tThreadID:%u\n", a, GetCurrentThreadId());
    printf("\nExitsumTest3\n");
}

int main()
{
    ThreadPool pool(3);
    int i = 938;
    int t = 836;
    pool.AddTask(taskTest, (void*)NULL);
    pool.AddTask(sumTest1, (void*)NULL);
    pool.AddTask(taskTest2, &i);
    pool.AddTask(sumTest3, &t);
    pool.AddTask(sumTest1, (void*)NULL);

    Sleep(100);

    return 0;
}
