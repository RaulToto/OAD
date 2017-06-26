#include <iostream>
using namespace std;

int main()
{
    int lista[23]={10,10,20,20,20,30,40,40,40,40,40,50,50,60,60,70,70,70,70,70,70,80,80};
    cout << "Grade distribution:" << endl;

   // for each element of array n, output a bar of the chart
   for(int i = 0; i < 23; i++)
   {
       cout << lista[i] << "---";
       for (int j = 0; j <23; j++)
       {

           if(lista[i]==lista[j])
           {
                cout << "*";
           }
       }
       
       cout << endl;
       
   }
}
