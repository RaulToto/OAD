#include <iostream>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef pair<string,int> str;//create a pair

void printAsterisk(int n)//imprimer los asteriscos
{
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
}

int main()
{
    map<string,int>str_num;//crea map  str_num
    string input,str_add {};//variables input para ingresar por teclado y str_add para agregar al mapa
    cout << "imput !" << endl;
    getline(cin,input);//ingresa por teclado
    map<string,int>::iterator p=str_num.begin();//iterator para 
    int k=0;
    for (int i = 0; i < input.length()+2; i++)
    {
        if(input[i]!=' ')//cuando hay espacio en el strn  de entrada
        {
            str_add.push_back(input[i]);//agraga a str_add
            if(i==input.length()-1)
                k=1;
        }
        else
        {
            k=1;//si hay espacio inicializa k=1
        }

        //cout << str_add << endl;
        while(k==1)//si k==1
        {
            if(p->first==str_add)//si el primer elemento del mapa es == a str_add aumenta en 1  el p->second
            {
                p->second++;
            }
            else
            {
               str_num.insert(str(str_add,1));//insert el nuevo str_add y inicializa con 1 p->second

                p++;//aumenta el puntero iterator
            }
            str_add.clear();//limpia str add 
            k=0;//incializa con k con 0
        }    
    }
   //imprime los asteriscos
    map<string,int>::iterator p1=str_num.begin();//inicaliza iterator p1 con begin
    while (p1!=str_num.end())
    {
        cout << p1->first  << ":";
        printAsterisk(p1->second);//llama a la funcion printasterisk
        p1++;//vanza p1
        cout << endl;
    }
}
