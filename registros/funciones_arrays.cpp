#include <iostream>
using namespace std;
struct persona{
    int id;
    string nombre;
    int edad;
    bool casado=false;
};
void ingresarDatosRegistro(persona per[], int n){
    int i;
    char respuesta;
    for(i=0;i<n;i++){
        per[i].id=i+1;
        cout<< "Ingrese el nomrbre de la persona: ";
        cin>>per[i].nombre;
        cout<<"Ingrese la edad de la persona: ";
        cin>>per[i].edad;
        cout<< "Esta casado: <<S/N: ";
        cin.get(respuesta);
        cin.ignore();
        if(respuesta== 's' || respuesta== 'S'){
            per[i].casado=true;
        }
    }
}
void mostrarDatosRegistro(persona per[], int n){
    int i;
    cout<< "ID\tNOMBRE\tEDAD\tCASADO"<<endl;
    for(i=0; i<n;i++){
        cout<<per[i].id<<"\t";
        cout<<per[i].nombre<<"\t";
        cout<<per[i].edad<<"\t";
        cout<<per[i].casado<<endl;
    }
}
main(){
    int np;
    cout<<"Ingrese la cantidad de personas: ";
    cin>>np;
    persona personas[np];
    ingresarDatosRegistro(personas, np);
    mostrarDatosRegistro(personas, np);
}