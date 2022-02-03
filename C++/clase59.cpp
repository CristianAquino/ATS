#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

struct corredor
{
    char nombre[20];
    int edad;
    char sexo[10];
    char club[30];
    char categoria[20];
};

int main(int argc, char const *argv[])
{
    int n;
    cout<<"CUANTOS CORREDORES DESEA INGRESAR?";
    cin>>n;
    struct corredor c1[n];
    
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        cout<<"CORREDOR"<<i+1<<endl;
        cout<<"INGRESE NOMBRE DEL CORREDOR: "<<endl;
        cin>>c1[i].nombre;
        cout<<"INGRESE EDAD DEL CORREDOR: "<<endl;
        cin>>c1[i].edad;
        cout<<"INGRESE SEXO DEL CORREDOR: "<<endl;
        cin>>c1[i].sexo;
        cout<<"INGRESE CLUB DEL CORREDOR: "<<endl;
        cin>>c1[i].club;

        if (c1[i].edad<=18)
        {
        strcpy(c1[i].categoria,"JUVENIL");
        }else if (c1[i].edad<=40)  
        {
        strcpy(c1[i].categoria,"SENIOR");
        }else{
        strcpy(c1[i].categoria,"VETERANO");
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout<<"DATOS CORREDOR"<<i+1<<endl;
        cout<<"NOMBRE DEL CORREDOR: "<<c1[i].nombre<<endl;
        cout<<"EDAD DEL CORREDOR: "<<c1[i].edad<<endl;
        cout<<"SEXO DEL CORREDOR: "<<c1[i].sexo<<endl;
        cout<<"CLUB DEL CORREDOR: "<<c1[i].club<<endl;
        cout<<"CATEGORIA DEL CORREDOR: "<<c1[i].categoria<<endl;
    }
    return 0;
}

