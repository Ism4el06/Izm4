#include <iostream>
#include <fstream>  // Necesaria para manejar archivos
using namespace std;

int main() {
    // Crear un objeto de tipo ofstream para escribir en el archivo
    ofstream archivoSalida;

    // Abrir el archivo (si no existe, se creará)
    archivoSalida.open("ejemplo.txt");

    // Verificar si el archivo se abrió correctamente
    if (archivoSalida.is_open()) {
        // Escribir texto en el archivo
        archivoSalida << "Hola, mundo!" << endl;
        archivoSalida << "Esto es una prueba." << endl;
        archivoSalida << "Línea 3." << endl;

        // Cerrar el archivo
        archivoSalida.close();
        
        cout << "Texto escrito en el archivo con éxito." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}