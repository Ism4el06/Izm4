#include <cstdio> //Incluir libreria para printf
#include "factorial.h" //Incluir la libreria factorial

int main () {
    //Declaracion de variable locales
    int num, resultado;

    //Solicitar al usuario que ingrese un numero
    printf("Ingrese un numero para calcular el factorial: ");
    scanf("%d", &num);

    //LLamada a la funcion factorial desde la libreria
    resultado = calcularfactorial(num);

    //Mostrar el resultado
    printf("El factorial de %d es: %d\n", num, resultado);

    return 0;
}