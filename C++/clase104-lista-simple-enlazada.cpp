#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
};

void insertar(Nodo *&lista,int n){
    Nodo *nuevo = new Nodo();
    Nodo *aux1=lista;
    Nodo *aux2;
    nuevo->dato=n;
    while(aux1!=NULL){
        aux2=aux1;
        aux1=aux1->sig;
    }
    if(lista==aux1){
        lista=nuevo;
    }else{
        aux2->sig=nuevo;
    }
    nuevo->sig=aux1;
    cout<<"ELEMENTO "<<n<<" INGRESADO\n";
}
void mostrar(Nodo *lista){
    Nodo *aux=lista;
    if(aux!=NULL){
        while(aux!=NULL){
            cout<<aux->dato<<"-";
            aux=aux->sig;
        }
        cout<<"\n";
    }else{
        cout<<"LA LISTA ESTA VACIA\n";
    }
}
bool buscar(Nodo *lista,int n){
    int c=0;
    bool flag = false;
    Nodo *aux=lista;
    while (aux!=NULL)
    {
        if(aux->dato==n){
            cout<<"ELEMENTO "<<n<<" ENCONTRADO EN LA POSICION "<<c+1<<endl;
            flag = true;  
        }
        aux=aux->sig;
        c++;
    }
    return flag;
}
bool eliminar(Nodo *&lista,int n){
    int c=0;
    bool flag = false;
    Nodo *borrar=lista;
    Nodo *aux=NULL;

    while(borrar!=NULL){
        if(borrar->dato==n){
            if(aux==NULL){
                lista=lista->sig;
                delete(borrar);
                cout<<"ELEMENTO "<<n<<" BORRADO EN LA POSICION "<<c+1<<endl;
                borrar=lista;
                c++;
                flag=true;
            }else{
                aux->sig=borrar->sig;
                delete(borrar);
                cout<<"ELEMENTO "<<n<<" BORRADO EN LA POSICION "<<c+1<<endl;
                borrar=aux;
                c++;
                flag=true;
            }
        }else{
            aux=borrar;
            borrar=borrar->sig;
            c++;
        }
    }
    return flag;
}

void eliminar_todos(Nodo *&lista){
    Nodo *borrar=lista;
    Nodo *aux=NULL;

    while(borrar!=NULL){
        if(aux==NULL){
            lista=lista->sig;
            delete(borrar);
            borrar=lista;
        }
    }
}

void menu(){
    int op,n;
    Nodo *lista=NULL;
    do
    {
    cout<<"\tMENU\n";
    cout<<"1.INSERTAR\n";
    cout<<"2.MOSTRAR\n";
    cout<<"3.BUSCAR\n";
    cout<<"4.ELIMINAR\n";
    cout<<"5.ELIMINAR TODO\n";
    cout<<"0.SALIR\n";
    cout<<"INGRESE UNA OPCION: ";
    cin>>op;
    switch (op)
        {
        case 1:
            cout<<"INGRESE UN ELEMENTO: ";
            cin>>n;
            insertar(lista,n);
            system("pause");
            break;
        case 2:
            cout<<"ELEMENTOS EN LA LISTA\n";
            mostrar(lista);
            system("pause");
            break;
        case 3:
            cout<<"INGRESE UN ELEMENTO PARA BUSCAR: ";
            cin>>n;
            if(buscar(lista,n)==false){
                cout<<"NO SE ENCONTRO\n";
            }
            system("pause");
            break;
        case 4:
            cout<<"INGRESE UN ELEMENTO A ELIMINAR: ";
            cin>>n;
            if(eliminar(lista,n)==false){
                cout<<"NO SE ENCONTRO ELEMENTOS\n";
            }
            system("pause");
            break;
        case 5:
            eliminar_todos(lista);
            cout<<"SE ELIMINARON TODOS LOS ELEMENTOS\n";
            system("pause");
            break;
        }
    system("cls");
    } while (op!=0);
    
}
int main(int argc, char const *argv[])
{
    menu();
    return 0;
}