#include "real.hpp"

Real::Real(double num) : value(num){}

std::unique_ptr<Numero> Real::suma(const Numero& other) const{
    const Real* real = dynamic_cast<const Real*>(&other);
    if(real){
        return std::make_unique<Real>(value + real->value);
    }
    return nullptr;
}

std::unique_ptr<Numero> Real::resta(const Numero& other) const{
    const Real* real = dynamic_cast<const Real*>(&other);
    if(real){
        return std::make_unique<Real>(value - real->value);
    }
    return nullptr;
}

std::unique_ptr<Numero> Real::multiplicacion(const Numero& other) const{
    const Real* real = dynamic_cast<const Real*>(&other);
    if(real){
        return std::make_unique<Real>(value*real->value);
    }
    return nullptr;
}

std::string Real::toString() const{
    return std::to_string(this->value);
}