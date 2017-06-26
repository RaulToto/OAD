#include <iostream>
#include <fstream>
#include <string>
//#define SENTINEL  ""
using namespace std;
int wordCount(string frase)
{
    int wordCount=0;
    for(int i=0;i<frase.length();i++)
    {
        if(frase[i]==' ')
        {
            wordCount++;
        }
    }
    return wordCount;
}

void readFile(string fileName)
{

}

int main()
{
    //leer();
    //--------------------------------------------------------------
    ifstream archivoEntrada;
    string frase;
    archivoEntrada.open("leerArchivo.txt");
    //archivoEntrada.close();
    //leer archivo
    int wordC=0;
    int lineCount=0;
    int charC=0;
    if (archivoEntrada.is_open())
    {
        while(!archivoEntrada.eof())
        {
            getline(archivoEntrada,frase);
            lineCount++;
  //          cout << "linea 1" << wordCount(frase);
            wordC+=wordCount(frase);
            charC+=frase.length();
        }
        archivoEntrada.close();
    }
       
    cout << "wordCount " << wordC << endl;
    cout <<"lineCount " << lineCount << endl;
    cout << "charCount " << charC << endl;
 
}
