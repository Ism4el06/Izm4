#include <iostream>
#include <stdexcept>

int division(int dividend, int divisor) {
    if (divisor == 0) {
        throw std::invalid_argument("División por cero no permitida");
    }
    if (dividend < divisor) {
        return 0;
    } else {
        return 1 + division(dividend - divisor, divisor);
    }
}

int main() {
    int dividend, divisor;
    std::cout << "Introduce el dividendo: ";
    std::cin >> dividend;
    std::cout << "Introduce el divisor: ";
    std::cin >> divisor;
    
    try {
        int resultado = division(dividend, divisor);
        std::cout << "El resultado de la division es: " << resultado << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
