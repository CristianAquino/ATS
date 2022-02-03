#include <iostream>
#include <conio.h>

using namespace std;

struct Persona
{
    char nombre[20];
    int edad;
}persona1,persona2;

int main(int argc, char const *argv[])
{
    cout<<"Ingrese el nombre de la Persona1:";
    cin>>persona1.nombre;
    cout<<"Ingrese la edad de la persona1:";
    cin>>persona1.edad;
    cout<<endl;
    cout<<"Ingrese el nombre de la Persona2:";
    cin>>persona2.nombre;
    cout<<"Ingrese la edad de la persona2:";
    cin>>persona2.edad;
    
    cout<<"DATOS Persona"<<endl;
    cout<<"Nombre de la Persona1:"<<persona1.nombre;
    cout<<"Edad de la persona1:"<<persona1.edad;
    cout<<endl;
    cout<<"Nombre de la Persona2:"<<persona2.nombre;
    cout<<"Edad de la persona2:"<<persona2.edad;
    
    return 0;
}

