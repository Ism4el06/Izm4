#include <iostream>
#include <stdlib.h>
#include <time.h>
#define max 50

using namespace std;

int tabla[max][max]; // Declarar la variable tabla como global

// Función para llenar la tabla con números aleatorios del 10 al 20
void llenaTabla(int f, int c) {
    srand(time(NULL)); // Semilla para números aleatorios
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            tabla[i][j] = 10 + rand() % 11; // Genera números entre 10 y 20
        }
    }
}

// Función para imprimir la tabla
void imprimeTabla(int f, int c) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            cout << tabla[i][j] << "\t";
        }
        cout << endl;
    }
}

// Función para calcular la suma de la diagonal principal
int sumaDiagonalPrincipal(int f, int c) {
    int suma = 0;
    for (int i = 0; i < f && i < c; i++) {
        suma += tabla[i][i];
    }
    return suma;
}

// Función para calcular la suma de la diagonal secundaria
int sumaDiagonalSecundaria(int f, int c) {
    int suma = 0;
    for (int i = 0; i < f && i < c; i++) {
        suma += tabla[i][c - 1 - i];
    }
    return suma;
}

// Función para determinar la diagonal mayor
string determinarDiagonalMayor(int sumaPrincipal, int sumaSecundaria) {
    if (sumaPrincipal > sumaSecundaria) {
        return "Diagonal Principal";
    } else if (sumaSecundaria > sumaPrincipal) {
        return "Diagonal Secundaria";
    } else {
        return "Ambas diagonales son iguales";
    }
}

// Función para graficar las diagonales
void graficarDiagonales(int f, int c) {
    cout << "\nGrafico de las diagonales:\n";
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            if (i == j) {
                cout << "P" << "\t"; // Diagonal principal
            } else if (i + j == c - 1) {
                cout << "S" << "\t"; // Diagonal secundaria
            } else {
                cout << "-" << "\t";
            }
        }
        cout << endl;
    }
}

// Función para limpiar la terminal
void limpiarTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int filas, columnas;
    char opcion;

    do {
        limpiarTerminal();

        // Pedir dimensiones de la matriz
        cout << "Ingrese el numero de filas y columnas de la tabla (max 50): ";
        cin >> filas >> columnas;

        // Validar dimensiones
        if (filas > max || columnas > max || filas <= 0 || columnas <= 0) {
            cout << "Dimensiones invalidas. Deben estar entre 1 y " << max << "." << endl;
            cout << "Pulse una tecla para continuar...";
            getchar();
            getchar();
            continue;
        }

        // Llenar y mostrar la tabla
        llenaTabla(filas, columnas);
        cout << "\nTabla generada:\n";
        imprimeTabla(filas, columnas);

        // Calcular sumas de las diagonales
        int sumaPrincipal = sumaDiagonalPrincipal(filas, columnas);
        int sumaSecundaria = sumaDiagonalSecundaria(filas, columnas);

        // Mostrar resultados
        cout << "\nSuma de la diagonal principal: " << sumaPrincipal << endl;
        cout << "Suma de la diagonal secundaria: " << sumaSecundaria << endl;
        cout << "Diagonal mayor: " << determinarDiagonalMayor(sumaPrincipal, sumaSecundaria) << endl;

        // Graficar diagonales
        graficarDiagonales(filas, columnas);

        cout << "\nPulse una tecla para continuar...";
        getchar();
        getchar();

        limpiarTerminal();

        cout << "Desea continuar? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    return 0;
}