#include<iostream>
#include<conio.h>

using namespace std;

struct info_direccion
{
    char direccion[30];
    char ciudad[20];
    char provincia[20];
};
struct empleado
{
    char nombre[20];
    struct info_direccion dir_empleado;
    float salario;
};

int main(int argc, char const *argv[])
{
    int n;
    cout<<"CUANTOS EMPLEADOS DESEA REGISTRAR"<<endl;
    cin>>n;
    struct empleado empleados[n];

    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        cout<<"EMPLEADO "<<i+1<<endl;
        cout<<"NOMBRE: ";
        cin>>empleados[i].nombre;
        cout<<"DIRECCION: ";
        cin>>empleados[i].dir_empleado.direccion;
        cout<<"CIUDAD: ";
        cin>>empleados[i].dir_empleado.ciudad;
        cout<<"PROVINCIA: ";
        cin>>empleados[i].dir_empleado.provincia;
        cout<<"SALARIO: ";
        cin>>empleados[i].salario;
        cout<<"\n";
    }
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        cout<<"DATOS EMPLEADO "<<i+1<<endl;
        cout<<"NOMBRE: "<<empleados[i].nombre<<endl;
        cout<<"DIRECCION: "<<empleados[i].dir_empleado.direccion<<endl;
        cout<<"CIUDAD: "<<empleados[i].dir_empleado.ciudad<<endl;
        cout<<"PROVINCIA: "<<empleados[i].dir_empleado.provincia<<endl;
        cout<<"SALARIO: "<<empleados[i].salario<<endl;
        cout<<"\n";
    }
    return 0;
}

