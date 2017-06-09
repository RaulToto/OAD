#include "linkedlist.h"
using namespace std;
LinkedList::LinkedList()
    :firstPtr(nullptr),lastPtr(nullptr)
{

}

LinkedList::~LinkedList()
{
    if(!isEmpty())
    {
        //cout << "destruyendo nodos" << endl;
        Node *temPtr;
        Node *curPtr=firstPtr;
        while(curPtr!=nullptr)
        {
            temPtr=curPtr;
            curPtr=curPtr->nextPtr;
            delete temPtr;
        }
    }
    //cout << "destroy every nodes" << endl;
}

void LinkedList::insertFirst( int  val)
{
    Node *newPtr=getNewNode(val);

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
void LinkedList::insertLast(int val)
{
    Node *newPtr=getNewNode(val);

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

bool LinkedList::removeFirst()
{
    Node *temPtr=firstPtr;
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

bool LinkedList::removeLast()
{
    Node *temPtr=lastPtr;
    if(isEmpty())
        cout << "the list is empty" << endl;
    else
    {
        if(firstPtr==lastPtr)
            firstPtr=lastPtr=nullptr;
        else
        {
            Node *curPtr=firstPtr;
            while(curPtr->nextPtr!=lastPtr)
                curPtr=curPtr->nextPtr;
            lastPtr=curPtr;
            curPtr->nextPtr=nullptr;

        }
        delete temPtr;
    }
}

void LinkedList::printList(LinkedList list)
{
    Node *temPtr=list.firstPtr;
    while(temPtr!=nullptr)
    {
        cout << temPtr->data << "|";
        temPtr=temPtr->nextPtr;
    }
    cout << endl;
}

bool LinkedList::isEmpty()
{
    return firstPtr==nullptr;
}

void LinkedList::sutter()
{
    cout << "entra a shtter" << endl;
    Node *temPtr=firstPtr;
    if(isEmpty())
    {
        cout << "lista vacia" << endl;
    }
    else
    {
        while(temPtr!=nullptr)
        {
            Node *newPtr=getNewNode(temPtr->data);
            newPtr->nextPtr=temPtr->nextPtr;
            temPtr->nextPtr=newPtr;
            temPtr=temPtr->nextPtr->nextPtr;
        }
    }
}

void LinkedList::reorganizar()
{
    Node *temPtrFirst=firstPtr;
    Node *temPtrLast=firstPtr->nextPtr->nextPtr;
    Node *temPtrNegativeFirst=nullptr;
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

int LinkedList::contarDuplicado()
{
    int cont=0;
    cout << "fuplicado" << endl;
    Node *temPtr=firstPtr;
    Node *temPtr1=firstPtr->nextPtr;
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



Node *LinkedList::getNewNode(int & val)
{
    return new Node(val);
}
