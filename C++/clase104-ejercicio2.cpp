#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
struct Nodo
{
    float dato;
    Nodo *sig;
};

void insertar(Nodo *&lista,float n){
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
float suma(Nodo *lista){
    float s=0;
    Nodo *aux=lista;
    while (aux!=NULL)
    {
        s=s+aux->dato;
        aux=aux->sig;
    }
    return s;
}
void promedio(Nodo *lista,float p){
    int c=0;
    float promedio;
    Nodo *aux=lista;
    while (aux!=NULL)
    {
        c++;
        aux=aux->sig;
    }
    promedio = p/c;
    cout<<"EL PROMEDIO ES: "<<promedio<<endl;
}

void menu(){
    Nodo *lista=NULL;
    int op,n;
    do
    {
        cout<<"MENU\n";
        cout<<"1.INSERTAR\n";
        cout<<"2.MOSTRAR\n";
        cout<<"3.SUMA DE ELEMENTOS\n";
        cout<<"4.PROMEDIO DE LOS ELEMENTOS\n";
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
                mostrar(lista);
                float n;
                n=suma(lista);
                cout<<"LA SUMA ES: "<<n<<endl;
                system("pause");
                break;
            case 4:
                promedio(lista,suma(lista));
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