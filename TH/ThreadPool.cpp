/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-03 16:03:20
 * @FilePath: \week1\TH\ThreadPool.cpp
 * @Description:
 *********************************/

// threadpool.cpp
#include "threadpool.h"
#include <errno.h>
#include <process.h>

ThreadPool::ThreadPool()
{
    threadnum = runnum = 0;
}

ThreadPool::ThreadPool(int num)
{
    threadnum = runnum = 0;
    CreatePool(num);
}

ThreadPool::~ThreadPool()
{
    Destory();
    CloseHandle(SemaphoreCall);
    CloseHandle(SemaphoreDel);
    CloseHandle(EventComplete);
}

bool ThreadPool::CreatePool(int num)
{
    m_thread.reserve(num);
    SemaphoreCall = CreateSemaphore(0, 0, 10000, NULL);
    SemaphoreDel = CreateSemaphore(0, 0, 10000, NULL);
    EventComplete = CreateEvent(0, false, false, NULL);
    for (int i = 0; i < num; i++)
    {
        m_thread.push_back(ThreadItem());
        m_thread[i].pool = this;
        m_thread[i].thread = _beginthread(JobThread, 0, &m_thread[i]); // create
    }
    threadnum = num;
    return true;
}

int ThreadPool::Active() //正在激活的线程
{
    return runnum;
}

int ThreadPool::Pending() //当前准备可以调度的线程
{
    return threadnum - runnum;
}

int ThreadPool::JobNum()
{
    return joblist.size();
}

bool ThreadPool::Schedule(threadfunc_t fun, void *arg) //执行一个工作
{
    listlock.Lock();
    joblist.push_back(ThreadJob(fun, arg));

    ReleaseSemaphore(SemaphoreCall, 1, NULL);
    listlock.Unlock();
    return true;
}

bool ThreadPool::Destory() //摧毁
{
    if (threadnum)
    {
        ReleaseSemaphore(SemaphoreDel, threadnum, NULL);
        // return !!WaitForSingleObject(EventComplete, INFINITE);
        return WaitForSingleObject(EventComplete, INFINITE);
    }
    return true;
}

void ThreadPool::JobThread(void *threadItem)
{
    ThreadItem *threaditem = (ThreadItem *)threadItem;
    ThreadPool *pool = threaditem->pool;
    HANDLE hWaitHandle[2];
    hWaitHandle[0] = pool->SemaphoreCall; //有任务进来
    hWaitHandle[1] = pool->SemaphoreDel;  //线程退出
    while (1)
    {
        DWORD wr = WaitForMultipleObjects(2, hWaitHandle, false, INFINITE);

        if (wr == WAIT_OBJECT_0 + 1) //得到退出信号
            break;

        pool->listlock.Lock();

        if (!pool->joblist.empty()) //取第一个任务执行
        {
            ThreadJob job = pool->joblist.front();
            pool->joblist.pop_front();
            pool->listlock.Unlock();

            InterlockedIncrement(&pool->runnum); //原子操作加减

            threaditem->run = true;
            job.Run();
            threaditem->run = false;

            InterlockedDecrement(&pool->runnum);
        }
        else
            pool->listlock.Unlock();
    }

    InterlockedDecrement(&pool->threadnum);

    if (!pool->threadnum)
    {
        SetEvent(pool->EventComplete);
    }
}