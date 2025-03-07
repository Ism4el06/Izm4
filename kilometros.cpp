#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Estructura para almacenar los datos de cada conductor.
struct Conductor {
    string nombre;
    vector<int> kms;  // Kilometros recorridos cada dia.
    int total_kms;    // Kilometros totales recorridos.
};

int main() {
    int n_conductores = 5;  // Numero de conductores.
    int dias = 7;  // Dias de la semana.
    vector<string> dias_semana = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};

    // Vector de conductores.
    vector<Conductor> conductores(n_conductores);

    // Nombres predefinidos de los conductores.
    vector<string> nombres = {"Carlos", "Ana", "Pedro", "Luis", "Jose"};
    
    for (int i = 0; i < n_conductores; i++) {
        conductores[i].nombre = nombres[i];
        conductores[i].kms.resize(dias);
        conductores[i].total_kms = 0;
    }

    // Generar kilometros aleatorios para cada conductor y cada dia.
    for (int i = 0; i < n_conductores; i++) {
        for (int j = 0; j < dias; j++) {
            conductores[i].kms[j] = rand() % 121 + 30;  // Kilometros aleatorios entre 30 y 150.
            conductores[i].total_kms += conductores[i].kms[j];
        }
    }

    // Igualar el kilometraje de "Jose" al de "Pedro".
    conductores[4].total_kms = conductores[2].total_kms;

    // Ordenar los conductores en orden descendente segun el total de kilometros recorridos usando burbuja.
    for (int i = 0; i < n_conductores - 1; i++) {
        for (int j = 0; j < n_conductores - i - 1; j++) {
            if (conductores[j].total_kms < conductores[j + 1].total_kms) {
                swap(conductores[j], conductores[j + 1]);
            }
        }
    }

    // Mostrar los kilometros totales recorridos por cada conductor en orden descendente.
    cout << "\nTabla de kilometros recorridos por cada conductor:\n";
    cout << setw(15) << "Conductor";
    for (const auto &dia : dias_semana) {
        cout << setw(10) << dia;
    }
    cout << setw(15) << "Total km" << endl;

    for (const auto &conductor : conductores) {
        cout << setw(15) << conductor.nombre;
        for (int j = 0; j < dias; j++) {
            cout << setw(10) << conductor.kms[j];
        }
        cout << setw(15) << conductor.total_kms << endl;
    }

    // Encontrar al conductor con el mayor numero de kilometros recorridos.
    int max_kms = conductores[0].total_kms;
    string max_nombre = conductores[0].nombre;

    cout << "\nConductor con mas kilometros recorridos: " << max_nombre << " con " << max_kms << " km.\n";

    // Mostrar los resultados graficamente.
    cout << "\nRepresentacion grafica de los kilometros recorridos:\n";
    for (const auto &conductor : conductores) {
        cout << setw(15) << conductor.nombre << ": ";
        for (int j = 0; j < conductor.total_kms; j += 10) {  // Cada 10 km representados por un '*'
            cout << "*";
        }
        cout << " (" << conductor.total_kms << " km)\n";
    }

    return 0;
}