#include "complejo.hpp"

Complejo::Complejo(double parteReal, double parteImaginaria) : parteReal(parteReal),parteIm(parteImaginaria){}

std::unique_ptr<Numero> Complejo::suma(const Numero& other) const{
    const Complejo* complejo = dynamic_cast<const Complejo*>(&other);
    if(complejo){
        return std::make_unique<Complejo>(Complejo(this->parteReal+complejo->parteReal,this->parteIm+complejo->parteIm));
    }
    return nullptr;
}

std::unique_ptr<Numero> Complejo::resta(const Numero& other) const{
    const Complejo* complejo = dynamic_cast<const Complejo*>(&other);
    if(complejo){
        return std::make_unique<Complejo>(Complejo(this->parteReal-complejo->parteReal,this->parteIm-complejo->parteIm));
    }   
    return nullptr;
}

std::unique_ptr<Numero> Complejo::multiplicacion(const Numero& other) const{
    const Complejo* complejo = dynamic_cast<const Complejo*>(&other);
    if(complejo){
        double nuevaParteReal = this->parteReal*complejo->parteReal - this->parteIm*complejo->parteIm;
        double nuevaParteIm = this->parteReal*complejo->parteIm + this->parteIm * complejo->parteReal;
        return std::make_unique<Complejo>(Complejo(nuevaParteReal,nuevaParteIm));
    }
    return nullptr;
}

std::string Complejo::toString(){
    std::string realStr = std::to_string(this->parteReal);
    std::string imStr = std::to_string(this->parteIm);
    std::string res;
    if(this->parteIm < 0){
        res = realStr + imStr + "i";
    }else{
        res = realStr + "+" +imStr + "i";
    }
    return res;
}