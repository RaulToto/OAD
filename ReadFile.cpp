#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    string filename;
    cout << "imput filename" << endl;
    cin >> filename;
    ifstream archivoDeEntrada;
    archivoDeEntrada.open(filename);
}