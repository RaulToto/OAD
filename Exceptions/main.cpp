#include "exceptionsum.h"
#include "range.h"
#include "exceptionintlegal.h"
#include <cmath>
#include <typeinfo>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//int maxInt = 1<<16 -1;

void calcularCuadrado(vector<int> &vec)
{
    int resultado=0,j=0;
    for (int i = 0; i < vec.size(); ++i) {
        try
        {
            if(vec[i]>100 or vec[i]<-100)
            {
                throw Range();
                j=1;
            }
        }
        catch(Range &exp)
        {
            cout << "ocurrio una exepcion" << exp.what() << endl;
        }

        resultado+=vec[i]*vec[i];
    }
    try{
        if(resultado>maxInt)
            throw ExceptionSum();
    }
    catch(ExceptionSum &sum)
    {
        cout << "ocurrio una  excepcion" << sum.what() << endl;
    }
    if(j==1)
        cout << "resultado es " << resultado << endl;
}
/*int main()
{
    int b;
    float a=0,resultado;
    cout << "ingrese un numero en el rango de -100 a 100" ;
    vector<int> v;

    while(cin>> a )
    {
        try{
            a=b;
            if(a-b!=0)
                throw ExceptionIntLegal();
        }
        catch(ExceptionIntLegal &ex)
        {
            cout << "ocurrio una excepcion" << ex.what();
        }

        v.push_back(a);
    }
    calcularCuadrado(v);
}*/
void leeNombreArch(char n)
{
    if(n)
    ifstream leer;
    string frase;
    leer.open("hola.txt");
    getline(leer,frase);
    else
        return;

}

void abreArch()
{
    
    if(n)
    ifstream leer;
    string frase;
    leer.open("hola.txt");
    getline(leer,frase);
    else
        return;
    
}

void cargaArch()
{
    
    if(n)
    ifstream leer;
    string frase;
    leer.open("hola.txt");
    getline(leer,frase);
    else
        return;
    
}

void cierraArch()
{

}

void crear()
{
    if()
    {
        ofstream archivo;
        //string line = "\\\\hline";
        archivo.open("hola.txt",ios::app);
        archivo << endl;
        archivo.close();

    }
    else
        return;
}
int nombreExc = 1;
int archExc = 2;
int cargaExc = 3;
int cierraExc  = 4;
int leeArch = 5;
int IntentaLeer = 6;

void leeArchivo ( int v [] ) {
    char *n;
    int cod;
    FILE *p;

    try{
        if(!leeNombreArch( n ))
            throw nombreExc;
    }
    catch(int nombreExc){
        cerr << "nombre inv";
        throw leeArch;
    }

    try{
        if(!abreArch(n, p))
            throw IntentaLeer;
    }
    catch(int archExc){
        cerr << "archivo inexistente";
        throw IntentaLeer ;
    }

    try{
        if(!cierraArch (p))
            throw cierraExc;
    }
    catch(int cierraExc){
        cerr << "archivo inexistente";
        throw IntentaLeer ;
    }

}

void intentaLeer (int v [ ] ) {
    int cod;
    do {
        cod = leeArchivo(v);
        if (cod == -1) {
            if ( !continua ( ) )
            return cod;
        } else {
            return cod;
        }
    } while (1);
}

main ( ) {
    int cod;
    int vec [100];
    cod = intentaLeer (vec);
    switch (cod) {
    case 0: break;
    case -1: printf ("error de nombre");
        break;
    case -2: printf ("error de carga");
        break;
    case -3: printf("error de cierre");
    };
    ordena (vec);
    imprime (vec);
}
