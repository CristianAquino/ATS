#include<iostream>
#include<conio.h>

using namespace std;

struct atleta
{
    char nombre[20];
    char pais[20];
    int n_medalla;
};

int main(int argc, char const *argv[])
{
    int n, max=0,pos;
    cout<<"CUANTOS ATLETAS INGRESARA?\n";
    cin>>n;
    struct atleta at[n];
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        cout<<"ATLETA"<<i+1<<endl;
        cout<<"NOMBRE: ";
        cin>>at[i].nombre;
        cout<<"PAIS: ";
        cin>>at[i].pais;
        cout<<"MEDALLAS: ";
        cin>>at[i].n_medalla;

        if(at[i].n_medalla>max){
            max=at[i].n_medalla;
            pos = i;
        }
        cout<<"\n";
    }

    cout<<"ATLETA CON MAYOR CANTIDAD DE MEDALLAS\n";
    cout<<"NOMBRE: "<<at[pos].nombre<<endl;
    cout<<"PAIS: "<<at[pos].pais<<endl;
    cout<<"MEDALLAS: "<<at[pos].n_medalla;
    return 0;
}

