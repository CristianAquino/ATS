#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;//importante para la eliminacion
};

Nodo *crearNodo(int n,Nodo *padre){
    Nodo *nuevo = new Nodo();
    nuevo->dato=n;
    nuevo->der=NULL;
    nuevo->izq=NULL;
    nuevo->padre=padre;
    return nuevo;
}
void insertar(Nodo *&arbol,int n,Nodo *padre){
    if(arbol==NULL){
        Nodo *nuevo=crearNodo(n,padre);
        arbol=nuevo;
    }else{
        int raiz;
        raiz = arbol->dato;
        if(n<raiz){
            insertar(arbol->izq,n,arbol);
        }else{
            insertar(arbol->der,n,arbol);
        }
    }
}
void mostrar(Nodo *arbol,int c){
    if(arbol==NULL){
        return;
    }else{
        mostrar(arbol->der,c+1);
        for (int i=0; i<c;i++){
            cout<<"   ";
        }
        cout<<arbol->dato<<endl;
        mostrar(arbol->izq,c+1);
    }
}
void buscar(Nodo *arbol,int n, int c){
    if(arbol==NULL){
        return;
    }else{
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
    }
}
void reemplazar(Nodo *arbol,Nodo *nuevoNodo){//reemplaza dos nodos
    if(arbol->padre){//asignamos al padre un nuevo hijo
        if(arbol->dato==arbol->padre->izq->dato){
            arbol->padre->izq=nuevoNodo;
        }else if(arbol->dato==arbol->padre->der->dato){
            arbol->padre->der=nuevoNodo;
        }
    }
    if(nuevoNodo){//asignamos nuevo padre
        nuevoNodo->padre=arbol->padre;
    }
}
Nodo *minimo(Nodo *arbol){//determinar el nodo mas a la izq
    if(arbol==NULL){
        return NULL;
    }
    if(arbol->izq){//si tiene hijo izq
        return minimo(arbol->izq);
    }else{
        return arbol;//retorna el mismo nodo
    }
}
void destruir(Nodo *nodo){
    nodo->der=NULL;
    nodo->izq=NULL;
    delete nodo;
}
void eliminarNodo(Nodo *nodoEliminar){
    if(nodoEliminar->der && nodoEliminar->izq){//si tiene hijo izq y der
        Nodo *menor = minimo(nodoEliminar->der);
        nodoEliminar->dato=menor->dato;
        eliminarNodo(menor);
    }else if(nodoEliminar->izq){//si tiene hijo izq
        reemplazar(nodoEliminar,nodoEliminar->izq);
        destruir(nodoEliminar);
    }else if(nodoEliminar->der){//si tiene hijo der
        reemplazar(nodoEliminar,nodoEliminar->der);
        destruir(nodoEliminar);
    }else{//sin hijos
        reemplazar(nodoEliminar,NULL);
        destruir(nodoEliminar);
    }
}
void eliminar(Nodo *arbol,int n){
    if(arbol==NULL){
        return;
    }else if(n<arbol->dato){
        eliminar(arbol->izq,n);
    }else if(n>arbol->dato){
        eliminar(arbol->der,n);
    }else{//cuando encuentra el elemento
        eliminarNodo(arbol);
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
        cout<<"4.ELIMINAR\n";
        cout<<"0.SALIR\n";
        cout<<"INGRESE SU OPCION: ";
        cin>>op;
        switch (op)
        {
            case 1:
                cout<<"INGRESE SU ELEMENTO: ";
                cin>>n;
                insertar(arbol,n,NULL);
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
                cout<<"INGRESE EL ELEMENTO A ELIMINAR: ";
                cin>>n;
                eliminar(arbol,n);
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