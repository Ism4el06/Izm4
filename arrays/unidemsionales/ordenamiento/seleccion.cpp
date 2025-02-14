#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void llenarVector(int v[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        //v[i] = rand() % 20 + 1;
        cin>>v[i];
    }
}

void mostrarVector(int v[], int n) {
    for (int i = 0; i < n; i++) {
    cout << v[i] << "\t";
    }
}

int ordenarSeleccion(int v[], int n) {
    int contador = 0, aux;
    bool cambio = true;
    for (int i = 0; i < n-1 && cambio; i++) {
        cambio = false;
        for (int j = i + 1; j < n; j++) {
            contador++;
            if (v[i] > v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                cambio = true;
            }
        }
    }
    return contador;
}

int main() {
    int ne, comparaciones;
    cout << "Ingrese el numero de elementos del vector: ";
    cin >> ne;
    int vector[ne];
    llenarVector(vector, ne);
    cout << "Vector original: \n";
    mostrarVector(vector, ne);
comparaciones = ordenarSeleccion(vector, ne);
cout << "\nVector ordenado: \n";
mostrarVector(vector, ne);
cout << "\nEl numero de comparaciones es: " << comparaciones;
}