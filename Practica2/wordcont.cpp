#include <fstream>
#include <iostream>
using namespace std;
typedef pair<int,int> letras;
int getsize(string frase)//funcion que retorna el tamaño
{
    return frase.length();
}
int main()
{    
    int lista[25]={};
    string frase ;
    ifstream archivoEntrada;
    archivoEntrada.open("english_words.txt");
    int size=0;
    if (archivoEntrada.is_open())
    {
        while(!archivoEntrada.eof())
        {
            getline(archivoEntrada,frase);//lee la linea del archivo
            size=getsize(frase);//almacena el tamaño de la frase
            lista[size]++;  //aumeta 1 en la posicion size de la lista
        }
        archivoEntrada.close(); //cierra el archivo
    }
    for(int i=1;i<25;i++)
    {
        cout << i  << "-----> "<< lista[i] << endl;//imprime la lista
    }    
    return 0;

}