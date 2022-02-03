#include<iostream>
#include<conio.h>

using namespace std;

struct alumno
{
    char nombre[20];
    int edad;
    float promedio;
};

int main(int argc, char const *argv[])
{
    int n;
    cout<<"CUANTOS ALUMNO INGRESARA?\n";
    cin>>n;
    struct alumno au[n];

    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        cout<<"ALUMNO"<<i+1<<endl;
        cout<<"INGRESE SU NOMBRE: ";
        cin>>au[i].nombre;
        cout<<"INGRESE SU EDAD: ";
        cin>>au[i].edad;

        float prom = 0;
        for (int i = 0; i < 3; i++)
        {
            int n;
            cout<<"INGRESE SU NOTA"<<i+1<<endl;
            cin>>n;
            prom = n+prom;
        }
        float p = prom/3;
        au[i].promedio=p;
        cout<<"\n";
    }

    for (int i = 0; i < n; i++)
    {
        cout<<"DATOS ALUMNO "<<i+1<<endl;
        cout<<"NOMBRE: "<<au[i].nombre<<endl;
        cout<<"EDAD: "<<au[i].edad<<endl;
        cout<<"PROMEDIO: "<<au[i].promedio<<endl;
        cout<<"\n";
    }
    int max=0,pos;
    for (int i = 0; i < n; i++)
    {
        if(au[i].promedio>max){
            max=au[i].promedio;
            pos=i;
        }
    }
    cout<<"\n";
    cout<<"EL MAYOR PROMEDIO ES: "<<max;
    cout<<"\n";
    cout<<"ALUMNO CON MAYOR PROMEDIO"<<endl;
    cout<<"NOMBRE: "<<au[pos].nombre<<endl;
    cout<<"EDAD: "<<au[pos].edad<<endl;
    cout<<"PROMEDIO: "<<au[pos].promedio<<endl;
    return 0;
}