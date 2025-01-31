#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void llenavector(int v[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        //v[i] = rand() % 20 + 1;
        cin>>v[i];
    }
}
void mostrarVector(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << "\t";
    }
}
int ordenaSeleccion(int v[], int n) {
    int contador = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            contador++;
            if (v[i] > v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    return contador;
}

main()
{
    int ne, comparaciones;
    cout<<"Ingrese el numero de elementos del vector: ";
    cin>>ne;
    int vector[ne];
    llenavector(vector, ne);
    cout<<"Vector original: \n";
    mostrarVector(vector, ne);
    comparaciones = ordenaSeleccion(vector, ne);
    cout<<"\nVector ordenado por seleccion: \n";
    mostrarVector(vector, ne);
    cout<<"\nEl numero de comparaciones es: "<<comparaciones<<endl;
}