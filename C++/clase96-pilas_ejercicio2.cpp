#include<conio.h>
#include<iostream>
#include<string>

using namespace std;

struct Nodo
{
    char dato;
    Nodo *sig;
};

void push(Nodo *&pila,char c){
    Nodo *nuevo = new Nodo();
    nuevo->dato=c;
    nuevo->sig=pila;
    pila = nuevo;
    cout<<"CARACTER "<<c<<" INGRESADO\n";
}
void mostrar(Nodo *pila){
    Nodo *aux = pila;
    cout<<"CIMA\t";
    while (aux!=NULL)
    {
        cout<<aux->dato<<"-";
        aux=aux->sig;
    }
    cout<<"\tFIN"<<endl;
}
int main(int argc, char const *argv[])
{
    Nodo *pila = NULL;
    char dato;
    int op;
    do
    {
        cout<<"\tMENU\n";
        cout<<"1. INSERTAR\n";
        cout<<"2. MOSTRAR\n";
        cout<<"0. SALIR\n";
        cout<<"INGRESE SU OPCION: ";
        cin>>op;
        switch (op)
        {
        case 1:
            cout<<"INGRESE UN CARACTER: ";
            cin>>dato;
            push(pila,dato);
            system("pause");
            system("cls");
            break;
        case 2:
            cout<<"DATOS EN LA PILA\n";
            mostrar(pila);
            system("pause");
            system("cls");
            break;
        }
    } while (op!=0);
    cout<<"PROGRAMA FINALIZADO";
    return 0;
}