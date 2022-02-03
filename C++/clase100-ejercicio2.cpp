#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct cliente
{
    char nombre[20];
    int edad;
};

struct Nodo
{
    struct cliente cl;
    Nodo *sig;
};

void push(Nodo *&ini,Nodo *&fin,cliente &c){
    Nodo *nuevo = new Nodo();
    nuevo->cl=c;
    nuevo->sig=NULL;
    if(ini==NULL){
        ini=nuevo;
    }else{
        fin->sig=nuevo;
    }
    fin=nuevo;
    cout<<"SE GUARDO DATOS DEL CLIENTE\n";
}
void mostrar(Nodo *ini,Nodo *fin){
    int cont = 0;
    if(ini!=NULL){
        Nodo *aux=ini;
        cout<<"INICIO\n";
        while (aux!=NULL)
        {
            cout<<"\tCLIENTE "<<cont+1<<endl;
            cout<<"\tNOMBRE: "<<aux->cl.nombre<<endl;
            cout<<"\tEDAD: "<<aux->cl.edad<<endl;
            aux=aux->sig;
            cont++;
        }
        cout<<"FIN\n";
    }else{
        cout<<"NO HAY DATOS QUE MOSTRAR\n";
    }
}

int main(int argc, char const *argv[])
{
    struct cliente clientes;
    int op;
    Nodo *ini=NULL;
    Nodo *fin=NULL;
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
            cout<<"INGRESE NOMBRE: ";
            cin>>clientes.nombre;
            cout<<"INGRESE EDAD: ";
            cin>>clientes.edad;
            push(ini,fin,clientes);
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