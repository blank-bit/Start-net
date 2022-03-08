/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-03 16:03:08
 * @FilePath: \week1\TH\mutex.h
 * @Description:
 *********************************/

// mutex.h
#ifndef _MUTEX_H_
#define _MUTEX_H_
#include <windows.h>

class Mutex
{
public:
    Mutex();
    Mutex(const Mutex &m);
    ~Mutex();

    HANDLE handle;
    CRITICAL_SECTION c_lock;
    void Lock();
    void Unlock();

    Mutex &operator=(const Mutex &m);
};
#endif
