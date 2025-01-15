#include <iostream>
using namespace std;
main ()
{
    int n1, n2, intervalo=0, numero;
    bool limiteInferior = false;
    bool limiteSuperior = false;
        cout << "ingresa el limite inferior: ";
        cin >> n1;
        cout << "ingresa el limite superior: ";
        cin >> n2;
        if (n1 > n2 ){
        cout << "el limite inferior no puede ser mayor que el limite superior";
        }
        while (n1>n2) {
            cout << "introduce un numero (0 para terminar): ";
            cin >> numero;
                if (numero != 0) {
                    if (numero < n1|| numero > n2) { 
                        intervalo += numero; 
                    }
                    else { limiteInferior = true; limiteSuperior = true; }
        while (numero !=0)
        cout << "la suman de los numeros fuera  del intervalo es:";
    }

}