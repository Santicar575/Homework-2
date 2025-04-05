#pragma once
#include "cuentaDeBanco.hpp"

class CuentaCorriente : public CuentaDeBanco{
    public:
        using CuentaDeBanco::CuentaDeBanco;
        //Muestra el balance, el titular y el tipo de la cuenta
        void showInfo() override;
        //Extrae dinero de la cuenta, si no hay suficiente intenta extraer dinero de la caja de ahorro. Devuelve true si pudo extraerla, false de lo contrario
        bool withdraw(double money, CuentaDeBanco* cuenta) override;
};