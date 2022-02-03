#include<iostream>
#include<conio.h>

using namespace std;

struct etapas
{
    int hora;
    int minutos;
    int segundos;
};

int main(int argc, char const *argv[])
{
    int n,h=0,m=0,s=0;
    cout<<"CUANTAS ETAPAS REGISTRARA?\n";
    cin>>n;
    struct etapas et[n];
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        cout<<"ETAPA "<<i+1<<endl;
        cout<<"HORAS: ";
        cin>>et[i].hora;
        cout<<"MINUTOS: ";
        cin>>et[i].minutos;
        cout<<"SEGUNDOS: ";
        cin>>et[i].segundos;

        h=h+et[i].hora;
        m=m+et[i].minutos;
        if(m>=60){
            m=m-60;
            h=h+1;
        }
        s=s+et[i].segundos;
        if(s>=60){
            s=s-60;
            m=m+1;
        }
        cout<<"\n";
    }
    cout<<"HORAS TOTALES: "<<h<<endl;
    cout<<"MINUTOS TOTALES: "<<m<<endl;
    cout<<"SEGUNDOS TOTALES: "<<s<<endl;
    return 0;
}
