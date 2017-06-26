#include <string>
#include <iostream>
using namespace std;
string  traducir(string );
string swap(string ,string );
bool vocal(char );
int mayusculas(int c);
int main()
{
    string word;
    getline(cin,word);
    //cout << word;
    traducir(word);
}
string traducir(string a)
{
    
    string b,copia;
    int i=0;
    //string b[a.length()];
    //cout << a[0];
    if(vocal(a[0])!=false)
    {
        return "way"+a;
    }
    else 
    {
        while (vocal(a[i])==false)
        {
            b[i]=a[i];
            i++;
        }
    }
    //cout <<  "tem" << swap(copia,b);    
    
}
string swap(string a,string b)
{
    //"olahw" hw;
    string tem=a;
    int tam=a.length();
    for (int i = 0; i < b.length(); i++,tam--)
    {
        a[tam]=b[i];
        a[i]=tem[i];
    }
    return tem;
}

bool vocal(char a)
{
    bool retornar=false;
    char vocales[5]={'a','e','i','o','u'};
    
    for (int i = 0; i < 5; i++)
    {
       // cout << vocales[i];
        if (vocales[i]==a)
        {
            retornar=true;
        }
    } 
    return retornar;
}
