#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
};

void push(Nodo *&ini,Nodo *&fin,int n){
    Nodo *nuevo = new Nodo();
    nuevo->dato=n;
    nuevo->sig=NULL;

    if (ini == NULL)
    {
        ini = nuevo;
    }else{
        fin->sig=nuevo;
    }
    fin = nuevo;
    cout<<"ELEMENTO "<<n<<" INGRESADO"<<endl;
}

void pop(Nodo *&ini,Nodo *&fin){
    int n;
    Nodo *aux = ini;
    n=aux->dato;
    if(ini == fin){
        ini=aux->sig;
        fin=aux->sig;
    }else{
        ini=aux->sig;
    }
    delete(aux);
    cout<<"SE ELIMINO "<<n<<endl;
}

void mostrar(Nodo *ini,Nodo *fin){
    Nodo *aux = ini;
    cout<<"INICIO\t";
    while (aux!=NULL)
    {
        cout<<aux->dato<<"-";
        aux= aux->sig;
    }
    cout<<"\tFIN\n";
}

int main(int argc, char const *argv[])
{
    Nodo *ini=NULL;
    Nodo *fin=NULL;
    push(ini,fin,12);
    push(ini,fin,15);
    mostrar(ini,fin);
    while (ini!=NULL)//bucle  necesario para eliminar todo
    {
        pop(ini,fin);
    }    
    return 0;
}

