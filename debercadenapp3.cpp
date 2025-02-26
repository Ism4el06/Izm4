#include <iostream>
using namespace std;

void llenarCadena(char cad[], int n = 50) {
    cout << "Ingresa una cadena de caracteres: ";
    cin.getline(cad, n);
}

int longitudCadena(const char cad[]) {
    int contador = 0;
    while (cad[contador] != '\0') {
        contador++;
    }
    return contador;
}

int contarPalabras(const char cad[]) {
    int palabras = 0;
    bool dentroDePalabra = false;

    for (int i = 0; cad[i] != '\0'; i++) {
        if (cad[i] != ' ' && cad[i] != '\t') {
            if (!dentroDePalabra) {
                palabras++;
                dentroDePalabra = true;
            }
        } else {
            dentroDePalabra = false;
        }
    }

    return palabras;
}

int main() {
    char palabras[50];
    llenarCadena(palabras);
    
    cout << "La cadena ingresada es: " << palabras << endl;
    cout << "La longitud de la cadena es: " << longitudCadena(palabras) << endl;
    cout << "La cantidad de palabras es: " << contarPalabras(palabras) << endl;

    return 0;
}
