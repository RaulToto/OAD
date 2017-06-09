#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
class Node
{
    friend class LinkedList;
public:
    Node(int & val):data(val),nextPtr(NULL){}
    int getData(){return this->data;}


    int data;
    Node *nextPtr;
};
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void insertFirst( int );
    void insertLast( int );
    bool removeFirst();
    bool removeLast();
    void printList(LinkedList );
    bool isEmpty();
    void sutter();
    void reorganizar();
    int contarDuplicado();


    //LinkedList concatenate(LinkedList ,LinkedList);

private:
    Node *firstPtr;
    Node *lastPtr;
    Node *getNewNode(int &);
    friend LinkedList concatenate(LinkedList , LinkedList );
};


#endif // LINKEDLIST_H
