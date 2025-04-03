#include "complejo.hpp"
#include "real.hpp"
#include "entero.hpp"
#include <iostream>

int main() {
    // Prueba con Enteros
    Entero entero1(5);
    Entero entero2(3);

    auto sumaEntero = entero1.suma(entero2);
    auto restaEntero = entero1.resta(entero2);
    auto multiplicacionEntero = entero1.multiplicacion(entero2);

    std::cout << "Entero 1: " << entero1.toString() << std::endl;
    std::cout << "Entero 2: " << entero2.toString() << std::endl;
    std::cout << "Suma de enteros: " << sumaEntero->toString() << std::endl;
    std::cout << "Resta de enteros: " << restaEntero->toString() << std::endl;
    std::cout << "Multiplicación de enteros: " << multiplicacionEntero->toString() << std::endl;

    // Prueba con Reales
    Real real1(5.5);
    Real real2(3.2);

    auto sumaReal = real1.suma(real2);
    auto restaReal = real1.resta(real2);
    auto multiplicacionReal = real1.multiplicacion(real2);

    std::cout << "\nReal 1: " << real1.toString() << std::endl;
    std::cout << "Real 2: " << real2.toString() << std::endl;
    std::cout << "Suma de reales: " << sumaReal->toString() << std::endl;
    std::cout << "Resta de reales: " << restaReal->toString() << std::endl;
    std::cout << "Multiplicación de reales: " << multiplicacionReal->toString() << std::endl;

    // Prueba con Complejos
    Complejo complejo1(2.0, 3.0); // 2 + 3i
    Complejo complejo2(1.0, 4.0); // 1 + 4i

    auto sumaComplejo = complejo1.suma(complejo2);
    auto restaComplejo = complejo1.resta(complejo2);
    auto multiplicacionComplejo = complejo1.multiplicacion(complejo2);

    std::cout << "\nComplejo 1: " << complejo1.toString() << std::endl;
    std::cout << "Complejo 2: " << complejo2.toString() << std::endl;
    std::cout << "Suma de complejos: " << sumaComplejo->toString() << std::endl;
    std::cout << "Resta de complejos: " << restaComplejo->toString() << std::endl;
    std::cout << "Multiplicación de complejos: " << multiplicacionComplejo->toString() << std::endl;

    return 0;
}