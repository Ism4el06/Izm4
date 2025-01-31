//factorial.h

#ifndef FACTORIAL_H
#define FACTORIAL_H

//Declaracion de la funcion factorial
int calcularfactorial(int num);

//Definicion de la funcion factorial
int calcularfactorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * calcularfactorial(num - 1);
    }
}

#endif  // FACTORIAL_H