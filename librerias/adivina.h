#include <stdlib.h>
#include <time.h>
#include <iostream>
namespace adivinanza{
    void llenarVector(int ri, int rs, int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % (rs - ri + 1) + ri;
    }
}

void adivinarNumero(int ri, int rs) {
    int numeroAdivinado = rand() % (rs - ri + 1) + ri;
    int intento, intentosRestantes = 3;

    std::cout << "\n¡Adivina el número! Tienes 3 intentos." << std::endl;

    while (intentosRestantes > 0) {
        std::cout << "\nIntento " << (4 - intentosRestantes) << " de 3. Ingresa tu intento: ";
        std::cin >> intento;

        if (intento == numeroAdivinado) {
            std::cout << "¡Felicidades! Has adivinado el numero." << std::endl;
            return;
        } else if (intento < numeroAdivinado) {
            std::cout << "El numero es mayor. Te quedan " << --intentosRestantes << " intentos." << std::endl;
        } else {
            std::cout << "El numero es menor. Te quedan " << --intentosRestantes << " intentos." << std::endl;
        }
    }

    std::cout << "\nNo te quedan intentos crack. El numero correcto era: " << numeroAdivinado << std::endl;
}

}