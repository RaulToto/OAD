#include <iostream>
#include <tree.h>
#include <node.h>
using namespace std;
int main()
{
    Tree<int> tre;
    int a=4,b=5,c=100;

    tre.insertNode(a);
    tre.insertNode(b);
    tre.insertNode(c);
    cout <<tre ;
}
