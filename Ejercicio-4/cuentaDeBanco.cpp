#include "cuentaDeBanco.hpp"
#include <iostream>

CuentaDeBanco::CuentaDeBanco(std::string owner, double balance) : owner(owner),balance(balance){}

void CuentaDeBanco::deposit(double amount){
    this->balance += amount;
}
