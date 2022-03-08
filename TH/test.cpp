/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-03 16:05:42
 * @FilePath: \week1\TH\test.cpp
 * @Description:
 *********************************/
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "ThreadPool.h"

void ts(void* n)
{
	printf("tsmsg:%d\t", *(int*)n);
	printf("id:%d\n", ::GetCurrentThreadId());
}

void tp(void* n)
{
	printf("tpmsg:%d\t", *(int*)n);
	printf("id:%d\n", ::GetCurrentThreadId());
}

int main()
{
	ThreadPool threadpool(4);
	printf("begin\n");
	for (int i = 0; i < 10; i++)
	{
		threadfunc_t t;
		if (i % 2)
		{
			t = ts;
		}
		else
		{
			t = tp;
		}

		threadpool.Schedule(t, &i);
		Sleep(100);
	}
	threadpool.Destory();
	_CrtDumpMemoryLeaks();
}