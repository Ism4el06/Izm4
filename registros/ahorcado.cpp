#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ahorcado.h"
using namespace std;
main()
{
    string palabras[5],palabraSeleccionada;
    
    int op;
    cout << "Juego del Ahorcado" << endl;
    cout << "-------------------" << endl;
    cout<<"Elige una categoria: "<<endl;
    op = opciones();
    (op==1)? deportes(palabras): (op==2)? animales(palabras):(op==3)? frutas(palabras): (op==4)? paises(palabras): vehiculos(palabras);
    system("cls");
    palabraSeleccionada = palabraAleatoria(palabras);
    jugar(palabraSeleccionada);
}