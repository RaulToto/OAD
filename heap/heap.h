#ifndef HEAP_H
#define HEAP_H
#include <iostream>
using namespace std;

class heap
{
public:
    heap();
    ~heap();
    int sizes();
    bool isEmpty();
    void enqueue(int value);
    int peek();
    int dequeue();
    void imprime();
private:
    int allocatedLength;
    int n;
    int *T;
    void grow();
    void bubbleUp(int childPos);
    void bubbleDown(int parentPos);
};

#endif // HEAP_H
