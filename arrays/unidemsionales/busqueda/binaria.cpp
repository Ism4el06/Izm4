#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../../../librerias/array.h"
using namespace std;
using namespace vectorn;
bool isBusquedaBinaria(int v[], int n, int elemento) {
    int izquierda = 0;
    int derecha = n - 1;
    for (int i = 0; i <= derecha; i++) {
        int centro = (izquierda + derecha) / 2;
        if (v[centro] == elemento) {
            return true;
        } else if (v[centro] < elemento) {
            izquierda = centro + 1;
        } else {
            derecha = centro - 1;
        }
    }
    return false;
}

int main () {
    int ne, dato;
    cout << "Ingrese el numero de elementos del vector: ";
    cin >> ne;
    int vector[ne];
    llenarVector(vector, ne);
    cout << "Vector generado: ";
    mostrarVector(vector, ne);
    cout << endl;
    ordenarSeleccion(vector, ne); // Ordenamos el vector
    cout << "Vector ordenado: ";
    mostrarVector(vector, ne);
    cout << endl;
    cout << "\nIngrese el elemento a buscar: ";
    cin >> dato;
    (isBusquedaBinaria(vector, ne, dato)) ? cout << "El elemento esta en el vector" : cout << "El elemento no esta en el vector";
    cout << endl;
}