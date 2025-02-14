#include <iostream>
using namespace std;

void cambiarString(string nombres){
    nombres = " Sin nombres ";
}
void cambiarArray(char apellido[]){
    apellido[0] = 'A';
    apellido[1] = 'B';
    apellido[2] = 'C';
    apellido[3] = 'D';
    apellido[4] = 'E';
    apellido[5] = '\0';  // Caracter nulo para indicar el final de la cadena
    cout <<"Ingresa el nuevo apellido ";
    cin.getline(apellido,20);

}
main() {  
    string nombres, apodo; 
    string curso [5] = {"C++","Java","Python","C#","PHP"};
    char apellido[20],apodo [20];  
    cout << "ingrese su nombre: ";  
    getline(cin, nombres);  
    cout << "ingrese su apellido: ";
    cin.getline(apellido, 20);  
    cout << "su apellido inicial es: " << apellido << endl;
    cambiarArray(apellido);  
    cout << "su apellido luego de llamar a la funcion es: " << apellido << endl;
}