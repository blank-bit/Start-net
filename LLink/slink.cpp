/*********************************
 * @Author: wang
 * @LastEditTime: 2022-02-28 13:54:08
 * @FilePath: \练习\link.cpp
 * @Description:
 *********************************/
#include <iostream>
using namespace std;
class MyLinkedList
{
public:
    struct node
    {
        int val;
        node *next;
        node(int x) : val(x), next(nullptr) {}
    };

    //构造函数
    MyLinkedList()
    {
        head = new node(0);
        size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index > size - 1)
        {
            return -1;
        }

        node *cur = nullptr;
        cur = head->next;
        while (index--)
        {
            cur = cur->next;
        }

        return cur->val;
    }

    void addAtHead(int val)
    {
        node *cur = new node(val);
        cur->next = head->next;
        head->next = cur;

        size++;
    }

    void addAtTail(int val)
    {
        node *tail = nullptr;
        tail = head;

        int i = size;
        while (i--)
        {
            tail = tail->next;
        }

        node *cur = new node(val);
        tail->next = cur;

        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
        {
            return;
        }

        if (index < 0)
        {
            // return addAtHead(val);
            index = 0;
        };

        // if (index == size)
        // {
        //     return addAtTail(val);
        // };

        node *ptr = nullptr;
        ptr = head;

        while (index--)
        {
            ptr = ptr->next;
        }

        node *cur = new node(val);
        cur->next = ptr->next;
        ptr->next = cur;

        size++;
    }

    void deleteAtIndex(int index)
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
        cur->next = nullptr;

        delete (cur);

        size--;
    }

private:
    int size;
    node *head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

// 0 // 1 2 3