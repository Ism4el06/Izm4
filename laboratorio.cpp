#include <cstdlib>
#include "librerias/laboratorio.h"
using namespace std;
int main() {
    int opcion;
    bool clearScreen = true;
    do {
        if (clearScreen) {
            system("cls");  
        }
        cout << "\nMenu:\n"
        << "1. Anadir Registro\n"
        << "2. Modificar Registro\n"
        << "3. Eliminar Registro\n"
        << "4. Procesar Datos\n"
        << "5. Salir\n"
        << "Opcion: ";
   cin >> opcion;
   switch (opcion) {
       case 1:
           anadirRegistro();
           clearScreen = true;
           break;
       case 2:
           modificarRegistro();
           clearScreen = true;
           break;
       case 3:
           eliminarRegistro();
           clearScreen = true;
           break;
       case 4:
           procesarDatos();
           clearScreen = true;  
           break;
       case 5:
           cout << "Saliendo...\n";
           break;
       default:
           cout << "Opcion invalida.\n";
           clearScreen = true;
   } 
        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
    } while (opcion != 5);

    return 0;
}


        
