#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void leer(ifstream archivoEntrada)
{
    string frase;
    string fraseMayor;
    archivoEntrada.open("fichero.txt");
    getline(archivoEntrada,frase);
    fraseMayor=frase;
    
    if (archivoEntrada.is_open())
    {

        
        while(!archivoEntrada.eof())
        {
            getline(archivoEntrada,frase);   
            if (frase.length()> fraseMayor.length())
            {
                fraseMayor=frase;
            }
        }
        archivoEntrada.close();
    }
    archivoEntrada.close();
    cout << fraseMayor << endl;

}
int main()
{
    //crear un archivo
    ofstream archivo;
    archivo.open("fichero.txt");
    archivo << "hola mundo" << endl;
    archivo << "hello world" << endl;
    archivo << "this program is write in c++" << endl;
    archivo << "good bye" << endl;
  
    archivo.close();


    //----------------
    
    ifstream archivoEntrada;
    /*string frase;
    archivoEntrada.open("fichero.txt");
    
    if (archivoEntrada.is_open())
    {

        
        while(!archivoEntrada.eof())
        {
            getline(archivoEntrada,frase);
            
            cout << frase << endl;
        }
        archivoEntrada.close();
    }
    return 0;
  */
    string frase;
    string fraseMayor;
    archivoEntrada.open("fichero.txt");
    getline(archivoEntrada,frase);
    fraseMayor=frase;
    
    if (archivoEntrada.is_open())
    {

        
        while(!archivoEntrada.eof())
        {
            getline(archivoEntrada,frase);   
            if (frase.length()> fraseMayor.length())
            {
                fraseMayor=frase;
            }
        }
        archivoEntrada.close();
    }
    archivoEntrada.close();
    cout << fraseMayor << endl;
    
}