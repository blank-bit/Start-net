/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-03 15:02:14
 * @FilePath: \week1\ThreadPool\ThreadPool.h
 * @Description:
 *********************************/

#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <Windows.h>
#include <process.h>
#include "..\Array\array.h"
#include "..\Llink\llink.h"

using namespace std;

typedef void (*TaskFun)(void *arg);

class Mutex
{
public:
	Mutex();
	~Mutex();

	void Lock();
	void Unlock();

private:
	CRITICAL_SECTION cslock;
};

struct ThreadItem
{
	TaskFun task;
	void *arg;
	ThreadItem(TaskFun f, void *a)
	{
		task = f;
		arg = a;
	}
};

class ThreadPool
{
private:
	MyArray Handles;
	int MaxThreadNum;
	// HANDLE RunThreadSem;
	// long RunThreadNum;

public:
	ThreadPool();
	ThreadPool(int size);
	~ThreadPool();

	void InitThreadPool();
	void AddTask(TaskFun task, void *arg);
	void ExitThreadPool();
	MyLinkedList Tasklist;
	Mutex mutex;
	bool stop;
};

ThreadPool::ThreadPool() : MaxThreadNum(5), stop(false)
{
	InitThreadPool();
}

ThreadPool::ThreadPool(int size) : MaxThreadNum(size), stop(false)
{
	InitThreadPool();
}

ThreadPool::~ThreadPool()
{
	ExitThreadPool();
}

void Worker(LPVOID *pl)
{
	ThreadPool *pool = (ThreadPool *)pl;

	while (!pool->stop)
	{
		pool->mutex.Lock();
		if (pool->Tasklist.isEmpty())
		{
			pool->mutex.Unlock();
			continue;
		}

		TaskFun task = (*(ThreadItem *)(pool->Tasklist.getHead())).task;
		void *arg = (*(ThreadItem *)(pool->Tasklist.getHead())).arg;
		pool->Tasklist.deleteAtIndex(0);
		pool->mutex.Unlock();

		(*task)(arg);
	}
}

void ThreadPool::InitThreadPool()
{
	// RunThreadSem = CreateSemaphore(NULL, MaxThreadNum, MaxThreadNum, NULL);
	for (int i = 0; i < MaxThreadNum; i++)
	{
		HANDLE hd = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Worker, (LPVOID *)this, 0, NULL); //未挂起
		Handles.PushBack(&hd);
	}
}

void ThreadPool::AddTask(TaskFun task, void *arg)
{
	mutex.Lock();
	// WaitForSingleObject(RunThreadSem, INFINITE);
	// int t = InterlockedIncrement(&RunThreadNum);
	// // InterlockedDecrement(&RunThreadNum);
	// ResumeThread(*(HANDLE *)Handles.GetIndex(t - 1));

	ThreadItem *item = new ThreadItem(task, arg);
	Tasklist.addAtTail(item);
	mutex.Unlock();
}

void ThreadPool::ExitThreadPool()
{
	stop = true;
	for (int i = 0; i < (int)Handles.Size(); ++i)
	{
		WaitForSingleObject(*(HANDLE *)Handles.GetIndex(i), INFINITE);
	}
}

Mutex::Mutex()
{
	InitializeCriticalSection(&cslock);
}

Mutex::~Mutex()
{
	DeleteCriticalSection(&cslock);
}

void Mutex::Lock()
{
	EnterCriticalSection(&cslock);
}

void Mutex::Unlock()
{
	LeaveCriticalSection(&cslock);
}

#endif
