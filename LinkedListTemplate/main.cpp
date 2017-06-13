#include <iostream>
#include <node.h>
#include <linkedlist.h>
using namespace std;
int main()
{
    cout << "  /////////////////////////////"<< endl;
    cout << " ///Create a int LinkedList///" << endl;
    cout << "/////////////////////////////" << endl;
    LinkedList<int> list;
    int a,b;
    while(true)
    {

        cout << "+++++++++++++++++++++++++++++++++" <<endl;
        cout << "|input 1: for insert at front   |" << endl;
        cout << "|input 2: for insert at back    |" << endl;
        cout << "|input 3: for shutter           |" << endl;
        cout << "|input 4: organize linkedList   |" << endl;
        cout << "|input 5: print linkedList      |" << endl;
        cout << "|if you exit press ctrl+z       |" << endl;
        cout << "+++++++++++++++++++++++++++++++++" << endl;
        cout << "?";cin>> a;
        if(a==1)
        {
            cout <<"input number";cin >> b;
            list.insertFisrt(b);

        }
        else if(a==2)
        {
            cout <<"input number";cin >> b;
            list.insertLast(b);
        }
        else if(a==3)
        {
            list.sutter();
        }
        else if(a==4)
        {
            list.reorganizar();
        }
        else if(a==5)
        {
            cout << "the linkedList-->" ;
            list.print();
        }

    }
    //lista.insertFirst(4);

    //cout << "la lista sin organisar" << endl;
    //lista.printList(lista);

    //lista.reorganizar();
    //cout << "lista organizada" << endl;
    //lista.printList(lista);

    //lista.removeLast();
    //lista.sutter();
    //lista.reorganizar() ;
    //lista.contarDuplicado();
}

