#include "heap.h"
#include <iostream>

/* Starting size for the heap.*/
const int DEFAULT_SIZE = 9;

heap::heap() {
    allocatedLength = DEFAULT_SIZE;
    n =0;
    T = new int[allocatedLength];
}

heap::~heap() {
    delete[] T;
}

/* Retorna el número de elementos de la cola de prioridad. */
int heap::sizes() {
    return n;
}

bool heap::isEmpty() {
    return (sizes() == 0);
}

/* Aumenta el tamaño del array cuando se necesita más espacio. */
void heap::grow() {
    allocatedLength*=2;
    int* newElems = new int[allocatedLength];
    for (int i=0; i<n; i++) {
        newElems[i] = T[i];
    }
    delete[] T;
    T = newElems;
}

/* Devuelve, pero no elimina, el primer elemento en la cola de prioridad. */
int heap::peek() {
    if (isEmpty()) {
        cout<<"Cola esta vacia.";
    }
    return T[0];
}

/* Encola una nuevo elemento en la cola de prioridad. */
void heap::enqueue(int value) {

    if(sizes()<DEFAULT_SIZE){
        T[n+1]= value;
        n=n+1;
        bubbleUp(n);
    }
    else{
        grow();
        enqueue(value);}
}

/* Devuelve y elimina el primer elemento de la cola de prioridades. */
int heap::dequeue() {
 if (isEmpty()) {
        cout<<"Cola esta vacia.";
    }
    //return T[0];
    T[1]=T[n];
    n=n-1;
    bubbleDown(1);
}


void heap::imprime() {
    if (isEmpty()) {
        cout<<"Cola esta vacia.";
    }
    else{
    for(int i=0;i<n;i++){
        cout<<T[i+1]<<" ";
    }
    }
}

/* Metodo para subir un nodo recién colocado y obtener un heap válido. */
void heap::bubbleUp(int childPos) {
    int j,a;
    j=childPos/2;
    if(j>=1){
        if(T[childPos]>T[j])
        {
        a=T[childPos];
        T[childPos]=T[j];
        T[j]=a;
        bubbleUp(j);
        }
    }
}

/* Metodo para descender y obtener un heap válido. */
void heap::bubbleDown(int parentPos) {
    int j,a;
    j=parentPos*2;
    if(j<=n){
        if(j<n){
         if(T[j+1]>T[j]){
            j=j+1;}
        if(T[parentPos]<T[j])
         {
         a=T[parentPos];
         T[parentPos]=T[j];
         T[j]=a;
         bubbleDown(j);}

}}}

