#include <iostream>
using namespace std;
void deportes(string deportes[]){
    string deportesx[5] = {"futbol","tenis","baloncesto","voley","natacion"}; 
    for(int i=0;i<5;i++){
        deportes[i] = deportesx[i];
    }     
}
void animales(string animales[]){
    string animalesx[5] = {"perro","gato","conejo","tigre","leon"};
    for (int i = 0; i < 5; i++)
       animales[i] = animalesx[i];    
}
void frutas(string frutas[]){
    string frutasx[5] = {"manzana","naranja","pera","platano","uva"};
    for(int i=0;i<5;i++)
        frutas[i] = frutasx[i];
}
void paises(string paises[]){
    string paisesx[5] = {"mexico","argentina","brasil","chile","colombia"};
    for(int i=0;i<5;i++)
    paises[i] = paisesx[i];
}
void vehiculos (string vehiculos[]){
    string vehiculosx[5] = {"coche","moto","bicicleta","avion","barco"};
    for(int i=0;i<5;i++)
    vehiculos[i]= vehiculosx[i];
}
string palabraAleatoria(string palabras[]){
    srand(time(NULL));
    int numero = rand() % 5;
    return palabras[numero];
}
void humano(int intento){
    cout<<"Intento: "<<intento<<endl;
    system("pause");
    switch(intento){
        case 1:
    cout << "   +---+" << endl;
    cout << "   |   |" << endl;
    cout << "       |" << endl;
    cout << "       |" << endl;
    cout << "       |" << endl;
    cout << "       |" << endl;
    break;
  case 2:
    cout << "   +---+" << endl;
    cout << "   |   |" << endl;
    cout << "   O   |" << endl;
    cout << "       |" << endl;
    cout << "       |" << endl;
    cout << "       |" << endl;
    break;
  case 3:
    cout << "   +---+" << endl;
    cout << "   |   |" << endl;
    cout << "   O   |" << endl;
    cout << "   |   |" << endl;
    cout << "       |" << endl;
    cout << "       |" << endl;
    break;
  case 4:
    cout << "   +---+" << endl;
    cout << "   |   |" << endl;
    cout << "   O   |" << endl;
    cout << "  /|   |" << endl;
    cout << "       |" << endl;
    cout << "       |" << endl;
    break;
  case 5:
    cout << "   +---+" << endl;
    cout << "   |   |" << endl;
    cout << "   O   |" << endl;
    cout << "  /|\\  |" << endl;
    cout << "       |" << endl;
    cout << "       |" << endl;
    break;
  case 6:
    cout << "   +---+" << endl;
    cout << "   |   |" << endl;
    cout << "   O   |" << endl;
    cout << "  /|\\  |" << endl;
    cout << "  /    |" << endl;
    cout << "       |" << endl;
    break;
  case 7:
    cout << "   +---+" << endl;
    cout << "   |   |" << endl;
    cout << "   O   |" << endl;
    cout << "  /|\\  |" << endl;
    cout << "  / \\  |" << endl;
    cout << "       |" << endl;
    break;       
    }    
    system("pause");    
}
void jugar(string palabraSeleccionada){    
    int longitud = palabraSeleccionada.length();
    string palabraOculta(longitud, '_');
    int intentos = 0;
    char letra;
    bool bandera;
    while (intentos < 7 && palabraOculta != palabraSeleccionada) {
       bandera=false;
       cout << "Palabra: " << palabraOculta << endl;
       cout << "Intentos restantes: " << 7 - intentos << endl;
       cout << "Ingresa una letra: ";
       cin.ignore();
       cin.get(letra);
       for (int i = 0; i < longitud; i++) {   
           if (palabraSeleccionada[i] == letra) {
               palabraOculta[i] = letra;
               bandera=true;
           }            
       }
       if(!bandera){
           intentos++;
           humano(intentos);
       } 
       system("cls");       
   }
   if (palabraOculta == palabraSeleccionada) {
       cout << "Felicidades, has adivinado: " << palabraOculta << endl;
   } else {    
       cout << "Has agotado tus intentos. La palabra era: " << palabraSeleccionada << endl;
   }
}
int opciones(){
   int op;
   cout << "1. Deportes" << endl;
   cout <<"2. Animales" << endl;
   cout << "3. Frutas" << endl;
   cout << "4. Paises " << endl;
   cout << "5. Vehiculos"<< endl;
   cout<<"Esoja una opcion: ";
   cin >> op;
   return op;
}