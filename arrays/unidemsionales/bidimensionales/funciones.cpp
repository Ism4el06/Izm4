#include <iostream>
#define max 50
#include <stdlib.h>
#include <time.h>
using namespace std;
void llenaTabla (int tabla[][50],int f,int c){
    for (int i=0; i<f; i++){
        for (int j=0; j<c; j++){
            cout << "Ingrese el valor de la posicion ["<<i<<"]["<<j<<"]: "; cin >> tabla[i][j];
        }
    }
}
void imprimeTabla(int tabla [][50],int f, int c){
    for(int i=0;i < f;i++){
        for (int j=0; j<c;j++){
            cout<<tabla [i][j]<<"\t";
        }
    }
}
main ()
{
    int Tabla [50][50],filas,columnas;
    cout << "Ingrese el numero de filas y columas de las tablas: "; cin >> filas>>columnas;
    llenaTabla (Tabla,filas,columnas);
    imprimeTabla (Tabla,filas,columnas);
}