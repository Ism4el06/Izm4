#include <iostream>
#include <stdlib.h>
#include <time.h>
#define RONDAS 5
using namespace std;

void obtenerEleccionUsuario(int &eleccion) {
    cout << "Elige una opcion: 1. Piedra, 2. Papel, 3. Tijera: ";
    cin >> eleccion;
    while (eleccion < 1 || eleccion > 3) {
        cout << "Opcion invalida. Intenta de nuevo: ";
        cin >> eleccion;
    }
}

void obtenerEleccionMaquina(int &eleccion) {
    eleccion = rand() % 3 + 1;
}

int determinarGanadorRonda(int usuario, int maquina) {
    if (usuario == maquina) return 0;  // Empate
    if ((usuario == 1 && maquina == 3) || (usuario == 2 && maquina == 1) || (usuario == 3 && maquina == 2)) {
        return 1;  // Gana usuario
    }
    return -1;  // Gana máquina
}

void determinarGanadorJuego(int puntosUsuario, int puntosMaquina) {
    cout << "\nResultados finales:\n";
    cout << "Usuario: " << puntosUsuario << " - Maquina: " << puntosMaquina << endl;
    if (puntosUsuario > puntosMaquina) {
        cout << "GRANDEEEEEE LE GANASTE AL BOT GG EZ NO TEAM B).\n";
    } else if (puntosUsuario < puntosMaquina) {
        cout << "TE GANO EL BOT XDDDDDDDD.\n";
    } else {
        cout << "El juego ha terminado en empate.\n";
    }
}

int main() {
    srand(time(NULL));

    int nivel, eleccionUsuario, eleccionMaquina;
    int puntosUsuario = 0, puntosMaquina = 0;

    cout << "Seleccione nivel de dificultad (1. Principiante, 2. Intermedio, 3. Avanzado): ";
    cin >> nivel;

    switch (nivel) {
        case 2: puntosMaquina = 1; break;
        case 3: puntosMaquina = 2; break;
    }

    for (int ronda = 1; ronda <= RONDAS; ronda++) {
        cout << "\n--- Ronda " << ronda << " ---\n";
        
        obtenerEleccionUsuario(eleccionUsuario);
        obtenerEleccionMaquina(eleccionMaquina);

        cout << "La maquina eligio: ";
        switch (eleccionMaquina) {
            case 1: cout << "Piedra"; break;
            case 2: cout << "Papel"; break;
            case 3: cout << "Tijera"; break;
        }
        cout << endl;

        int resultado = determinarGanadorRonda(eleccionUsuario, eleccionMaquina);

        if (resultado == 1) {
            cout << "Ganaste esta ronda!\n";
            puntosUsuario++;
        } else if (resultado == -1) {
            cout << "La maquina gana esta ronda.\n";
            puntosMaquina++;
        } else {
            cout << "Empate en esta ronda.\n";
        }

        cout << "Puntuacion actual - Usuario: " << puntosUsuario << " Maquina: " << puntosMaquina << endl;
    }

    determinarGanadorJuego(puntosUsuario, puntosMaquina);

    return 0;
}