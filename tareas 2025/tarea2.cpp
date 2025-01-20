#include <iostream>
#include <stdlib.h>//libreria para el uso de rand
#include <time.h>//libreria para el uso de time
using namespace std;
void llenaDatos (float v[], int ne){
srand (time(NULL));//funcion semilla para generar numeros
for (int i=0; i<ne; i++){
v[i] = (float)(rand() % 45 + 55) + (float)(rand() % 100) / 100; 
if (v[i]>99){
v[i]=99;
}
}
}
void verDatos (float v[], int ne){
cout <<"los elementos del vector son: "<<endl;
for (int i=0; i<ne; i++){
cout << v[i] <<" ";
}
}
float sumaPromedioCifras (float v[], int ne){
float suma=0;
for (int i=0; i<ne; i++){
suma+=v[i];
}
return (float)suma/ne;
}
int contarDebajoPromedio (float v[], int ne, float promedio){
float contar =0;
for (int i=0; i<ne; i++){
if (v[i]<promedio){
contar++;
}
}
return contar;
}
void guardaElementosmenores (float v[], int ne, float promedio, float lista []){
int j=0;
for (int i=0; i<ne; i++){
if (v[i]<promedio){
lista[j]=v[i];
j++;
}
}
}
int main () {
int ne, menores;
float promedioNumeros;
cout<< "Cuantos elemetos tiene el vector?: ";
cin>>ne;
float vector [ne];
llenaDatos (vector, ne);
verDatos (vector, ne);
promedioNumeros = sumaPromedioCifras (vector, ne);
cout << "\nEl promedio de los datos generados es= "<< promedioNumeros <<endl;
menores = contarDebajoPromedio (vector, ne, promedioNumeros);
cout << "La cantidad de elementos debajo del promedio son: " << menores <<endl;
float listaMenores [menores];
guardaElementosmenores (vector, ne, promedioNumeros, listaMenores);
verDatos (listaMenores, menores);
}
