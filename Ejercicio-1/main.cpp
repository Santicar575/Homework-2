#include "time.hpp"
#include <iostream>

int main() {
    int hour, minutes, seconds, option;
    std::string daytime;
    Time time;

    while (true) {
        std::cout << "Ingrese 1 para probar el constructor por defecto, 2 para probar el constructor con hora, "
                     "3 para probar el constructor con hora y minutos, 4 para probar el constructor con hora, minutos y segundos, "
                     "5 para probar el constructor con hora, minutos, segundos y 'a.m./p.m.': ";
        if (!(std::cin >> option)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Entrada inválida. Intente nuevamente.\n";
            continue;
        }

        try {
            switch (option) {
                case 1:
                    time = Time();
                    break;
                case 2:
                    std::cout << "Enter hour: ";
                    std::cin >> hour;
                    time = Time(hour);
                    break;
                case 3:
                    std::cout << "Enter hour: ";
                    std::cin >> hour;
                    std::cout << "Enter minutes: ";
                    std::cin >> minutes;
                    time = Time(hour, minutes);
                    break;
                case 4:
                    std::cout << "Enter hour: ";
                    std::cin >> hour;
                    std::cout << "Enter minutes: ";
                    std::cin >> minutes;
                    std::cout << "Enter seconds: ";
                    std::cin >> seconds;
                    time = Time(hour, minutes, seconds);
                    break;
                case 5:
                    std::cout << "Enter hour: ";
                    std::cin >> hour;
                    std::cout << "Enter minutes: ";
                    std::cin >> minutes;
                    std::cout << "Enter seconds: ";
                    std::cin >> seconds;
                    std::cout << "Enter 'a.m./p.m.': ";
                    std::cin >> daytime;
                    time = Time(hour, minutes, seconds, daytime);
                    break;
                default:
                    std::cout << "Opción no válida, intente nuevamente.\n";
                    continue;
            }

            while (true) {
                std::cout << "Hora en formato de 12 horas: ";
                time.getTime();
                std::cout << "Hora en formato de 24 horas: ";
                time.printTime();

                std::cout << "Para modificar la hora ingrese 1, para modificar los minutos ingrese 2, "
                             "para modificar los segundos ingrese 3, para modificar 'a.m./p.m.' ingrese 4, "
                             "para mostrar los valores individualmente ingrese 5, para imprimir la hora ingrese 6, "
                             "para salir ingrese 7: ";
                if (!(std::cin >> option)) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Entrada inválida. Intente nuevamente.\n";
                    continue;
                }

                switch (option) {
                    case 1:
                        std::cout << "Enter hour: ";
                        std::cin >> hour;
                        time.setHour(hour);
                        break;
                    case 2:
                        std::cout << "Enter minutes: ";
                        std::cin >> minutes;
                        time.setMinutes(minutes);
                        break;
                    case 3:
                        std::cout << "Enter seconds: ";
                        std::cin >> seconds;
                        time.setSeconds(seconds);
                        break;
                    case 4:
                        std::cout << "Enter 'a.m./p.m.': ";
                        std::cin >> daytime;
                        time.setDaytime(daytime);
                        break;
                    case 5:
                        std::cout << "Hour: " << time.getHour() << std::endl;
                        std::cout << "Minutes: " << time.getMinutes() << std::endl;
                        std::cout << "Seconds: " << time.getSeconds() << std::endl;
                        std::cout << "a.m./p.m.: " << time.getDaytime() << std::endl;
                        break;
                    case 6:
                        std::cout << "Hora en formato de 12 horas: ";
                        time.getTime();
                        std::cout << "Hora en formato de 24 horas: ";
                        time.printTime();
                        break;
                    case 7:
                        return 0; // Salir del programa
                    default:
                        std::cout << "Opción no válida, intente nuevamente.\n";
                        break;
                }
            }
        } catch (const char* msg) {
            std::cerr << msg << std::endl;
            std::cout << "Si desea intentarlo nuevamente, escriba 'y': ";
            char retry;
            std::cin >> retry;
            if (retry != 'y') {
                return 0; // Salir del programa
            }
        }
    }

    return 0;
}