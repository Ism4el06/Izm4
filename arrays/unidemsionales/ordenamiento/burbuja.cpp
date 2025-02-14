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

int ordenarBurbujav3(int v[], int n) {
    int mejora = 1;
    bool cambio = true;
    int aux, contador = 0;
    for (int i = 0; i < n && cambio; i++) {
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
    }
    return contador;
}

int determinarMasOptima(int c1, int c2, int c3) {
    if (c1 <= c2 && c1 <= c3) return 1;
    if (c2 <= c1 && c2 <= c3) return 2;
    return 3;
}

void mostrarVector(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}

main() {
    int ne;
    cout << "Numero de elementos: ";
    cin >> ne;
    int vec[ne], copia1[ne], copia2[ne], copia3[ne];
    llenarVector(vec, ne);
    for (int i = 0; i < ne; i++) {
        copia1[i] = copia2[i] = copia3[i] = vec[i];
    }
    cout << "Vector original: ";
    mostrarVector(vec, ne);
    cout << endl;
    int c1 = ordenarBurbujav1(copia1, ne);
    int c2 = ordenarBurbujav2(copia2, ne);
    int c3 = ordenarBurbujav3(copia3, ne);
    cout << "El # de comparaciones burbuja v1: " << c1 << endl;
    cout << "El # de comparaciones burbuja v2: " << c2 << endl;
    cout << "El # de comparaciones burbuja v3: " << c3 << endl;
    cout << "La version mas optima es: v" << determinarMasOptima(c1, c2, c3) << endl;
    cout << "Vector ordenado: ";
    mostrarVector(copia1, ne);
}