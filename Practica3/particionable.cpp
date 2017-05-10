#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int mayor(vector<int> &vec)//devuelve el numero mayor dle vector y tambien lo elimina
{
    int mayor=vec[0],i=0,j=0;//asumiendo que el mayor esta en la primera posicion 
    while(i<vec.size())
    {
        if(vec[i]>mayor)
        {
            mayor=vec[i];//acualizamos mayor si encuentra un numero mayor al que era anteriormente
            j=i;//actualizamos j para borrar esa posicion 
        }
        i++;
    }
    vec.erase(vec.begin()+j);//borramos el numero en esa posicion j
    return mayor;//retorna el numero mayor del vector

}
int menor(vector<int> &vec)//funcion para hallar el numero menor
{
    int menor=vec[0],i=0;
    while(i<vec.size())
    {
        if(vec[i]<menor)
        {
            menor=vec[i] ;
            vec.erase(vec.begin()+i);
        }
        i++;
    }
    return menor;

}
void particionable(vector<int> &vec)
{
    int big,total;
    vector<int>vec1;//creamos dos vectores para almacenar los subconjuntos
    vector<int>vec2;
    total=accumulate(vec.begin(),vec.end(),0);//calculamos la suma de los elementos del vector
    big=mayor(vec);//calculamos el mayor de los elementos
    if(big>(total/2))//en el caso de que el mayor numero de la lista se mayor que el total/2 no habria solucion
        cout << "no hay solucion para el problema" << endl;
    else //en otro caso 
    {   
        vec1.push_back(big);//agregamos el mas grande al vector 1
        int sum=accumulate(vec1.begin(),vec1.end(),0);//calculamos la suma de sus elementos
        for (int i = 0; i < vec.size(); i++)
        {
            vec1.push_back(menor(vec));//agregamos el menor  de los numeros 
            sum=accumulate(vec1.begin(),vec1.end(),0);//volvemos a calcular la suma de los elementos de vec
            for (int j = 0; j < vec.size(); i++)
            {
                if(total/2==sum+vec[i])//si le agregamos un elemento de vec1 y ya es igual a total/2 se terina todo
                {
                    vec1.push_back(vec[j]);
                    vec.erase(vec.begin()+j);
                    j=vec.size();
                    i=vec.size();
                }
            }
        }
        for (int i = 0; i < vec.size(); i++)//agrega los elementos que quedaron en vec a vec2
        {
            vec2.push_back(vec[i]);
        }
    }
    //imprime los dos vectores
    cout << "elements vector 1" << endl;
    for(int i=0;i<vec1.size();i++){cout << vec1[i] << endl;}
    cout << "elements vector 2" << endl;    
    for(int i=0;i<vec2.size();i++){cout << vec2[i] << endl;}
    
}

int main()
{
    int a,tam;
    cout << "ingrese el tamaño " ; cin >> tam;
    vector<int>v;
    while(tam>0)
    {
        cout << "ingrese el numero "; cin >> a;
        v.push_back(a);
        tam--;
    }
    particionable(v);
}