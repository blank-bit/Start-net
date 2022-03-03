/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-01 14:03:12
 * @FilePath: /Start_net/Llink/LlinkWrapper.cpp
 * @Description:
 *********************************/

#include "LlinkWrapper.h"
#include "llink.h"

#ifdef __cplusplus
extern "C"
{
#endif

    struct tagLlink
    {
        MyLinkedList myLinkedList;
    };

    struct tagLlink* Init(void)
    {
        return new struct tagLlink;
    }

    void* getIndex(struct tagLlink* llink, int index)
    {
        return llink->myLinkedList.getIndex(index);
    }

    void* getHead(struct tagLlink* llink)
    {
        return llink->myLinkedList.getHead();
    }

    void* getTail(struct tagLlink* llink)
    {
        return llink->myLinkedList.getTail();
    }

    void addAtHead(struct tagLlink* llink, void* val)
    {
        llink->myLinkedList.addAtHead(val);
    }

    void addAtTail(struct tagLlink* llink, void* val)
    {
        llink->myLinkedList.addAtTail(val);
    }

    void addAtIndex(struct tagLlink* llink, int index, void* val)
    {
        llink->myLinkedList.addAtIndex(index, val);
    }

    void deleteAtIndex(struct tagLlink* llink, int index)
    {
        llink->myLinkedList.deleteAtIndex(index);
    }

    void deinit(struct tagLlink** llink)
    {
        delete* llink;
    }

    int getSize(struct tagLlink* llink)
    {
        return llink->myLinkedList.getSize();
    }

    int isEmpty(struct tagLlink* llink)
    {
        return llink->myLinkedList.isEmpty();
    }

    void traverse(struct tagLlink* llink)
    {
        llink->myLinkedList.traverse();
    }

#ifdef __cplusplus
};
#endif