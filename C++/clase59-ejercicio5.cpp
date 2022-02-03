#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

struct persona
{
    char nombre[20];
    bool disc;
};

int main(int argc, char const *argv[])
{
    int n, d=0,s=0;
    cout<<"INGRESE LA CANTIDAD DE PERSONAS\n";
    cin>>n;
    struct persona p[n],p1[100],p2[100];
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        cout<<"NOMBRE: ";
        cin>>p[i].nombre;
        cout<<"DISCAPACIDAD SI(1)/NO(0)";
        cin>>p[i].disc;
        if (p[i].disc==1)
        {
            strcpy(p1[d].nombre,p[i].nombre);
            d++;
        }else{
            strcpy(p2[s].nombre,p[i].nombre);
            s++;
        }
    }
    cout<<"PERSONA CON DISCAPACIDAD\n";
    for (int i = 0; i < d; i++)
    {
        cout<<"NOMBRE: "<<p1[i].nombre<<endl;
    }
    cout<<"PERSONA SIN DISCAPACIDAD\n";
    for (int i = 0; i < s; i++)
    {
        cout<<"NOMBRE: "<<p2[i].nombre<<endl;
    }    
    return 0;
}

