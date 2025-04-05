#pragma once
#include <string>

class CuentaDeBanco{
    protected:
        //El titular de la cuenta y el balance son protected ya que quiero que los puedan usar las clases derivadas pero que sean privados. Si fueran private las clases derivadas no tendrian acceso mediante la herencia.
        std::string owner;
        double balance;

    public:
        CuentaDeBanco(std::string owner, double balance=0);
        virtual void deposit(double amount);//Como depositar es lo mismo para todas las cajas no es necesario que sea un metodo abstracto puro, ya que en la clase base se puede implementar    
        virtual void showInfo() = 0;//El metodo showInfo es puro porque cada cuenta tiene su propia forma de mostrar la informacion
        virtual bool withdraw(double amount, CuentaDeBanco* cuenta) = 0;//El metodo withdraw es puro porque cada cuenta tiene su propia forma de retirar dinero
};