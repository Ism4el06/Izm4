#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

namespace vectorn {
    void llenarVector(int v[], int n, int ri=0, int rs=10) {
        int i;
        for (int i = 0; i < n; i++) {
            v[i] = rand() % (rs - ri + 1) + ri;
        }
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

int ordenarInsercion(int v[], int n) {
    int contador = 0;
    for (int i = 1; i < n; i++) {
        int aux = v[i];
        int j = i - 1;
        while (j >= 0) {
            contador++;
            if (aux < v[j]) {
                v[j + 1] = v[j];
                v[j] = aux;
            }
            j--;
        }
    }
    return contador;
}

// Funcion para generar un numero aleatorio
int generarNumeroAleatorio(int ri, int rs) {
    return rand() % (rs - ri + 1) + ri;
}

// Funcion para adivinar el numero
void adivinarNumero() {
    srand(time(NULL)); // Inicializar la semilla para numeros aleatorios
    int numeroAdivinar = generarNumeroAleatorio(1, 10); // Numero entre 1 y 10
    int intentos = 3;
    int intentoUsuario;

    cout << "¡Bienvenido al juego de adivinar el numero!" << endl;
    cout << "Tienes 3 intentos para adivinar un numero entre 1 y 10." << endl;

    for (int i = 0; i < intentos; i++) {
        cout << "Intento #" << i + 1 << ": ";
        cin >> intentoUsuario;

        if (intentoUsuario == numeroAdivinar) {
            cout << "¡Felicidades! Has adivinado el numero." << endl;
            return;
        } else {
            cout << "Numero incorrecto. ";
            if (intentoUsuario < numeroAdivinar) {
                cout << "El numero a adivinar es mayor." << endl;
            } else {
                cout << "El numero a adivinar es menor." << endl;
            }
        }
    }

    cout << "Lo siento, has agotado tus intentos. El numero era: " << numeroAdivinar << endl;
}

int main() {
    adivinarNumero();
    return 0;
}
