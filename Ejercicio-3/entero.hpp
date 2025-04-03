#pragma once
#include "numero.hpp"

class Entero : public Numero {
    private:
        int value;
    public:
        Entero(int num);
        virtual std::unique_ptr<Numero> suma(const Numero& other) const override;
        virtual std::unique_ptr<Numero> resta(const Numero& other) const override;
        virtual std::unique_ptr<Numero> multiplicacion(const Numero& other) const override;
        virtual std::string toString() override;
};