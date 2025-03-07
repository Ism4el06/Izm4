#include <iostream>
#include <fstream>
#include <string>  // Necesaria para usar string

using namespace std;

int main() {
    // Crear un objeto de tipo ifstream para leer el archivo
    ifstream archivoEntrada;

    // Abrir el archivo
    archivoEntrada.open("ejemplo.txt");

    // Verificar si el archivo se abrió correctamente
    if (archivoEntrada.is_open()) {
        string linea;
        
        // Leer el archivo línea por línea
        while (getline(archivoEntrada, linea)) {
            cout << "Leído: " << linea << endl;
        }

        // Cerrar el archivo
        archivoEntrada.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}