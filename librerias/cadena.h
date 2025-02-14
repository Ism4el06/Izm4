#include <iostream>
namespace cadena{

void llenarCadena(char cad[], int n = 50) {
    std::cout << "Ingresa una cadena de caracteres: ";
    std::cin.getline(cad, n);
    std::cin.clear();
}

int longitudCadena(char cad[]) {
    int contador = 0;
    for (int i = 0; cad[i] != '\0'; i++)
        contador++;
    return contador;
}

int contarPalabras(char cad[]) {
    int palabras = 0;
    int longitudPalabra = 0;
    bool dentroDePalabra = false;

    for (int i = 0; cad[i] != '\0'; i++) {
        if (cad[i] != ' ') {
            longitudPalabra++;
            dentroDePalabra = true;
        } else {
            if (dentroDePalabra && longitudPalabra >= 2) {
                palabras++;
            }
            dentroDePalabra = false;
            longitudPalabra = 0; // Reiniciar el conteo de caracteres de la palabra
        }
    }

    // Verificar la última palabra
    if (dentroDePalabra && longitudPalabra >= 2) {
        palabras++;
    }

    return palabras;
}

int main() {
    char palabras[50];
    llenarCadena(palabras);
    std::cout << "La cadena ingresada es: " << palabras << std::endl;
    std::cout << "La longitud de la cadena es: " << longitudCadena(palabras) << std::endl;
    std::cout << "La cantidad de palabras es: " << contarPalabras(palabras) << std::endl;
}
}