/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-03 16:03:03
 * @FilePath: \week1\TH\mutex.cpp
 * @Description:
 *********************************/

// mutex.cpp
#include "mutex.h"

Mutex::Mutex()
{
    InitializeCriticalSection(&c_lock);
}

Mutex::Mutex(const Mutex &m)
{
    InitializeCriticalSection(&c_lock);
}

Mutex::~Mutex()
{
    DeleteCriticalSection(&c_lock);
}

void Mutex::Lock()
{
    EnterCriticalSection(&c_lock); //进入锁临界区
}

void Mutex::Unlock()
{
    LeaveCriticalSection(&c_lock); //进入锁临界区
}

Mutex &Mutex::operator=(const Mutex &m)
{
    //不进行复制
    return *this;
}
