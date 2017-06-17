/*//////////////////////////////////////////////////////
///  *@file Node.h                                   ///
///   * @version 1.0                                 ///
///    * @date 15/06/2017                            ///
///     * @author Raul Edgar Quispe Totocayo         ///
///                                                  ///
///       * @brief this program using the libntl     ///
//////////////////////////////////////////////////////*/

#ifndef NODE_H
#define NODE_H
#include <iostream>
//declaration tree with template
template <typename T> class Tree;
//declaration class node with templates
template <typename T>

class Node
{
    //class tree is fried from class Node
    friend class Tree<T>;
public:
    Node(T &dd)
        :data(dd),leftPtr(nullptr),reightPtr(nullptr){}
    T getData()
    {
        return this->data;
    }
    Node<T> *getLeftPtr()
    {
        return this->leftPtr;
    }
    Node<T> *getReightPtr()
    {
        return this->reightPtr;
    }

private:
    T data;
    Node<T> *leftPtr;
    Node<T> *reightPtr;
};

#endif // NODE_H
