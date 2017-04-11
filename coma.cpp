#include <iostream>
using namespace std;
void coma(string );

int main()
{
    string lista="10000000000";
    coma(lista);
}
void coma(string list)
{
    string tem=list;
   
    int cont=0,aumentar=1;
    for (int i = 0; i < list.length(); i++)
    {
        //tem  100,00000
        //list 1000000000
        if(cont==3)
        {
            cont=-1;
            
            tem[i]=',';
            
            /*for (int j = i+1; j < tem.length()+aumentar; j++)
            {
                tem[j]+list[j-1];
            }*/
            
        }
        cont++;
        aumentar++;
    }
    cout << "la lista es " << tem;
}