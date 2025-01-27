#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Funcion para llenar el vector con numeros aleatorios
void llenarVector(int v[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 20 + 1;
        //cin>>v[i];
    }
}

// Version 1 de ordenarBurbuja
int ordenarBurbujav1(int v[], int n) {
    int aux, contador = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            contador++;
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
    return contador;
}

// Version 2 de ordenarBurbuja
int ordenarBurbujav2(int v[], int n) {
    int mejora = 1;
    int aux, contador = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - mejora; j++) {
            contador++;
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
        mejora++;
    }
    return contador;
}

// Version 3 de ordenarBurbuja
int ordenarBurbujav3(int v[], int n) {
    int mejora = 1;
    bool cambio;
    int aux, contador = 0;
    for (int i = 0; i < n; i++) {
        cambio = false;
        for (int j = 0; j < n - mejora; j++) {
            contador++;
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                cambio = true;
            }
        }
        mejora++;
        if (!cambio) break;
    }
    return contador;
}

// Funcion para mostrar el vector
void mostrarVector(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Funcion para determinar la version mas optima
void determinarMasOptima(int comparaciones1, int comparaciones2, int comparaciones3) {
    if (comparaciones1 <= comparaciones2 && comparaciones1 <= comparaciones3) {
        cout << "La version mas optima es: Burbuja v1 con " << comparaciones1 << " comparaciones." << endl;
    } else if (comparaciones2 <= comparaciones1 && comparaciones2 <= comparaciones3) {
        cout << "La version mas optima es: Burbuja v2 con " << comparaciones2 << " comparaciones." << endl;
    } else {
        cout << "La version mas optima es: Burbuja v3 con " << comparaciones3 << " comparaciones." << endl;
    }
}

// Funcion principal
int main() {
    int ne;
    cout << "Numero de elementos: ";
    cin >> ne;

    int vec[ne], copia1[ne], copia2[ne];

    llenarVector(vec, ne);

    // Crear copias del vector original
    for (int i = 0; i < ne; i++) {
        copia1[i] = vec[i];
        copia2[i] = vec[i];
    }

    cout << "Vector original: ";
    mostrarVector(vec, ne);

    // Ejecutar y mostrar resultados para cada version
    int comparaciones1 = ordenarBurbujav1(copia1, ne);
    cout << "Vector ordenado por burbuja v1: ";
    mostrarVector(copia1, ne);
    cout << "El numero de comparaciones burbuja v1: " << comparaciones1 << endl;

    int comparaciones2 = ordenarBurbujav2(copia2, ne);
    cout << "Vector ordenado por burbuja v2: ";
    mostrarVector(copia2, ne);
    cout << "El numero de comparaciones burbuja v2: " << comparaciones2 << endl;

    int comparaciones3 = ordenarBurbujav3(vec, ne);
    cout << "Vector ordenado por burbuja v3: ";
    mostrarVector(vec, ne);
    cout << "El numero de comparaciones burbuja v3: " << comparaciones3 << endl;

    // Determinar la version mas optima
    determinarMasOptima(comparaciones1, comparaciones2, comparaciones3);

    return 0;
}
