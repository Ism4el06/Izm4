#include <iostream>
using namespace std;
void llenaVector (int vector[], int tamaño){
    for (int i=0;i<tamaño;i++){
        cout<<"Ingrese el valor del elemento ["<<i+1<<": ";
        cin>>vector[i];
    }
}
void verVector (int vector[], int tamaño){
    for (int i=0;i<tamaño;i++){
        cout<<"Elemento ["<<i+1<<"del vector es: "<<vector[i]<<endl;
    }
}
main()
{
    int ne;
    cout<<"Cuanros elementos tiene el vector?: ";
    cin>>ne;
    int vector[ne];
    llenaVector(vector, ne);
    verVector(vector, ne);
}