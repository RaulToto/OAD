
Verificar si una cadena es Palindromo en C++

Un palíndromo (del griego palin dromein, volver a ir hacia atrás) es una palabra, número o frase que se lee igual hacia adelante que hacia atrás. Si se trata de un número, se llama capicúa. Habitualmente, las frases palindrómicas se resienten en su significado cuanto más largas son.

Esta pequeña aplicación nos permite saber si una palabra, frase o conjunto de números son aquellos denominados palíndromos o no.

La salida seria asi :
#include <iostream>
#include <string.h>
using namespace std;

bool esPalindromo(string cadena, int size){
    for(int i = 0; i < size/2; i++)
        if(cadena[i] != cadena[size-i-1]) 
            return false;
    return true;   
}
int main(){
    string cadena;
    cout << "Ingresa la cadena: ";
    getline(cin,cadena);    
    esPalindromo(cadena,cadena.length()) ? 
        cout << "\nEs palindromo \n" : cerr << "\nNo es palindromo \n";    
    cin.get();
    cin.get();
    return 0;    
}