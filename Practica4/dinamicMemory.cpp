#include <iostream>
using namespace std;
int main()
{
    int b=5;
    int *a = new int;
    a=&b;
    cout << b << endl;
    cout << *a << endl;
}