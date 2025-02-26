#include <iostream>
using namespace std;
struct persona{
    string nombre;
    int edad;
    float estatura;
};
void funcion1(){
    
}
void ingresarRegistro(persona &per1){
    cout << "Ingrese el nombre: ";
    getline(cin, per1.nombre);
    cout << "Ingrese la edad: ";
    cin >> per1.edad;
    cout << "Ingrese la estatura: ";
    cin >> per1.estatura;
}
void mostrarRegistro(persona &per1){
    cout << "El nombre es: " << per1.nombre << endl;
    cout << "La edad es: " << per1.edad << endl;
    cout << "La estatura es: " << per1.estatura << endl;
}
int main(){
    persona per1={"", 0, 0.0};
    ingresarRegistro(per1);
    mostrarRegistro(per1);
}