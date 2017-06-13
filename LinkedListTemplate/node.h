#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
template<typename T> class LinkedList;
template<typename T>
class Node
{
    friend class LinkedList<T>;
public:
    Node(T &val):data(val),nextPtr(nullptr){}
    T getData()
    {
        return this->data;
    }

private:
    T data;
    Node<T> *nextPtr;

};

#endif // NODE_H
