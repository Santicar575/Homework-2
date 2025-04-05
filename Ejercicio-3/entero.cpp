#include "entero.hpp"

Entero::Entero(int num) : value(num){}

std::unique_ptr<Numero> Entero::suma(const Numero& other) const{
    const Entero* entero = dynamic_cast<const Entero*>(&other);
    if(entero){
        return std::make_unique<Entero>(value + entero->value);
    }
    return nullptr;
}

std::unique_ptr<Numero> Entero::resta(const Numero& other) const{
    const Entero* entero = dynamic_cast<const Entero*>(&other);
    if(entero){
        return std::make_unique<Entero>(value - entero->value);
    }
    return nullptr;
}

std::unique_ptr<Numero> Entero::multiplicacion(const Numero& other) const{
    const Entero* entero = dynamic_cast<const Entero*>(&other);
    if(entero){
        return std::make_unique<Entero>(value*entero->value);
    }
    return nullptr;
}

std::string Entero::toString() const{
    return std::to_string(this->value);
}