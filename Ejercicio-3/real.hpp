#pragma once
#include "numero.hpp"

class Real:public Numero{
    private:
        double value;
    public:
        Real(double num);
        virtual std::unique_ptr<Numero> suma(const Numero& other) const override;
        virtual std::unique_ptr<Numero> resta(const Numero& other) const override;
        virtual std::unique_ptr<Numero> multiplicacion(const Numero& other) const override;
        virtual std::string toString() const override;
};