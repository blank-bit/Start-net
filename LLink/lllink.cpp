/*********************************
 * @Author: wang
 * @LastEditTime: 2022-02-28 13:54:08
 * @FilePath: \练习\link.cpp
 * @Description:
 *********************************/
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <string>

using namespace std;

class MyLinkedList
{
public:
    struct node
    {
        void *val;
        node *pre;
        node *next;
        node(void *data) : val(data), next(nullptr), pre(nullptr) {}
    };

    MyLinkedList()
    {
        head = new node(0);
        size = 0;
    }

    void *get(int index)
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

    void addAtHead(void *val)
    {
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

    void addAtTail(void *val)
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
        cur->pre = tail;

        size++;
    }

    void addAtIndex(int index, void *val)
    {
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

        if (cur->next)
        {
            cur->next->pre = ptr;
        }

        cur->next = nullptr;

        delete (cur);

        size--;
    }

    void Traverse()
    {
        node *ptr;
    }

    // ~MyLinkedList()
    // {
    //     node *ptr = head;
    //     while (ptr->next)
    //     {
    //         node *cur = ptr->next;
    //         ptr->next = cur->next;
    //         if (cur->next)
    //         {
    //             cur->next->pre = ptr;
    //         }
    //         delete (cur);
    //     }
    //     delete (head);
    // }

private:
    int size;
    node *head;
};

typedef struct
{
    string name;
    int age;
} data;

int main()
{
    MyLinkedList myLinkedList;
    int i = 7;
    myLinkedList.addAtHead(&i);
    cout << *(int *)myLinkedList.get(0) << endl;

    data s;
    s.age = 12;
    s.name = "hsu";

    myLinkedList.addAtHead(&s);

    data t = *(data *)myLinkedList.get(0);
    cout << "age:" << t.age << "\tname:" << t.name << endl;

    _CrtDumpMemoryLeaks();
}