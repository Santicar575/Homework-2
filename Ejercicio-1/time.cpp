#include "time.hpp"
#include <iostream>
#include <iomanip>

Time::Time(int hour, int minutes, int seconds, std::string daytime){
    //Asigno los valores a los atributos de la clase chequeando que sean válidos
    //Si no son válidos lanzo una excepción que luego será capturada en el main
    (hour>11 || hour<0) ? throw "Invalid hour" : this->hour = hour;
    (minutes>59 || minutes<0) ? throw "Invalid minutes" : this->minutes = minutes;
    (seconds>59 || seconds<0) ? throw "Invalid seconds" : this->seconds = seconds;
    (daytime=="a.m." || daytime=="p.m.") ? this->daytime = daytime : throw "Invalid daytime";
}

int Time::getHour(){
    return this->hour;
}

int Time::getMinutes(){
    return this->minutes;
}

int Time::getSeconds(){
    return this->seconds;
}

std::string Time::getDaytime(){
    return this->daytime;
}

void Time::setHour(int hour){
    (hour>11 || hour<0) ? throw "Invalid hour" : this->hour = hour;
}

void Time::setMinutes(int minutes){
    (minutes>59 || minutes<0) ? throw "Invalid minutes" : this->minutes = minutes;
}

void Time::setSeconds(int seconds){
    (seconds>59 || seconds<0) ? throw "Invalid seconds" : this->seconds = seconds;
}

void Time::setDaytime(std::string daytime){
    (daytime=="a.m." || daytime=="p.m.") ? this->daytime = daytime : throw "Invalid daytime";
}

void Time::getTime(){
    //Utilizo setfill y setw para que los números se impriman con dos dígitos
    std::cout<<std::setfill('0')<<std::setw(2)<<this->hour<<"h, "<<std::setfill('0')<<std::setw(2)<<this->minutes<<"m, "<<std::setfill('0')<<std::setw(2)<<this->seconds<<"s "<<this->daytime<<std::endl;
}

void Time::printTime(){
    int hour = this->hour;
    //Si la hora es p.m. le sumo 12 para que se imprima en formato de 24 horas
    if(this->daytime=="p.m."){
        hour+=12;
    }
    //Utilizo setfill y setw para que los números se impriman con dos dígitos
    std::cout<<std::setfill('0')<<std::setw(2)<<hour<<":"<<std::setfill('0')<<std::setw(2)<<this->minutes<<":"<<std::setfill('0')<<std::setw(2)<<this->seconds<<std::endl;
}

