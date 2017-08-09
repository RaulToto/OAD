#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;
int suma(vector<int> vec)
{
    int resultado=0;
    for (size_t i = 0; i < vec.size(); i++)
    {
        resultado+=vec[i] ;
    }
    return resultado;
}
void lanzarExepcion()
{
    try
    {
        
    }
    catch (const std::exception&)
    {
        
    }
}
int main()
{
    vector<int> v;
    cout << "ingrese un numero entero entre -100 y 100" << endl;
    int a ;
    while(true)
    {
        
    }
    cout << "la suma es" << suma(v);
}