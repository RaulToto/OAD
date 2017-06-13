#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <node.h>
#include <iostream>
using namespace std;
template<typename T>

class LinkedList
{
public:
    LinkedList():firstPtr(nullptr),lastPtr(nullptr){}
    ~LinkedList()
    {
        if(!isEmpty())
        {
            Node<T> *temPtr;
            Node<T> *curPtr=firstPtr;
            while(curPtr!=nullptr)
            {
                temPtr=curPtr;
                curPtr=curPtr->nextPtr;
                delete temPtr;
            }
        }
    }
    void insertFisrt(T &val)
    {
        Node<T> *newPtr=getNewNode(val);

        if(isEmpty())
        {
            firstPtr=lastPtr=newPtr;
        }
        else
        {
            newPtr->nextPtr=firstPtr;
            firstPtr=newPtr;

        }
    }
    void insertLast(T &val)
    {
        Node<T> *newPtr=getNewNode(val);

        if(isEmpty())
        {
            firstPtr=lastPtr=newPtr;
        }
        else
        {
            lastPtr->nextPtr=newPtr;
            lastPtr=newPtr;

        }
    }
    bool removeFisrt()
    {
        Node<T> *temPtr=firstPtr;
        if(isEmpty())
        {
            cout << "esta vacia" << endl;
        }
        else
        {
            if(firstPtr==lastPtr)
            {
                firstPtr=lastPtr=nullptr;
            }
            else
                firstPtr=firstPtr->nextPtr;
            delete temPtr;
        }
    }
    bool removeLast()
    {
        Node<T> *temPtr=lastPtr;
        if(isEmpty())
            cout << "the list is empty" << endl;
        else
        {
            if(firstPtr==lastPtr)
                firstPtr=lastPtr=nullptr;
            else
            {
                Node<T> *curPtr=firstPtr;
                while(curPtr->nextPtr!=lastPtr)
                    curPtr=curPtr->nextPtr;
                lastPtr=curPtr;
                curPtr->nextPtr=nullptr;

            }
            delete temPtr;
        }
    }
    bool isEmpty()
    {
        return firstPtr==nullptr;
    }
    void print()
    {
        Node<T> *temPtr=firstPtr;
        while(temPtr!=nullptr)
        {
            cout << temPtr->data << "|";
            temPtr=temPtr->nextPtr;
        }
        cout << endl;
    }
    void sutter()
    {
        cout << "entra a shtter" << endl;
        Node<T> *temPtr=firstPtr;
        if(isEmpty())
        {
            cout << "lista vacia" << endl;
        }
        else
        {
            while(temPtr!=nullptr)
            {
                Node<T> *newPtr=getNewNode(temPtr->data);
                newPtr->nextPtr=temPtr->nextPtr;
                temPtr->nextPtr=newPtr;
                temPtr=temPtr->nextPtr->nextPtr;
            }
        }

    }

    void reorganizar()
    {
        Node<T> *temPtrFirst=firstPtr;
        Node<T> *temPtrLast=firstPtr->nextPtr->nextPtr;
        Node<T> *temPtrNegativeFirst=nullptr;
        while (temPtrLast!=nullptr) {
            if(temPtrFirst->nextPtr->data<0 )
            {
                cout << temPtrFirst->nextPtr->data << endl;
                if(temPtrNegativeFirst==nullptr)
                {
                    temPtrNegativeFirst=temPtrFirst->nextPtr;
                    if(firstPtr->data>0 and temPtrNegativeFirst!=nullptr and temPtrLast->nextPtr!=NULL)
                    {
                        temPtrFirst->nextPtr=temPtrLast;
                        temPtrNegativeFirst->nextPtr=firstPtr;
                        firstPtr=temPtrNegativeFirst;
                        temPtrLast=temPtrLast->nextPtr;
                        temPtrNegativeFirst=nullptr;
                    }
                    else if(firstPtr->data<0 and temPtrNegativeFirst!=nullptr and temPtrLast->nextPtr!=NULL)
                    {
                        temPtrFirst->nextPtr=temPtrLast;
                        temPtrNegativeFirst->nextPtr=firstPtr;
                        firstPtr=temPtrNegativeFirst;
                        temPtrLast=temPtrLast->nextPtr;
                        temPtrNegativeFirst=nullptr;
                        while(temPtrFirst->nextPtr->data<0)
                        {
                            //cout << "entra ala condicional" << endl;
                            temPtrNegativeFirst=temPtrFirst->nextPtr;
                            temPtrFirst->nextPtr=temPtrLast;
                            temPtrNegativeFirst->nextPtr=firstPtr;
                            firstPtr=temPtrNegativeFirst;
                            temPtrLast=temPtrLast->nextPtr;
                            temPtrNegativeFirst=nullptr;
                        }
                    }

                }//
                //pone un numero negativo al inicio de la lista
            }
            if(lastPtr->data<0 and temPtrLast==lastPtr)
            {
                cout << "entr¿" << endl;
                temPtrNegativeFirst=lastPtr;
                temPtrFirst->nextPtr->nextPtr=NULL;
                lastPtr=temPtrFirst->nextPtr;
                temPtrLast=temPtrFirst->nextPtr;
                temPtrNegativeFirst->nextPtr=firstPtr;
                firstPtr=temPtrNegativeFirst;
            }
            temPtrFirst=temPtrFirst->nextPtr;
            temPtrLast=temPtrLast->nextPtr;
        }
    }
    int contarDuplicado()
    {
        int cont=0;
        cout << "fuplicado" << endl;
        Node<T> *temPtr=firstPtr;
        Node<T> *temPtr1=firstPtr->nextPtr;
        while(temPtr1!=nullptr)
        {
            //temPtr1=temPtr1->nextPtr;
            if(temPtr->data==temPtr1->data)
            {
                cont++;
                //cout << temPtr->data << "----"<< temPtr1->data << endl;

            }
            //temPtr1=temPtr1->nextPtr;
            temPtr=temPtr1;
            temPtr1=temPtr1->nextPtr;
        }
        //cout << "hay --->" << cont << " duplicados" ;
        return cont;
    }




private:
    //pointer to first node
    Node<T> *firstPtr;
    //pointer to last node
    Node<T> *lastPtr;
    Node<T> *getNewNode(T &val)
    {
        return new Node<T>(val);
    }
};

#endif // LINKEDLIST_H
