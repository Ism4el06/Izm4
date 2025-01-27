#include <iostream>
using namespace std;

void identificarTipoCadena(char cadena[], int longitud, int &esNumerica, int &esAlfabetica, int &esAlfanumerica) {
    esNumerica = 1;
    esAlfabetica = 1;
    esAlfanumerica = 1;

    for (int i = 0; i < longitud; i++) {
        if (cadena[i] >= '0' && cadena[i] <= '9') {
            esAlfabetica = 0;
        }
        else if ((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z')) {
            esNumerica = 0;
        }
        else {
            esNumerica = 0;
            esAlfabetica = 0;
            esAlfanumerica = 0;
            break;
        }
    }
}

int main() {
    char cadena[50];
    int esNumerica, esAlfabetica, esAlfanumerica;

    cout << "Ingrese una cadena de caracteres: ";
    cin >> cadena;

   
    int longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;
    }

    identificarTipoCadena(cadena, longitud, esNumerica, esAlfabetica, esAlfanumerica);

    if (esNumerica) {
        cout << "La cadena es NUMERICA." << endl;
    } 
    else if (esAlfabetica) {
        cout << "La cadena es ALFABETICA." << endl;
    } 
    else if (esAlfanumerica) {
        cout << "La cadena es ALFANUMERICA." << endl;
    } 
    else {
        cout << "La cadena contiene caracteres no validos." << endl;
    }

    return 0;
}