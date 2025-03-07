#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Crear un objeto de tipo fstream
    fstream archivo;
    string frase;

    // Pedir al usuario una frase para agregar al archivo
    cout << "Escribe una frase para agregar al archivo: ";
    getline(cin, frase);

    // Abrir el archivo en modo escritura (append)
    archivo.open("ejemplo.txt", ios::out | ios::app);
    if (archivo.is_open()) {
        archivo << frase << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para escribir." << endl;
    }

    // Abrir el archivo en modo lectura
    archivo.open("ejemplo.txt", ios::in);
    if (archivo.is_open()) {
        string linea;
        cout << "Contenido del archivo:" << endl;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para leer." << endl;
    }

    return 0;
}