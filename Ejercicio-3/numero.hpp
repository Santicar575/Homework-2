#pragma once
#include <string>
#include <memory>

class Numero{
    public:
        virtual std::unique_ptr<Numero> suma(const Numero& other) const = 0;
        virtual std::unique_ptr<Numero> resta(const Numero& other) const = 0;
        virtual std::unique_ptr<Numero> multiplicacion(const Numero& other) const = 0;
        virtual std::string toString() = 0;
};