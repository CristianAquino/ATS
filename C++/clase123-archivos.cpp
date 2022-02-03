#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

void crearArchivo(){
    fflush(stdin);
    ofstream archivo;
    string dir,nombre;
    cout<<"EL ARCHIVO SE CREARA EN EL ESCRITORIO\n";
    dir = "C:/Users/51927/Desktop/";
    cout<<"INGRESE EL NOMBRE DEL ARCHIVO ";
    getline(cin,nombre);
    nombre=nombre+".txt";
    dir=dir+nombre;
    archivo.open(dir.c_str(),ios::out);
    if(archivo.fail()){
        cout<<"ERROR AL CREAR EL ARCHIVO\n";
        exit(1);
    }
    archivo.close(); 
}

void escribirArchivo(string dir){
    ofstream archivo;
    string frase;
    //si se crea un archivo existente no genera error y sobrescribe
    archivo.open(dir.c_str(),ios::out);//abriendo en modo escritura
    if(archivo.fail()){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO\n";
        exit(1);
    }
    //<< es utilizado para agregar el texto al archivo
    //printf("INGRESE SU TEXTO\n");
    int n;
    do
    {
        fflush(stdin);
        cout<<"INGRESE SU TEXTO\n";
        getline(cin,frase);
        frase=frase+"\n";
        archivo<<frase;
        cout<<"DESEA INGRESAR OTRA FRASE S(1)/N(0): ";
        cin>>n;
    } while (n!=1);
    archivo.close();
}
void leerArchivo(string dir){
    ifstream archivo;
    string texto;
    archivo.open(dir.c_str(),ios::in);
    if(archivo.fail()){
        cout<<"EL ARCHIVO NO EXISTE O NO SE PUDO ABRIR";
        exit(1);    
    }
    while (!archivo.eof())
    {
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    archivo.close();
}
void agregarTexto(string dir){
    ofstream archivo;
    string texto;
    archivo.open(dir.c_str(),ios::app);
    if(archivo.fail()){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO\n";
        exit(1);
    }
    int n;
    do
    {
        fflush(stdin);
        cout<<"INGRESE SU TEXTO\n";
        getline(cin,texto);
        texto=texto+"\n";
        archivo<<texto;
        cout<<"DESEA INGRESAR OTRA FRASE S(1)/N(0): ";
        cin>>n;
    } while (n!=1);
    archivo.close();
}
void menu2(string dir){
    int op;
    do
    {
        fflush(stdin);
        cout<<"ARCHIVO: "<<dir<<endl;
        cout<<"\tMENU\n";
        cout<"1. ESCRIBIR\n";
        cout<"2. LEER\n";
        cout<<"3. AGREGAR TEXTO\n";
        cout<"0. SALIR\n";
        cout<"INGRESE SU OPCION: ";
        cin>>op;
        switch (op)
        {
            case 1:
                escribirArchivo(dir);
                system("pause");
                break;
            case 2:
                leerArchivo(dir);
                system("pause");
                break;
            case 3:
                agregarTexto(dir);
                system("pause");
                break;
        }
        system("cls");
    } while (op!=0);
}
void menu1(){
    int op;
    string dir,nombre;
    dir = "C:/Users/51927/Desktop/"; 
    do
    {
        fflush(stdin);
        cout<<"MENU\n";
        cout<"1. CREAR ARCHIVO\n";
        cout<"2. ABRIR ARCHIVO\n";
        cout<"0. SALIR\n";
        cout<"INGRESE SU OPCION: ";
        cin>>op;
        switch (op)
        {
        case 1:
            crearArchivo();
            system("pause");
            break;
        case 2:
            fflush(stdin);
            cout<<"RECUERDE QUE SE ABRIRAN LOS ARCHIVOS DEL ESCRITORIO\n";
            cout<<"INGRESE EL NOMBRE DEL ARCHIVO";
            getline(cin,nombre);
            nombre=nombre+".txt";
            dir=dir+nombre;
            menu2(dir);
            break;
        }
    } while (op!=0);
}

int main(int argc, char const *argv[])
{
    menu1();
    return 0;
}