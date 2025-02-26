#include <iostream>
#include <string>
using namespace std;

void cadenaRempl(string &cadena, const string &buscar, const string &reemplazar) {
    size_t pos = cadena.find(buscar);
    if (pos != string::npos) {
        cadena.replace(pos, buscar.size(), reemplazar);
        cout << "Resultado: " << cadena << endl;
    } else {
        cout << "La frase objetivo no se encontró en la cadena principal." << endl;
    }
}

int main() {
    string cadena, buscar, reemplazar;
    char opcion;

    cout << "Ingresa la cadena principal: ";
    getline(cin, cadena);

    do {
        cout << "Cadena actual: " << cadena << endl;
        
        cout << "Ingresa la frase objetivo a reemplazar: ";
        getline(cin, buscar);

        if (cadena.find(buscar) == string::npos) {
            cout << "Error: La frase objetivo no se encuentra en la cadena." << endl;
            continue;
        }

        cout << "Ingresa la frase que reemplazara '" << buscar << "': ";
        getline(cin, reemplazar);

        cadenaRempl(cadena, buscar, reemplazar);

        cout << "¿Quieres intentar otro reemplazo? (s/n): ";
        cin >> opcion;
        cin.ignore(); 

    } while (opcion == 's' || opcion == 'S');

    cout << "Programa terminado." << endl;
    return 0;
}
