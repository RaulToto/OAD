/**
  * @file main.cpp
  * @version 1.0
  * @date 19/04/17
  * @author Raul Edgar Quispe Totocayo
  * @title main
  */

#include <iostream>
#include <string>
#include <map>//libreria para map
#include <utility>//libreria para para pair
#include <iomanip>
using namespace std;
typedef pair<string,double> venta_dia;
int main()
{
    map<string,double >semana;
    semana.insert(venta_dia("monday",300.65) );
    semana.insert(venta_dia("thursday",390.15) );
    semana.insert(venta_dia("wednesday",500.23) );
    double total=0;
    map<string,double>::iterator p=semana.begin();
    while (p!=semana.end())
    {
        cout << p->first << "------"  << p->second << endl;
        total+=p->second;
        p++;
    }
    cout << "total->>" << total;
    return 0;

}