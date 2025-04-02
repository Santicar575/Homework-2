#include <iostream>
#include "course.hpp"
#include "student.hpp"


int main(){
    Course course("Prueba");
    int option;
    do {
        std::cout << "1. Inscribir estudiante\n2. Desinscribir estudiante\n3. Verificar inscripción\n4. Verificar si el curso está completo\n5. Mostrar estudiantes\n6. Copiar Curso\n7. Salir\nIngrese una opción: ";
        std::cin >> option;
        switch (option) {
            case 1:{
                std::string nombre;
                int id;
                std::cout << "Nombre: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout << "Legajo: ";
                std::cin >> id;
                try{
                    auto student = std::make_unique<Student>(Student(nombre, id));
                    (course.addStudent(std::move(student))) ? std::cout<<"El estduiante fue inscripto correctamente"<<std::endl : std::cout<<"El estudiante ya se encuentra en el curso"<<std::endl;
                } catch (const char* msg){
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 2:{
                int id;
                std::cout << "Legajo a desinscribir: ";
                std::cin >> id;
                (course.removeStudent(id)) ? std::cout<<"El estduiante fue eliminado correctamente"<<std::endl : std::cout<<"El estudiante no se encuentra en el curso"<<std::endl;
                break;
            }
            case 3:{
                int id;
                std::cout << "Legajo a verificar: ";
                std::cin >> id;
                std::cout << ((course.searchStudent(id) == -1) ? "No Inscripto" : "Inscripto") << "\n";
                break;
            }
            case 4:
                std::cout << (course.isFull() ? "Curso completo" : "Cupos disponibles") << "\n";
                break;
            
            case 5:
                std::cout << course; // Uso el operador de salida sobrecargado para mostrar los estudiantes
                break;
            
            case 6:{
                std::cout << "Creando una copia del curso...\n";
                Course copiedCourse = course; // Crear una copia del curso usando el constructor de copia
                std::cout << "Estudiantes en el curso copiado:\n";
                std::cout << course; // Mostrar los estudiantes del curso copiado
                break;
            }
            case 7:
                std::cout << "Saliendo...\n";
                break;
            
            default:
                std::cout << "Opción inválida.\n";
        }
        std::cout << "-----------------------------------\n";
    }while (option != 7);

    return 0;
}