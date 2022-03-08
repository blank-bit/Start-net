/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-01 14:02:54
 * @FilePath: /Start_net/Llink/llink.cpp
 * @Description:
 *********************************/

#include "llink.h"

MyLinkedList::MyLinkedList()
{
    head = new node(0);
    size = 0;
}

/*********************************
 * @function: getIndex
 * @description: 返回index节点的值
 * @param {int} index
 * @return {*}
 *********************************/
void *MyLinkedList::getIndex(int index)
{
    if (index < 0 || index > size - 1)
    {
        return nullptr;
    }

    node *cur = nullptr;
    cur = head->next;
    while (index--)
    {
        cur = cur->next;
    }

    return cur->val;
}

/*********************************
 * @function: getHead
 * @description: 返回头节点的值
 * @param {*}
 * @return {*}
 *********************************/
void *MyLinkedList::getHead(void)
{
    if (size > 0)
        return head->next->val;
    return nullptr;
}

/*********************************
 * @function: getTail
 * @description: 返回最后一个节点的值
 * @param {*}
 * @return {*}
 *********************************/
void *MyLinkedList::getTail(void)
{
    node *cur = nullptr;
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
 * @description: 头插
 * @param {void} *val
 * @return {*}
 *********************************/
void MyLinkedList::addAtHead(void *val)
{

    // int *v = new int(*(int *)val); //拷贝

    node *cur = new node(val);

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
 * @description: 尾插
 * @param {void} *val
 * @return {*}
 *********************************/
void MyLinkedList::addAtTail(void *val)
{
    // int *v = new int(*(int *)val); //深拷贝

    node *tail = nullptr;
    tail = head;

    int i = size;
    while (i--)
    {
        tail = tail->next;
    }

    node *cur = new node(val);
    tail->next = cur;
    cur->pre = tail;

    size++;
}

/*********************************
 * @function: addAtIndex
 * @description: 在第index个节点前插入
 * @param {int} index
 * @param {void} *val
 * @return {*}
 *********************************/
void MyLinkedList::addAtIndex(int index, void *val)
{
    // int *v = new int(*(int *)val); //深拷贝

    if (index > size)
    {
        return;
    }

    if (index < 0)
    {
        index = 0;
    };

    node *ptr = nullptr;
    ptr = head;

    while (index--)
    {
        ptr = ptr->next;
    }

    node *cur = new node(val);
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
 * @description: 删除第index个节点
 * @param {int} index
 * @return {*}
 *********************************/
void MyLinkedList::deleteAtIndex(int index)
{
    if (index < 0 || index > size - 1)
    {
        return;
    }

    node *ptr = nullptr;
    ptr = head;

    while (index--)
    {
        ptr = ptr->next;
    }

    node *cur = nullptr;
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
 * @description: 遍历输出节点值
 * @param {*}
 * @return {*}
 *********************************/
// void MyLinkedList::traverse(void)
//{
//     node *ptr = head;
//     while (ptr->next)
//     {
//         ptr = ptr->next;
//         std::cout << *(char **)(ptr->val) << std::endl;
//     }
// }

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
    node *ptr = head;
    while (ptr->next)
    {
        node *cur = ptr->next;
        ptr->next = cur->next;
        if (cur->next)
        {
            cur->next->pre = ptr;
        }
        delete (cur);
    }
    delete (head);
}