#include <iostream>
#include "heap.h"
using namespace std;

int main()
{

    cout<<"heap"<<endl;
    heap H;
    H.enqueue(18);
    H.enqueue(25);
    H.enqueue(41);
    H.enqueue(34);
    H.enqueue(14);
    H.enqueue(10);
    H.enqueue(52);
    H.enqueue(50);
    H.enqueue(48);

    cout<<"Tamaño: "<<H.sizes()<<endl;
    H.imprime();
    H.dequeue();
    cout<<endl;
    H.imprime();
    return 0;
}
