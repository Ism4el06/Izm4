#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Crear un objeto de tipo ofstream
    ofstream archivoSalida;

    // Abrir el archivo en modo "append" (agregar al final)
    archivoSalida.open("ejemplo.txt", ios::app);

    // Verificar si el archivo se abrió correctamente
    if (archivoSalida.is_open()) {
        archivoSalida << "Línea agregada al final." << endl;
        archivoSalida << "Otra línea más." << endl;
        
        archivoSalida.close();
        cout << "Texto agregado con éxito." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}