/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-01 14:03:12
 * @FilePath: /Start_net/Llink/LlinkWrapper.cpp
 * @Description:
 *********************************/

#include "LlinkWrapper.h"
#include "llink.h"
#include <iostream>

#ifdef __cplusplus
extern "C"
{
#endif

    struct tagLlink
    {
        MyLinkedList myLinkedList;
    };

    struct tagLlink *Init(void)
    {
        return new struct tagLlink;
    }

    void *getIndex(struct tagLlink *llink, int index)
    {
        return llink->myLinkedList.getIndex(index);
    }

    void *getHead(struct tagLlink *llink)
    {
        return llink->myLinkedList.getHead();
    }

    void *getTail(struct tagLlink *llink)
    {
        return llink->myLinkedList.getTail();
    }

    void addAtHead(struct tagLlink *llink, void *val)
    {
        llink->myLinkedList.addAtHead(val);
    }

    void addAtTail(struct tagLlink *llink, void *val)
    {
        llink->myLinkedList.addAtTail(val);
    }

    void addAtIndex(struct tagLlink *llink, int index, void *val)
    {
        llink->myLinkedList.addAtIndex(index, val);
    }

    void deleteAtIndex(struct tagLlink *llink, int index)
    {
        llink->myLinkedList.deleteAtIndex(index);
    }

    void deinit(struct tagLlink **llink)
    {
        delete *llink;
    }

    int getSize(struct tagLlink *llink)
    {
        return llink->myLinkedList.getSize();
    }

    int isEmpty(struct tagLlink *llink)
    {
        return llink->myLinkedList.isEmpty();
    }

    //通过getSize和getIndex来遍历，将得到的指针进行类型转换
    void traverse(struct tagLlink *llink)
    {
        int i = 0;
        while (i < llink->myLinkedList.getSize())
        {
            // auto ot = (*(array->myArray.Begin() + i));
            std::cout << "Array[" << i << "]:" << *(char **)llink->myLinkedList.getIndex(i) << std::endl;
            // std::cout << "Array[" << i << "]:" << *ot << std::endl;
            i++;
        }
    }

#ifdef __cplusplus
};
#endif