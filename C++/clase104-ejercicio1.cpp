#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
};

void insertar(Nodo *&lista,int n){
    Nodo *nuevo = new Nodo();
    Nodo *aux1=lista;
    Nodo *aux2;
    nuevo->dato=n;
    while (aux1!=NULL)
    {
        aux2=aux1;
        aux1=aux1->sig;
    }
    if(lista==aux1){
        lista=nuevo;
    }else{
        aux2->sig=nuevo;
    }
    nuevo->sig=aux1;
}

void mayor(Nodo *lista){
    Nodo *aux=lista;
    int mayor=0;
    while (aux!=NULL)
    {
        if((aux->dato)>=mayor){
            mayor=aux->dato;
        }
        aux=aux->sig;
    }
    cout<<"EL MAYOR ES: "<<mayor<<endl;
}

void menor(Nodo *lista){
    Nodo *aux=lista;
    int menor=99999;
    while (aux!=NULL)
    {
        if((aux->dato)<=menor){
            menor=aux->dato;
        }
        aux=aux->sig;
    }
    cout<<"EL MENOR ES: "<<menor<<endl;
}

void mostrar(Nodo *lista){
    Nodo *aux=lista;
    while (aux!=NULL)
    {
        cout<<aux->dato<<"-";
        aux=aux->sig;
    }
    cout<<"\n";
}

void menu(){
    Nodo *lista=NULL;
    int op,n;
    do
    {
        cout<<"MENU\n";
        cout<<"1.INSERTAR\n";
        cout<<"2.MOSTRAR\n";
        cout<<"3.MAYOR ELEMENTO\n";
        cout<<"4.MENOR ELEMENTO\n";
        cout<<"0.SALIR\n";
        cout<<"INGRESE SU OPCION: ";
        cin>>op;
        switch (op)
        {
            case 1:
                cout<<"INGRESE SU ELEMENTO: ";
                cin>>n;
                insertar(lista,n);
                system("pause");
                break;
            case 2:
                cout<<"ELEMENTOS DE LA LISTA\n";
                mostrar(lista);
                system("pause");
                break;
            case 3:
                mayor(lista);
                system("pause");
                break;
            case 4:
                menor(lista);
                system("pause");
                break;
        }
        system("cls");
    } while (op!=0);
    cout<<"PROGRAMA FINALIZADO";
}

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}