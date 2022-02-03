#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *der;
    Nodo *izq;
};
//se podria decir que es el nodo arbol
Nodo *crearNodo(int n){
    Nodo *nuevo = new Nodo();
    nuevo->dato=n;
    nuevo->der=NULL;
    nuevo->izq=NULL;
    return nuevo;
}

void insertar(Nodo *&arbol,int n){
    if(arbol==NULL){
        Nodo *nuevo = crearNodo(n);
        arbol=nuevo;
    }else{
        int raiz;
        raiz=arbol->dato;
        if(n<raiz){
            insertar(arbol->izq,n);
        }else{
            insertar(arbol->der,n); 
        }
    }
}
void mostrar(Nodo *arbol,int c){
    if(arbol==NULL){
        return;
    }else{
        mostrar(arbol->der,c+1);
        for(int i=0;i<c;i++){
            cout<<"   ";
        }
        cout<<arbol->dato<<endl;
        mostrar(arbol->izq,c+1);
    }
}
void buscar(Nodo *arbol,int n,int c){
    if(arbol!=NULL){
        if(n==arbol->dato){
            cout<<"EL ELEMENTO "<<n<<" SE ENCUENTRA EN EL ARBOL\n";
            cout<<"Y ESTA EN EL NIVEL "<<c<<endl;
        }else{
            if(n<arbol->dato){
                buscar(arbol->izq,n,c+1);
            }else{
                buscar(arbol->der,n,c+1);
            }
        }
    }else{
        cout<<"EL ELEMENTO NO SE ENCONTRO\n";
    }
}
void preOrden(Nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        cout<<arbol->dato<<"-";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}
void inOrden(Nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        inOrden(arbol->izq);
        cout<<arbol->dato<<"-";
        inOrden(arbol->der);
    }
}
void postOrden(Nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout<<arbol->dato<<"-";
    }
}
void menu(){
    int op,n,c=0;
    Nodo *arbol=NULL;
    do
    {
        cout<<"\tMENU\n";
        cout<<"1.INSERTAR\n";
        cout<<"2.MOSTRAR\n";
        cout<<"3.BUSCAR\n";
        cout<<"4.PREORDEN\n";
        cout<<"5.INORDEN\n";
        cout<<"6.POSTORDEN\n";
        cout<<"0.SALIR\n";
        cout<<"INGRESE SU OPCION: ";
        cin>>op;
        switch (op)
        {
            case 1:
                cout<<"INGRESE SU ELEMENTO: ";
                cin>>n;
                insertar(arbol,n);
                system("pause");
                break;
            case 2:
                mostrar(arbol,c);
                system("pause");
                break;
            case 3:
                cout<<"INGRESE EL DATO A BUSCAR: ";
                cin>>n;
                buscar(arbol,n,c);
                system("pause");
                break;
            case 4:
                cout<<"ARBOL EN PRE-ORDEN: ";
                preOrden(arbol);
                cout<<"\n";
                system("pause");
                break;
            case 5:
                cout<<"ARBOL EN IN-ORDEN: ";
                inOrden(arbol);
                cout<<"\n";
                system("pause");
                break;
            case 6:
                cout<<"ARBOL EN POST-ORDEN: ";
                postOrden(arbol);
                cout<<"\n";
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