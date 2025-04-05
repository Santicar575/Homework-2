#include "cajaDeAhorro.hpp"
#include <iostream>

bool CajaDeAhorro::withdraw(double amount, CuentaDeBanco* cuenta){
    if (amount <= 0) {
        std::cout << "Monto inválido para retirar." << std::endl;
        return false;
    }
    if (amount > this->balance){
        std::cout<<"No hay suficiente dinero en la caja de ahorro"<<std::endl;
        return false;
    }
    this->balance -= amount;
    std::cout<<"Se han retirado $"<<amount<<" de la caja de ahorro"<<std::endl;
    return true;
}

void CajaDeAhorro::showInfo(){
    if(this->showCounter >= this->maxShows){
        std::cout<<"Se va a realizar un descuento de 20$ ya que se ha mostrado mas de dos veces la informacion de la cuenta"<<std::endl;
        if (!this->withdraw(20)){
            std::cout<<"Hasta que no haya balance suficiente no podra ver la informacion de su cuenta"<<std::endl;
            return;
        }
    }
    std::cout<<"Caja de ahorro:\nTitular de la cuenta: "<<this->owner<<"\nBalance: "<<this->balance<<std::endl;
    if(this->showCounter < this->maxShows){
        std::cout<<"Si se muestra la informacion de la cuenta "<< this->maxShows - this->showCounter <<" veces mas se le descontaran 20$ de la cuenta"<<std::endl;
        this->showCounter++;
    }
}