#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ordenar_palabras_desc(vector<string>& palabras) {
    for (size_t i = 0; i < palabras.size(); ++i) {
        for (size_t j = i + 1; j < palabras.size(); ++j) {
            if (palabras[j].length() > palabras[i].length()) {
                swap(palabras[i], palabras[j]);
            }
        }
    }
}

string procesar_cadena(const string& cadena) {
    vector<string> palabras;
    size_t inicio = 0, fin;
    while ((fin = cadena.find(' ', inicio)) != string::npos) {
        palabras.push_back(cadena.substr(inicio, fin - inicio));
        inicio = fin + 1;
    }
    palabras.push_back(cadena.substr(inicio));
    
    ordenar_palabras_desc(palabras);
    
    string resultado;
    for (size_t i = 0; i < palabras.size(); ++i) {
        if (i > 0) resultado += " ";
        resultado += palabras[i];
    }
    
    return resultado;
}

int main() {
    string cadena_original = "uno quince doce";
    string cadena_resultado = procesar_cadena(cadena_original);
    
    cout << "Cadena original: " << cadena_original << endl;
    cout << "\nCadena resultado = " << cadena_resultado << "." << endl;
    
    return 0;
}