/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-01 14:04:39
 * @FilePath: /Start_net/Array/array.cpp
 * @Description:
 *********************************/

#include "array.h"

MyArray::MyArray() : _first(nullptr), _last(nullptr), _end(nullptr)
{
    _first = new void* [iArrayLen];
    _last = _first;
    _end = _first + iArrayLen;
}

MyArray::MyArray(int size) : _first(nullptr), _last(nullptr), _end(nullptr), capacity(size)
{
    _first = new void* [size];
    _last = _first;
    _end = _first + size;
}

void** MyArray::Begin()
{
    return _first;
}

void** MyArray::End()
{
    return _last;
}

MyArray::~MyArray()
{
    delete[] _first;
}

/*********************************
 * @function: PushBack
 * @description: ������ĩβ�������
 * @param {void} *val
 * @return {*}
 *********************************/
void MyArray::PushBack(void* val)
{
    CheckCapacity();
    _last[0] = val;
    ++_last;
}

/*********************************
 * @function: PushFront
 * @description: ������ͷ��������
 * @param {void} *val
 * @return {*}
 *********************************/
void MyArray::PushFront(void* val)
{
    CheckCapacity();
    for (int i = Size() - 1; i >= 0; --i)
    {
        _first[i + 1] = _first[i];
    }
    _first[0] = val;
    ++_last;
}

/*********************************
 * @function: Insert
 * @description: �������в�������
 * @param {int} index
 * @param {void} *val
 * @return {*}
 *********************************/
void MyArray::Insert(int index, void* val)
{
    if (index < 0 || index > Size())
    {
        return;
    }

    CheckCapacity();
    if (index == Size())
    {
        _last[0] = val;
        ++_last;
        return;
    }

    for (int i = Size() - 1; i >= index; --i)
    {
        _first[i + 1] = _first[i];
    }
    _first[index] = val;
    ++_last;
}

/*********************************
 * @function: Pop_back
 * @description: ɾ�����һ������
 * @param {*}
 * @return {*}
 *********************************/
void MyArray::PopBack()
{
    if (!Empty())
    {
        --_last;
    }
}

/*********************************
 * @function: DeleteIndex
 * @description: ɾ����Index������(0-Index)
 * @param {int} index
 * @return {*}
 *********************************/
void MyArray::DeleteIndex(int index)
{
    if (index > Size() - 1 || index < 0)
    {
        return;
    }

    for (int i = index; i < Size() - 1; ++i)
    {
        _first[i] = _first[i + 1];
    }

    --_last;

    CheckCapacity();
}

int MyArray::Empty()
{
    if (_last == _first)
    {
        return 1;
    }
    return 0;
}

/*********************************
 * @function: ExpCapacity
 * @description: ���鳤����������
 * @param {*}
 * @return {*}
 *********************************/
void MyArray::ExpCapacity(void)
{
    int size = Size();
    int newSize = 2 * size;
    void** tmp = new void* [newSize];

    if (_first)
    {
        for (int i = 0; i < size; ++i)
        {
            tmp[i] = _first[i];
        }

        delete[] _first;
    }

    _first = tmp;
    _last = _first + size;
    _end = _first + newSize;
    capacity = newSize;
}

/*********************************
 * @function: CutCapacity
 * @description: ���鳤������һ��
 * @param {*}
 * @return {*}
 *********************************/
void MyArray::CutCapacity(void)
{
    if (!_first)
    {
        return;
    }

    int size = Size();
    int newSize = capacity / 2;
    void** tmp = new void* [newSize];

    if (newSize <= size)
    {
        for (int i = 0; i < newSize; ++i)
        {
            tmp[i] = _first[i];
        }
    }
    else
    {
        for (int i = 0; i < size; ++i)
        {
            tmp[i] = _first[i];
        }
    }

    delete[] _first;

    _first = tmp;
    if (newSize <= size)
    {
        _last = _first + newSize;
    }
    else
    {
        _last = _first + size;
    }
    _end = _first + newSize;
    capacity = newSize;
}

/*********************************
 * @function: GetIndex
 * @description: ��ȡ��index������
 * @param {int} index
 * @return {void *}
 *********************************/
void* MyArray::GetIndex(int index)
{
    if (index > Size() - 1 || index < 0)
    {
        return nullptr;
    }

    return _first[index];
}

/*********************************
 * @function: Traverse
 * @description: ���������������
 * @param {*}
 * @return {*}
 *********************************/
 // void MyArray::Traverse()
 // {
 //     int i = 0;
 //     while (i < Size())
 //     {
 //         std::cout << "Array[" << i << "]:" << *(int *)_first[i] << std::endl;
 //         i++;
 //     }
 // }

 /*********************************
  * @function: Size
  * @description: �����������ݳ���
  * @param {*}
  * @return {int}
  *********************************/
int MyArray::Size()
{
    return _last - _first;
}

/*********************************
 * @function: Capacity
 * @description: ������������
 * @param {*}
 * @return {int}
 *********************************/
int MyArray::Capacity()
{
    return _end - _first;
}

/*********************************
 * @function: CheckCapacity
 * @description: �ж��Ƿ���Ҫ����/�������鳤��
 * @param {*}
 * @return {*}
 *********************************/
void MyArray::CheckCapacity()
{
    if (_last == nullptr)
        return;

    //��������
    if (_last == _end)
    {
        return ExpCapacity();
    }

    //���ݳ��Ȳ���������һ��(������С��iArrayLen)
    if ((Size() * 2) <= Capacity() && Size() >= iArrayLen)
    {
        return CutCapacity();
    }
}