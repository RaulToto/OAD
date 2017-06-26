#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include "tree.h"
template<typename T>

class LinkedList
{
public:
    LinkedList():nexPtr(nullptr){}
    Node<T> * getNextPtr()
    {
        return nexPtr;

    }

private:
    Node<T> *nexPtr;

};

#endif // LINKEDLIST_H
