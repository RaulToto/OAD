#include "linkedlist.h"
#include <iostream>
using namespace std;
LinkedList concatenate(LinkedList lista1 , LinkedList lista2)
{
    lista1.lastPtr->nextPtr=lista2.firstPtr;
    return lista1;
}

int main()
{
    LinkedList lista;
    lista.insertFirst(8);
    //lista.insertFirst(4);
    lista.insertLast(-8);
    lista.insertLast(3);
    lista.insertLast(6);
    lista.insertLast(19);
    lista.insertLast(0);
    lista.insertLast(43);
    lista.insertLast(-10);
    lista.insertLast(-7);
    lista.insertLast(-2);
    lista.insertLast(-10);
    lista.insertLast(7);
    lista.insertLast(-2);

    cout << "la lista sin organisar" << endl;
    //lista.printList(lista);

    lista.reorganizar();
    //cout << "lista organizada" << endl;
    lista.printList(lista);

    //lista.removeLast();
    //lista.sutter();
    //lista.reorganizar() ;
    //lista.contarDuplicado();
}
