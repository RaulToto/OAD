#include <fstream>
#include <iostream>
#include <map>
#include <utility>
using namespace std;
typedef pair<int,int> letras;

/*int wordCount(string frase)
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
}*/
int getsize(string frase)
{
    return frase.length();
}
int main()
{   
    map<int,int >tam;  
    string frase ;//imprimir lineas
    //string result{};
    ifstream archivoEntrada;

    archivoEntrada.open("english_words.txt");
    int size=0;
    int i=1;
    int cont =0;
    if (archivoEntrada.is_open())
    {
        while(!archivoEntrada.eof())
        {
            getline(archivoEntrada,frase);
            size=getsize(frase);
            tam.insert(letras(i,size));
            //cout << frase << endl;
            i++;
            
        }
        archivoEntrada.close();
      
    }
    map<int,int>::iterator p=tam.begin();
    //int i=1;
    //map<int,int >tam2;
    int lista[25]={};
    while (p!=tam.end())
    {
        lista[p->second]++;
        p++;
    }    
    for(int i=1;i<25;i++)
    {
        cout << i  << "-----"<< lista[i] << endl;
    }    
    return 0;

}