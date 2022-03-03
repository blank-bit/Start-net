/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-02 16:27:24
 * @FilePath: \练习\ThreadPool\ThreadPool.h
 * @Description:
 *********************************/

#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <Windows.h>
#include <list>
#include <queue>
#include <memory>

using std::list;
using std::queue;
using std::shared_ptr;

typedef int (*TaskFun)(void *param);

class ThreadPool
{
private:
    int maxsize;
    bool stop;

public:
    ThreadPool(int size);
    ~ThreadPool();

    void CreateThread(int num);
    void EnQueue(TaskFun func);
};

ThreadPool::ThreadPool(int size)
{
}

ThreadPool::~ThreadPool()
{
}

#endif