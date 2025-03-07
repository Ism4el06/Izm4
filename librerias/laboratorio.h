#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

struct Estudiante {
    int id;
    string nombres;
    float nota1, nota2, nota3, promedio, z;
    char categoria;
};

vector<Estudiante> estudiantes;
int id_counter = 1;

void anadirRegistro() {
    Estudiante est;
    est.id = id_counter++;
    cout << "Ingrese nombre: "; cin.ignore(); getline(cin, est.nombres);
    do {
        cout << "Ingrese nota 1 (0-20): "; cin >> est.nota1;
    } while (est.nota1 < 0 || est.nota1 > 20);
    do {
        cout << "Ingrese nota 2 (0-20): "; cin >> est.nota2;
    } while (est.nota2 < 0 || est.nota2 > 20);
    do {
        cout << "Ingrese nota 3 (0-20): "; cin >> est.nota3;
    } while (est.nota3 < 0 || est.nota3 > 20);
    est.promedio = (est.nota1 + est.nota2 + est.nota3) / 3.0;
    estudiantes.push_back(est);
    cout << "Registro agregado!\n";
}

void modificarRegistro() {
    int id;
    cout << "Ingrese ID del estudiante a modificar: "; cin >> id;
    for (auto &est : estudiantes) {
        if (est.id == id) {
            cout << "Modificar (1: Nombre, 2: Nota1, 3: Nota2, 4: Nota3): ";
            int opcion; cin >> opcion;
            switch(opcion) {
                case 1: cout << "Nuevo nombre: "; cin.ignore(); getline(cin, est.nombres); break;
                case 2: do { cout << "Nueva Nota 1 (0-20): "; cin >> est.nota1; } while (est.nota1 < 0 || est.nota1 > 20); break;
                case 3: do { cout << "Nueva Nota 2 (0-20): "; cin >> est.nota2; } while (est.nota2 < 0 || est.nota2 > 20); break;
                case 4: do { cout << "Nueva Nota 3 (0-20): "; cin >> est.nota3; } while (est.nota3 < 0 || est.nota3 > 20); break;
                default: cout << "Opción no valida.\n"; return;
            }
            est.promedio = (est.nota1 + est.nota2 + est.nota3) / 3.0;
            cout << "Registro modificado!\n";
            return;
        }
    }
    cout << "ID no encontrado.\n";
}

void eliminarRegistro() {
    int id;
    cout << "Ingrese ID del estudiante a eliminar: "; cin >> id;
    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        if (it->id == id) {
            estudiantes.erase(it);
            cout << "Registro eliminado!\n";
            return;
        }
    }
    cout << "ID no encontrado.\n";
}

void procesarDatos() {
    if (estudiantes.empty()) {
        cout << "No hay registros.\n";
        return;
    }
    float suma = 0, sumaCuadrados = 0;
    for (const auto &est : estudiantes) suma += est.promedio;
    float media = suma / estudiantes.size();
    for (const auto &est : estudiantes) sumaCuadrados += pow(est.promedio - media, 2);
    float varianza = sumaCuadrados / estudiantes.size();
    float desviacion = sqrt(varianza);
    
    for (auto &est : estudiantes) {
        est.z = (est.promedio - media) / desviacion;
        if (est.z > 1) est.categoria = 'A';
        else if (est.z <= 1 && est.z > 0) est.categoria = 'B';
        else if (est.z <= 0 && est.z > -1) est.categoria = 'C';
        else est.categoria = 'D';
    }
    
    cout << "\nLista de Estudiantes:\n";
    cout << left << setw(5) << "ID" << setw(20) << "Nombre" << setw(8) << "Nota1" << setw(8) << "Nota2" << setw(8) << "Nota3" << setw(10) << "Promedio" << setw(10) << "Categoria" << "\n";
    cout << string(65, '-') << "\n";
    for (const auto &est : estudiantes) {
        cout << left << setw(5) << est.id << setw(20) << est.nombres << setw(8) << est.nota1 << setw(8) << est.nota2 << setw(8) << est.nota3 << setw(10) << est.promedio << setw(10) << est.categoria << "\n";
    }
    
    cout << "\nMedia Aritmetica: " << media << "\n";
    cout << "Desviacion Estandar: " << desviacion << "\n";
}
