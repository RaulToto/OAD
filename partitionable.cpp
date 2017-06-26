#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int mayor(vector<int>& vec)
{
    int mayor=vec[0];
    for (int i = 0; i < vec.size(); i++)
    {
        if(mayor<vec[i])
            mayor=vec[i];
    }
    return mayor;
}
int menor(vector<int> & vec)
{
    int menor=vec[0];
    for (int i = 0; i < vec.size(); i++)
    {
        if(menor>vec[i])
            menor=vec[i];
    }
    return menor;
}
void deleteElement(int n,vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if(n==vec[i])
        {
            //cout << "delete " << vec[i] << endl;
            vec.erase(vec.begin()+i);     
        }
    }
}
bool findElement(int n,vector<int> &vec)
{
    int a=0;
    for (int i = 0; i < vec.size(); i++)
    {
        if(n==vec[i])
            a=1;
    }
    if(a==0)
        return false;
    else 
        return true;

}
void  partitionable(vector<int>&vec)
{
    vector<int> vec2;
    int totalSumElements,totalSumElementsVec2;//variable para almacenar la suma de los elementos del ventor
    totalSumElements=accumulate(vec.begin(),vec.end(),0);//suma todos los elementos del vector
    //totalSumElements=totalSumElements/2;
    if(totalSumElements%2==1)
        cout << "no es particionable"<< endl;//return false;
    else if(mayor(vec)>(totalSumElements)/2)//si el mayor numero del vector es mayor que la totalSumElements entonces es falso
        cout << "no es particionable"<< endl;//return false;
    else if(mayor(vec)==(totalSumElements)/2)//si
        cout << "si es particionable"<< endl;//return true;
    else
    {
        vec2.push_back(mayor(vec));
        cout << "agrega el mayor" <<mayor(vec) << endl;
        deleteElement(mayor(vec),vec);
        while(accumulate(vec2.begin(),vec2.end(),0)<=(totalSumElements)/2)
        {
            totalSumElementsVec2=accumulate(vec2.begin(),vec2.end(),0);
            cout << "busca" << totalSumElements/2-totalSumElementsVec2 << endl;
            if(findElement((totalSumElements/2-totalSumElementsVec2),vec)==true)
            {
                cout << "agregar cuando es mayor" << totalSumElements/2-totalSumElementsVec2 << endl;
                vec2.push_back(totalSumElements/2-totalSumElementsVec2);
                deleteElement(totalSumElements/2-totalSumElementsVec2,vec);
                break;      
            }
            else
            {
                cout << "agregar cuando es menor" << menor(vec) << endl;
                vec2.push_back(menor(vec));
                deleteElement(menor(vec),vec);
            }
                
        }
        /*
        if(accumulate(vec.begin(),vec.end(),0)==accumulate(vec2.begin(),vec2.end(),0))
        {
            return true;
        }
        else
            return false;
            */
    }
    //return totalSumElem
    cout << "vector1"<< endl;
    for (int i = 0; i < vec.size(); i++){cout << vec[i] << endl;}
    cout << "vector2" << endl;
    for (int i = 0; i < vec2.size(); i++){cout << vec2[i] << endl;}

}
int main()
{
 int a,tam;
    cout << "ingrese el tamaño " ; cin >> tam;
    vector<int>vec;
    while(tam>0)
    {
        cout << "ingrese el numero "; cin >> a;
        vec.push_back(a);
        tam--;
    }
    partitionable(vec);
    //cout << mayor(vec) << endl;
    //cout << menor(vec) << endl;
    //cout << "suma total de los elementos del vector " << partitionable(vec) << endl;
}
