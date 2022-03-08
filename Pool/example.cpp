#include "stdafx.h"
#include "ThreadPool.h"
#include <stdio.h>

class Task
{
public:
    static int Task1(PVOID p)
    {
        int i = 10;
        while (i >= 0)
        {
            printf("%d\n", i);
            Sleep(100);
            i--;
        }
        return i;
    }
};

class TaskCallback
{
public:
    static void TaskCallback1(int result)
    {
        printf("   %d\n", result);
    }
};

int main()
{
    ThreadPool threadPool(2, 10);
    for (size_t i = 0; i < 30; i++)
    {
        threadPool.QueueTaskItem(Task::Task1, NULL, TaskCallback::TaskCallback1);
    }
    threadPool.QueueTaskItem(Task::Task1, NULL, TaskCallback::TaskCallback1, TRUE);

    getchar();

    return 0;
}