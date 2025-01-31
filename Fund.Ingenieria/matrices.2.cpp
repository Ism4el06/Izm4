#include <stdio.h>
#include <stdlib.h>

int main() {
    int habitantesVivienda[5][25] = {0};
    
    habitantesVivienda[3][24] = 4;

    printf("El numero de habitantes del piso 24 de la vivienda 3 es: %d", habitantesVivienda[3][24]);
    return 0;//Ejemplo de matrices
}

