#include <iostream>
#include <Windows.h>
#include "ThreadPool.h"
#include <stdio.h>
#include <crtdbg.h>

void func()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::cout << "worker thread ID:" << std::this_thread::get_id() << std::endl;
}

int main()
{
	ThreadPool pool(4);
	int i = 0;
	while (i < 20)
	{
		pool.enqueue(func);
		i++;
		Sleep(100);
	}
	pool.~ThreadPool();
	_CrtDumpMemoryLeaks();
}