#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo
{
    char dato;
    Nodo *sig;
};

void push(Nodo *&ini,Nodo *&fin, char c){
    Nodo *nuevo = new Nodo();
    nuevo->dato=c;
    nuevo->sig=NULL;
    if(ini==NULL){
        ini=nuevo;
    }else{
        fin->sig=nuevo;
    }
    fin=nuevo;
    cout<<"CARACTER "<<c<<" INGRESADO\n";
}

void mostrar(Nodo *ini,Nodo *fin){
    Nodo *aux = ini;
    if(aux!=NULL){
        cout<<"INICIO\t";
        while (aux!=NULL)
        {
            cout<<aux->dato<<"-";
            aux=aux->sig;
        }
        cout<<"\tFIN\n";
    }else{
        cout<<"NO HAY ELEMENTOS\n";
    }
}

void pop(Nodo *&ini,Nodo *&fin){
    int n;
    Nodo *aux=ini;
    n=aux->dato;
    if(ini==fin){
        ini=ini->sig;
        fin=fin->sig;
    }else{
        ini=ini->sig;
    }
    delete(aux);
    cout<<"SE ELIMININO "<<n<<endl;
}

int main(int argc, char const *argv[])
{
    Nodo *ini=NULL;
    Nodo *fin=NULL;
    int op;
    char c;
    do
    {
        fflush(stdin);
        cout<<"MENU\n";
        cout<<"1. INSERTAR\n";
        cout<<"2. MOSTRAR\n";
        cout<<"0. SALIR\n";
        cin>>op;
        switch (op)
        {
        case 1:
            cout<<"INGRESE UN CARACTER: ";
            cin>>c;
            push(ini,fin,c);
            system("pause");
            system("cls"); 
            break;
        case 2:
            cout<<"ELEMENTOS EN LA COLA\n";
            mostrar(ini,fin);
            system("pause");
            system("cls");
            break;
        }
    } while (op!=0);
    cout<<"PROGRAMA FINALIZADO";    
    return 0;
}