/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-03 16:03:29
 * @FilePath: \week1\TH\ThreadPool.h
 * @Description:
 *********************************/

// threadpool.h
#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_

#include <vector>
#include <list>
#include "mutex.h"

using std::list;
using std::vector;

class ThreadPool;

typedef void (*threadfunc_t)(void *);

struct ThreadJob
{
    threadfunc_t fun;
    void *arg;
    ThreadJob()
    {
        memset(this, 0, sizeof(ThreadJob));
    }
    ThreadJob(threadfunc_t f, void *a)
    {
        fun = f;
        arg = a;
    }
    void Run()
    {
        if (fun)
        {
            fun(arg);
        }
    }
};

struct ThreadItem
{
    uintptr_t thread;
    ThreadPool *pool;
    bool run;
    ThreadItem()
    {
        pool = NULL;
        run = false;
    }
};

class ThreadPool
{
public:
    ThreadPool();
    ThreadPool(int num);
    ~ThreadPool();

    bool CreatePool(int num);
    int Active();                               //正在激活的线程
    int Pending();                              //当前准备可以调度的线程
    int JobNum();                               //当前任务数
    bool Schedule(threadfunc_t fun, void *arg); //执行一个工作
    bool Destory();                             //摧毁
    static void JobThread(void *arg);

private:
    Mutex listlock;
    vector<ThreadItem> m_thread;
    list<ThreadJob> joblist;
    HANDLE EventComplete;
    HANDLE SemaphoreCall;
    HANDLE SemaphoreDel;
    long runnum;
    long threadnum;
};

#endif