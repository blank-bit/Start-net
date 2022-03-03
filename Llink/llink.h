/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-01 14:03:24
 * @FilePath: /Start_net/Llink/llink.h
 * @Description:
 *********************************/

#ifndef _LLINK_H
#define _LLINK_H

class MyLinkedList
{
public:
    struct node
    {
        void* val;
        node* pre;
        node* next;
        node(void* data) : val(data), next(nullptr), pre(nullptr) {}
    };

    MyLinkedList();

    void* getIndex(int index);
    void* getHead(void);
    void* getTail(void);
    void addAtHead(void* val);
    void addAtTail(void* val);
    void addAtIndex(int index, void* val);
    void deleteAtIndex(int index);
    int getSize(void);
    int isEmpty(void);
    void traverse(void);

    ~MyLinkedList();

private:
    int size;
    node* head;
};

#endif
