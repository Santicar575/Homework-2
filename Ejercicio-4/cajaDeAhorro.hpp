#pragma once
#include "cuentaDeBanco.hpp"
#include "cuentaCorriente.hpp"

class CajaDeAhorro : public CuentaDeBanco{
    private:
        //Contador de veces que se muestra la informacion de la cuenta
        static const int maxShows = 2;
        int showCounter = 0;
    
    public:
        using CuentaDeBanco::CuentaDeBanco;
        //Muestra el balance, el titular y el tipo de la cuenta. Si se pide mas de dos veces se descuentan 20$ del balance
        void showInfo() override;
        //Extrae dinero de la cuenta solo si hay dinero suficiente. Devuelve true si pudo extraerla, false de lo contrario.
        bool withdraw(double money, CuentaDeBanco* cuenta = nullptr) override;

    friend CuentaCorriente;
};