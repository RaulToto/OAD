//GENERACION DE COMBINACIONES
//Autor:Raul Edgar Quispe Totocayo
#include <iostream>
using namespace std;
//funcion para hallar el factorial de un numero
int factorial(int n)
{
    if (n<=1)
        return 1;
    else
        return n*factorial(n-1);
}
//funcion que imprime la lista
void imprimer(int lista[],int r)
{
    for(int i=0;i<r;i++)
    {
        cout << lista[i] << " ";
    }
}
//funcion que calcula el numero de combinaciones de r
int combinatoria(int n,int r)
{
    return factorial(n)/(factorial(n-r)*factorial(r));
}
//funcion GENERACION DE COMBINACIONES
int combinacion(int r,int n)
{
    int lista[r]={};
    for(int i=0;i<r;i++)
    {
        lista[i]=i+1;
    }
    imprimer(lista,r);
    cout << endl;
    for(int i=1;i<combinatoria(n,r);i++)
    {
        int m=r-1;//se le resta 1 al r ya que en el arreglo comiensa desde el subindice 0
        int val_max=n;
        while(lista[m]==val_max)
        {
            m=m-1;
            val_max=val_max-1;
        }
        lista[m]=lista[m]+1;
        for(int j=m+1;j<r;j++)
        {
            lista[j]=lista[j-1]+1;
        }
        imprimer(lista,r);
        cout << endl;
    }
}

int main()
{
    int n,r;
    cout << "ingrese n " << endl;
    cin >> n;
    cout << "ingrese r " << endl;
    cin >> r;
    combinacion(r,n);
    //cout << combinatoria(n,r) << endl;
}