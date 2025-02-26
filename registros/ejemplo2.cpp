#include <iostream>
#include <stdio.h>
using namespace std;
void funcion1(int *punteroa){
    *punteroa = 300;

}
int main(){
    int a;
    int *punteroa;
    punteroa = &a;
    printf("Ingrese un numero: ");
    scanf("%d",&a);
    printf("El numero ingresado es: %d\n",a);
    printf("El numero ingresado es: %d\n", *punteroa);
    *punteroa = 200;
    printf("El numero ahora en a es: %d\n",a);
    funcion1(&a);
    printf("El numero ahora en a es: %d\n",a);
    return 0;
}