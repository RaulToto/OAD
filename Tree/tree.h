/*//////////////////////////////////////////////////////
///  *@file Node.h                                   ///
///   * @version 1.0                                 ///
///    * @date 15/06/2017                            ///
///     * @author Raul Edgar Quispe Totocayo         ///
///                                                  ///
///       * @brief this program using the libntl     ///
//////////////////////////////////////////////////////*/

#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <node.h>
using namespace std;
template<typename T>

class Tree
{
public:
    Tree()
        :rootPtr(nullptr){}
    void insertNode(T &val)
    {
        insertNodeHelper(&rootPtr,val);
    }

    friend std::ostream& operator <<(std::ostream &out,Tree<T> &tre)
    {
        out << tre.rootPtr->getData()<< endl;
        Node<T> *temPtr=tre.rootPtr;
        temPtr=temPtr->getReightPtr();

        cout << temPtr->getData()<< endl;

        //Node<T> *temLeftPtr=tre.rootPtr->leftPtr;
        //Node<T> *temReightPtr=tre.rootPtr->reightPtr;
        /*while((temLeftPtr != nullptr )or (temReightPtr != nullptr) )
        {
            cout << temLeftPtr->data << "---" << temReightPtr->data << endl;
            temLeftPtr=temLeftPtr->leftPtr;
            temReightPtr=temReightPtr->reightPtr;
        }*/
    }
private:
    Node<T> *rootPtr;
    void insertNodeHelper(Node<T> **ptr,T &val)
    {
        if(*ptr==nullptr)
        {
            *ptr=new Node<T>(val);
        }
        else
        {
            if(val<(*ptr)->data)
            {
                insertNodeHelper(&((*ptr)->leftPtr),val);
            }

            else
            {
                if(val>(*ptr)->data)
                    insertNodeHelper(&((*ptr)->reightPtr),val);
                else
                    cout << "nub" << endl;
            }
        }
    }
};

#endif // TREE_H
