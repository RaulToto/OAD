#include <iostream>
#include <NTL/ZZ.h>
#include <vector>
using namespace std;
using namespace NTL;
int main()
{
	ZZ input;
	cin>> input;
	ZZ a=conv<ZZ>(1000000000000);
	for(ZZ i=conv<ZZ>(0);i<input;i+=a)
	{
		cout << i << endl;
	}
}
