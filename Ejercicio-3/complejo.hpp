#pragma once
#include "numero.hpp"

class Complejo : public Numero{
    private:
        double parteReal;
        double parteIm;
    public:
        Complejo(double parteReal, double parteImaginaria);
        virtual std::unique_ptr<Numero> suma(const Numero& other) const override;
        virtual std::unique_ptr<Numero> resta(const Numero& other) const override;
        virtual std::unique_ptr<Numero> multiplicacion(const Numero& other) const override;
        virtual std::string toString() override;
};