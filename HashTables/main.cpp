#include <iostream>
#include <linkedlist.h>
using namespace std;
int main()
{
    HashMap hash;
    //hash.mostrar();
    hash.put(2,3);
    hash.put(2,5);
    hash.put(2,4);
    hash.put(2,6);
    hash.put(2,6);

    hash.put(130,4);
    cout << hash << endl;
    hash.remove(2);
    cout << hash << endl;
}
