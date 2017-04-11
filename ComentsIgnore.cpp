#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void removeComents(istream & is,ostream & os)
{

    ifstream archivoEntrada;
    string frase;
    archivoEntrada.open("copy.txt");
    if(archivoEntrada.is_open())
    {
        while (!archivoEntrada.eof())
        {
            getline(archivoEntrada,frase);
            for (int i = 0; i < frase.length(); i++)
            {
                if(frase[0]!='/' and frase[1]!='/' and frase[frase.length()-1]!='/')
                {
                    cout << frase  << endl;
                    i=frase.length()-1;
                }
            }
            
        }
        archivoEntrada.close();
    }
}
int main()
{
     //crear un archivo
    ofstream archivo;
    archivo.open("copy.txt");
    archivo << "//hola mundo" << endl;
    archivo << "/*hello world" << endl;
    archivo << "this program is write in c++*/" << endl;
    archivo << "good bye" << endl;
    //close 
    archivo.close();

    //abrir  un archivo
    
    ifstream archivoEntrada;
    string frase;
    archivoEntrada.open("copy.txt");
    if(archivoEntrada.is_open())
    {
        while (!archivoEntrada.eof())
        {
            getline(archivoEntrada,frase);
            for (int i = 0; i < frase.length(); i++)
            {
                if(frase[0]!='/' and frase[1]!='/' and frase[frase.length()-1]!='/')
                {
                    cout << frase  << endl;
                    i=frase.length()-1;
                }
            }
            
        }
        archivoEntrada.close();
    }
}