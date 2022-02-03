#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
};

void push(Nodo *&pila,int n){
    Nodo *nuevo = new Nodo();
    nuevo->dato=n;
    nuevo->sig=pila;
    pila = nuevo;
    cout<<"SE AGREGO: "<<n<<endl;
}
//solo elimina el de encima
void pop(Nodo *&pila){
    int n;
    Nodo *aux = pila;
    n=aux->dato;
    pila=aux->sig;
    delete(aux);
    cout<<"SE ELIMINO: "<<n<<endl;
}

void mostrar(Nodo *pila){
    Nodo *aux = pila;
    cout<<"CIMA\t";
    while (aux!=NULL)
    {
        cout<<aux->dato<<"-";
        aux = aux->sig;
    }
    cout<<"\tFIN";
    cout<<"\n";
}

int main(int argc, char const *argv[])
{
    Nodo *pila = NULL;
    int dato;
    char op = 'S';
    while (toupper(op)=='S')
    {
        cout<<"INGRESE UN NUMERO: ";
        cin>>dato;
        push(pila,dato);
        cout<<"DESEA INGRESAR OTRO NUMERO (s/n): ";
        cin>>op;
    }
    mostrar(pila);
    while (pila!=NULL)
    {
        pop(pila);
    }
    return 0;
}

