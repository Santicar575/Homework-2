#include <iostream>
#include "cajaDeAhorro.hpp"
#include "cuentaCorriente.hpp"

int main() {
    std::cout<<"Ingrese el nombre del titular de la cuenta: ";
    std::string owner;
    std::getline(std::cin, owner);
    std::cout<<"Ingrese el balance de la cuenta corriente: ";
    double balance;
    while(!(std::cin>>balance)){
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout<<"Error, ingrese un numero: ";
    }
    CuentaCorriente cuentaCorriente(owner, balance);
    std::cout<<"Ingrese el balance de la caja de ahorro: ";
    while(!(std::cin>>balance)){
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout<<"Error, ingrese un numero: ";
    }
    CajaDeAhorro cajaDeAhorro(owner, balance);
    int option;
    do{
        std::cout<<"\nOpciones:\n1. Mostrar la informacion de la cuenta corriente\n2. Mostrar la informacion de la caja de ahorro\n3. Retirar dinero de la cuenta corriente\n4. Retirar dinero de la caja de ahorro\n5. Ingresar dinero en la cuenta corriente\n6. Ingresar dinero en la caja de ahorro\n0. Salir: ";
        if(!(std::cin >> option)){
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            option = -1;
        }
        switch(option){
            case 1:
                cuentaCorriente.showInfo();
                break;
            case 2:
                cajaDeAhorro.showInfo();
                break;
            case 3:
                std::cout<<"Ingrese el monto a retirar: ";
                std::cin>>balance;
                cuentaCorriente.withdraw(balance, &cajaDeAhorro);
                break;
            case 4:
                std::cout<<"Ingrese el monto a retirar: ";
                std::cin>>balance;
                cajaDeAhorro.withdraw(balance);
                break;
            case 5:
                std::cout<<"Ingrese el monto a ingresar: ";
                std::cin>>balance;
                cuentaCorriente.deposit(balance);
                break;
            case 6:
                std::cout<<"Ingrese el monto a ingresar: ";
                std::cin>>balance;
                cajaDeAhorro.deposit(balance);
                break;
            case 0:
                std::cout<<"Saliendo..."<<std::endl;
                break;
            default:
                std::cout<<"Opcion invalida"<<std::endl;
        }
        
    }while(option != 0);

    return 0;
}