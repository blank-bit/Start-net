/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-01 14:02:54
 * @FilePath: /Start_net/Llink/llink.cpp
 * @Description:
 *********************************/

#include <iostream>
#include "llink.h"

MyLinkedList::MyLinkedList()
{
    head = new node(0);
    size = 0;
}

/*********************************
 * @function: getIndex
 * @description: ����index�ڵ��ֵ
 * @param {int} index
 * @return {*}
 *********************************/
void* MyLinkedList::getIndex(int index)
{
    if (index < 0 || index > size - 1)
    {
        return nullptr;
    }

    node* cur = nullptr;
    cur = head->next;
    while (index--)
    {
        cur = cur->next;
    }

    return cur->val;
}

/*********************************
 * @function: getHead
 * @description: ����ͷ�ڵ��ֵ
 * @param {*}
 * @return {*}
 *********************************/
void* MyLinkedList::getHead(void)
{
    if (size > 0)
        return head->next->val;
}

/*********************************
 * @function: getTail
 * @description: �������һ���ڵ��ֵ
 * @param {*}
 * @return {*}
 *********************************/
void* MyLinkedList::getTail(void)
{
    node* cur = nullptr;
    cur = head;
    int i = size;

    while (i--)
    {
        cur = cur->next;
    }

    return cur->val;
}

/*********************************
 * @function: addAtHead
 * @description: ͷ��
 * @param {void} *val
 * @return {*}
 *********************************/
void MyLinkedList::addAtHead(void* val)
{

    // int *v = new int(*(int *)val); //����

    node* cur = new node(val);

    cur->next = head->next;
    cur->pre = head;
    head->next = cur;

    if (size > 0)
    {
        cur->next->pre = cur;
    }

    size++;
}

/*********************************
 * @function: addAtTail
 * @description: β��
 * @param {void} *val
 * @return {*}
 *********************************/
void MyLinkedList::addAtTail(void* val)
{
    // int *v = new int(*(int *)val); //���

    node* tail = nullptr;
    tail = head;

    int i = size;
    while (i--)
    {
        tail = tail->next;
    }

    node* cur = new node(val);
    tail->next = cur;
    cur->pre = tail;

    size++;
}

/*********************************
 * @function: addAtIndex
 * @description: �ڵ�index���ڵ�ǰ����
 * @param {int} index
 * @param {void} *val
 * @return {*}
 *********************************/
void MyLinkedList::addAtIndex(int index, void* val)
{
    // int *v = new int(*(int *)val); //���

    if (index > size)
    {
        return;
    }

    if (index < 0)
    {
        index = 0;
    };

    node* ptr = nullptr;
    ptr = head;

    while (index--)
    {
        ptr = ptr->next;
    }

    node* cur = new node(val);
    cur->next = ptr->next;
    ptr->next = cur;
    cur->pre = ptr;

    if (cur->next)
    {
        cur->next->pre = cur;
    }

    size++;
}

/*********************************
 * @function: deleteAtIndex
 * @description: ɾ����index���ڵ�
 * @param {int} index
 * @return {*}
 *********************************/
void MyLinkedList::deleteAtIndex(int index)
{
    if (index < 0 || index > size - 1)
    {
        return;
    }

    node* ptr = nullptr;
    ptr = head;

    while (index--)
    {
        ptr = ptr->next;
    }

    node* cur = nullptr;
    cur = ptr->next;
    ptr->next = cur->next;

    if (cur->next)
    {
        cur->next->pre = ptr;
        cur->next = nullptr;
    }

    delete (cur);

    size--;
}

/*********************************
 * @function: traverse
 * @description: ��������ڵ�ֵ
 * @param {*}
 * @return {*}
 *********************************/
void MyLinkedList::traverse(void)
{
    node* ptr = head;
    while (ptr->next)
    {
        ptr = ptr->next;
        std::cout << *(char**)(ptr->val) << std::endl;
    }
}

int MyLinkedList::getSize(void)
{
    return size;
}

int MyLinkedList::isEmpty(void)
{
    return head->next ? 0 : 1;
}

MyLinkedList::~MyLinkedList()
{
    node* ptr = head;
    while (ptr->next)
    {
        node* cur = ptr->next;
        ptr->next = cur->next;
        if (cur->next)
        {
            cur->next->pre = ptr;
        }
        delete (cur);
    }
    delete (head);
}