#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main()
{
    string nombre= "Freddy";
    string apellido("Jaramillo");
    string inicial(1, 'f');
    string cadena= "Juan Jose Arturo";
    string nombre2(cadena,5);
    cout<< "La longitud de nombre2 es: "<<nombre2.length()<<endl;
    inicial += "reddy";
    cout<<inicial[0]<<endl;
    cout<<inicial<<endl;
    inicial = "cad";
    cout <<inicial<<endl;
    cout<<nombre2<<endl;
    return 0;
}