#include "time.hpp"
#include <iostream>

int main(){
    int hour,minutes,seconds,option;
    std::string daytime;
    Time time;
    choice1:
    std::cout<<"Ingrese 1 para probar el constructor por defecto, 2 para probar el constructor con hora, 3 para probar el constructor con hora y minutos, 4 para probar el constructor con hora, minutos y segundos, 5 para probar el constructor con hora, minutos, segundos y 'a.m./p.m.': ";
    std::cin>>option;
    try{
        switch(option){
            case 1:
                time = Time();
                break;
            case 2:
                std::cout<<"Enter hour: ";
                std::cin>>hour;
                time = Time(hour);
                break;
            case 3:
                std::cout<<"Enter hour: ";
                std::cin>>hour;
                std::cout<<"Enter minutes: ";
                std::cin>>minutes;
                time = Time(hour, minutes);
                break;
            case 4:
                std::cout<<"Enter hour: ";
                std::cin>>hour;
                std::cout<<"Enter minutes: ";
                std::cin>>minutes;
                std::cout<<"Enter seconds: ";
                std::cin>>seconds;
                time = Time(hour, minutes, seconds);
                break;
            case 5:
                std::cout<<"Enter hour: ";
                std::cin>>hour;
                std::cout<<"Enter minutes: ";
                std::cin>>minutes;
                std::cout<<"Enter seconds: ";
                std::cin>>seconds;
                std::cout<<"Enter 'a.m./p.m.': ";
                std::cin>>daytime;
                time = Time(hour, minutes, seconds, daytime);
                break;
            default:
                std::cout<<"Opción no válida, intente nuevamente"<<std::endl;
                goto choice1;
        }
        std::cout<<"Hora en formato de 12 horas: ";
        time.getTime();
        std::cout<<"Hora en formato de 24 horas: ";
        time.printTime();
        choice2:
        std::cout<<"Para modificar la hora ingrese 1, para modificar los minutos ingrese 2, para modificar los segundos ingrese 3, para modificar 'a.m./p.m.' ingrese 4,para mostrar los valores individualmente ingrese 5, para imprimir la hora ingrese 6, para salir ingrese 7: ";
        std::cin>>option;
        switch(option){
            case 1:
                std::cout<<"Enter hour: ";
                std::cin>>hour;
                time.setHour(hour);
                break;
            case 2:
                std::cout<<"Enter minutes: ";
                std::cin>>minutes;
                time.setMinutes(minutes);
                break;
            case 3:
                std::cout<<"Enter seconds: ";
                std::cin>>seconds;
                time.setSeconds(seconds);
                break;
            case 4:
                std::cout<<"Enter 'a.m./p.m.': ";
                std::cin>>daytime;
                time.setDaytime(daytime);
                break;
            case 5:
                std::cout<<"Hour: "<<time.getHour()<<std::endl;
                std::cout<<"Minutes: "<<time.getMinutes()<<std::endl;
                std::cout<<"Seconds: "<<time.getSeconds()<<std::endl;
                std::cout<<"a.m./p.mp: "<<time.getDaytime()<<std::endl;
                break;
            case 6:
                std::cout<<"Hora en formato de 12 horas: ";
                time.getTime();
                std::cout<<"Hora en formato de 24 horas: ";
                time.printTime();
                break;
            case 7:
                return 0;
            default:
                std::cout<<"Opción no válida, intente nuevamente"<<std::endl;
                goto choice2;
        }
        goto choice2;

    }catch(const char* msg){
        std::cerr<<msg<<std::endl;
        std::cout<<"If you want to try again, type 'y': ";
        char option;
        std::cin>>option;
        if(option=='y') goto choice1;
        return 0;
    }
    return 0;
}
