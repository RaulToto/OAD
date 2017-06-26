#include <iostream>
#include <tree.h>
#include <node.h>
#include <tree.cpp>
using namespace std;
int main()
{
    Tree<int> *tree= new Tree<int>();
    //int input;
    tree->insertNode(5);
    tree->insertNode(3);
    tree->insertNode(8);
    tree->insertNode(1);
    tree->insertNode(4);
    tree->insertNode(6);
    tree->insertNode(9);
    tree->insertNode(0);
    tree->insertNode(2);
    tree->insertNode(7);
    tree->insertNode(10);


    //tree->getVal(a);
    //cout << "is " << tree->getVal(a);
    //cout << tree;


    //cout << "preorder" << endl;
    //tree->preOrderTraversal();
    //cout << "inorder" << endl;
    //tree->inOrderTraversal();
    //cout << "postOrder " << endl;
    tree->postOrderTraversal();
    tree->printNivelByNivel();
    //cout <<tre ;
}
