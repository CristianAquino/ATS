#include<iostream>
#include<conio.h>
#include<stdlib.h>//para el new

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
};

void insertar(Nodo *&pila,int n){
    Nodo *nuevo = new Nodo();
    nuevo->dato=n;
    nuevo->sig=pila;
    pila=nuevo;
    cout<<"SE AGREGO: "<<n<<endl; 
}
//void eliminar(Nodo *&pila,int &n){
void eliminar(Nodo *&pila){
    int n;
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->sig;
    delete aux;
    cout<<"SE ELIMINO: "<<n<<endl;
}
int main(int argc, char const *argv[])
{
    //int n; necesario para referencia
    Nodo *pila = NULL;
    insertar(pila,15);
    insertar(pila,10);
    while (pila!=NULL)//debido al ciclo se elimina todo
    {
        eliminar(pila);
    }
    return 0;
}

