/*//////////////////////////////////////////////////////
///  *@file Tree.cpp                                 ///
///   * @version 1.0                                 ///
///    * @date 15/06/2017                            ///
///     * @author Raul Edgar Quispe Totocayo         ///
///                                                  ///
///       * @                                        ///
//////////////////////////////////////////////////////*/

#include <tree.h>
#include <iostream>
#include "node.h"

template<typename T>
void Tree<T>::remove(Node<T> *ptr)
{
    if(ptr == NULL)
        return;	// Nothing to do

    Node<T>* left = ptr->leftPtr;
    Node<T>* right = ptr->reightPtr;

    delete ptr;
    remove(left);
    remove(right);

}
template<typename T>
void Tree<T>::insertNodeHelper(Node<T> **ptr, T &val)
{
    if(*ptr==nullptr)
    {
        //create a new node
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
                cout << "duplicado" << endl;
        }
    }
}
template<typename T>
void Tree<T>::preOrderHelper(Node<T> *ptr)
{
    if(ptr)
    {
        std::cout << "--->" <<ptr->data<<std::endl;
        preOrderHelper(ptr->leftPtr);
        preOrderHelper(ptr->reightPtr);
    }
}
template<typename T>
void Tree<T>::inOrderHelper(Node<T> *ptr)
{
    if(ptr)
    {
        inOrderHelper(ptr->leftPtr);
        std::cout << "inorder " << ptr->data << std::endl;
        inOrderHelper(ptr->reightPtr);

    }
}
template<typename T>
void Tree<T>::postOrderHelper(Node<T> *ptr,int i)
{
    if(ptr)
    {
        i++;
        postOrderHelper(ptr->leftPtr,i);
        postOrderHelper(ptr->reightPtr,i);
        std::cout <<"dato--> "<< ptr->getData() << " Nivel --> " << i<< std::endl;

    }

}
template<typename T>
bool Tree<T>::getValHelper(Node<T> **ptr, T &val)
{
    while(*ptr)
    {
        if((*ptr)->data==val)
        {
            return true;
        }
        if((*ptr)->leftPtr->getData()<val)
        {
            ptr=&(*ptr)->leftPtr;
        }
        else if((*ptr)->reightPtr->getData()<val)
        {
            ptr=&(*ptr)->reightPtr;
        }
    }
    return false;
}
template<typename T>
void Tree<T>::printHelper(Node<T> *ptr)
{
    std::unordered_map<int, std::vector<Node<T>*> > m;
    printBinaryTree (ptr, m, 0);
    for ( auto& i : m )
    {
      std::cout << "Nivel " << i.first << ": ";
      for ( auto& j : i.second )
        std::cout << j->data << "  ";
    }
    std::cout << std::endl;
}
/*
template<typename T>
void Tree<T>::printHelper(Node<T> *ptr)
{
    LinkedList *ptr1=ptr;
    LinkedList *ptr2=ptr;
    while((ptr1 or ptr2)!=nullptr)
    {

    }
}*/
template<typename T>
void Tree<T>::lenghtHelper(Node<T> *ptr)
{
    int lenght=0;
    std::unordered_map<int, std::vector<Node<T>*> > m;
    printBinaryTree (ptr, m, 0);
    for ( auto& i : m )
    {
        lenght++;
      for ( auto& j : i.second ){}
        //std::cout << j->data << "  ";
    }
    //std::cout << std::endl;
    std::cout << lenght << std::endl;
}
// print a binary tree level by level
template <typename T>
void printBinaryTree (Node<T>* ptr, std::unordered_map<int, std::vector<Node<T>*> >& m, int level )
{
  if (ptr)
  {
    ++level;
    printBinaryTree ( ptr->getLeftPtr() ,m,level);
    printBinaryTree ( ptr->getReightPtr(),m,level);

    m[level].push_back(ptr);
  }
}
