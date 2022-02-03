#include<iostream>
#include<conio.h>

using namespace std;

struct promedio
{
    float nota1;
    float nota2;
    float nota3;
};

struct alumno
{
    char nombre[20];
    char sexo[10];
    int edad;
    struct promedio prom;
};

int main(int argc, char const *argv[])
{
    int n,max=0,pos;
    cout<<"CUANTOS ALUMNOS INGRESARA?\n";
    cin>>n;
    float f[n];
    struct alumno au[n];
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        cout<<"ALUMNO "<<i+1<<endl;
        cout<<"NOMBRE: ";
        cin>>au[i].nombre;
        cout<<"SEXO: ";
        cin>>au[i].sexo;
        cout<<"EDAD: ";
        cin>>au[i].edad;

        cout<<"NOTAS ALUMNO "<<i+1<<endl;
        cout<<"NOTA1: ";
        cin>>au[i].prom.nota1;
        cout<<"NOTA2: ";
        cin>>au[i].prom.nota2;
        cout<<"NOTA3: ";
        cin>>au[i].prom.nota3;

        f[i] = (au[i].prom.nota1+au[i].prom.nota2+au[i].prom.nota3)/3;
        if(f[i]>max){
            max = f[i];
            pos=i;
        }
        cout<<"\n";
    }

    for (int i = 0; i < n; i++)
    {
        cout<<"DATOS ALUMNO "<<i+1<<endl;
        cout<<"NOMBRE: "<<au[i].nombre<<endl;
        cout<<"SEXO: "<<au[i].sexo<<endl;
        cout<<"EDAD: "<<au[i].edad<<endl;

        cout<<"NOTAS ALUMNO "<<i+1<<endl;
        cout<<"NOTA1: "<<au[i].prom.nota1<<endl;
        cout<<"NOTA2: "<<au[i].prom.nota2<<endl;
        cout<<"NOTA3: "<<au[i].prom.nota3<<endl;
        cout<<"\n";
    }
    cout<<"MEJOR PROMEDIO: "<<f[pos];
    return 0;
}


