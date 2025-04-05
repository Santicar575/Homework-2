#include <iostream>
#include "cuentaCorriente.hpp"
#include "cajaDeAhorro.hpp"

void CuentaCorriente::showInfo(){
    std::cout<<"Cuenta Corriente:\nTitular de la cuenta: "<<this->owner<<"\nBalance: "<<this->balance<<std::endl;
}

bool CuentaCorriente::withdraw(double amount,CuentaDeBanco* cuenta){
    if (amount <= 0) {
        std::cout << "Monto inválido para retirar." << std::endl;
        return false;
    }
    if(amount > this->balance){
        if (!cuenta) {
            std::cout << "No hay fondos suficientes y no se especificó una caja de ahorro." << std::endl;
            return false;
        }
        CajaDeAhorro* cajaDeAhorro = dynamic_cast<CajaDeAhorro*>(cuenta);
        if(cajaDeAhorro){
            double newAmount = amount - this->balance;
            std::cout<<"El dinero en la cuenta corriente no es suficiente, se va a tratar de retirar $"<<newAmount<<" de la caja de ahorro"<<std::endl;
            if(!cajaDeAhorro->withdraw(newAmount)){
                std::cout<<"No hay suficiente dinero disponible"<<std::endl;
                return false;
            }
            this->balance = 0;
            return true;
        }
    }
    this->balance -= amount;
    std::cout<<"Se han retirado $"<<amount<<" de la cuenta corriente"<<std::endl;
    return true;
}