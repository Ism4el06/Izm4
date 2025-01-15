//programa q lee datos y muestra su promedio y el numero de datos que estan x debajo y encima del promedio
#include <iostream>
using namespace std;
main ()
{
    int value, promedio=0, contador=0;
    char op='s';
    bool bandera=false;
    while (bandera){
        cout << "Deseas ingresar valores <<S>> <<N>> : ";
        op=getchar();
        if (op =='s'|| op == 'S'){
            cout << "Ingrese un valor: ";
            cin >> value;
            contador++;
            promedio = promedio + value;
        }else{
          bandera = true;
            
        }

        cin.ignore();
    }
    cout << "El promedio es: "<< (float)promedio/contador ;
}