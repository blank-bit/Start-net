/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-01 14:15:26
 * @FilePath: /Start_net/Array/array.h
 * @Description:
 *********************************/

#ifndef _ARRAY_H
#define _ARRAY_H

#include <iostream>

class MyArray
{
public:
    const int iArrayLen = 5;
    MyArray();
    MyArray(int size);
    void **Begin();
    void **End();
    void PushBack(void *val);
    void PushFront(void *val);
    void Insert(int index, void *val);
    void PopBack();
    void DeleteIndex(int index);
    int Empty();
    void ExpCapacity(void);
    void CutCapacity(void);
    void *GetIndex(int index);
    // void Traverse();
    int Size();
    int Capacity();
    void CheckCapacity();
    ~MyArray();

private:
    void **_first;
    void **_last;
    void **_end;
    int capacity;
};

#endif
