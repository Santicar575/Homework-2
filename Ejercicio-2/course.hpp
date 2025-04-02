#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>
#include "student.hpp"

class Course{
    private:
        static const int maxCapacity = 20;
        std::string name;
        std::vector<std::unique_ptr<Student>> students;
        int currentCapacity = 0;
    public:
        Course(std::string name);
        //Creo otro constructor para poder realizar copias de cursos
        Course(const Course& other);

        std::string getName();
        void setName(std::string name);

        //Retorna true si el estudiante fue incertado correctamente, false de lo contrario
        bool addStudent(std::unique_ptr<Student> student);
        //Retorna true si el estudiante fue incertado correctamente, false de lo contrario
        bool addStudent(std::string name, int id);

        //Retorna la posicion del alumno en el vector de estudiantes o -1 si no lo encontro
        int searchStudent(int id);

        //Retorna true si el estudiante fue eliminado correctamente, false de lo contrario
        bool removeStudent(int id);

        //Imprime la lista dde estudiantes en orden alfabetico
        void printStudents();

        //Retorna true si el curso esta completo, false de lo contrario
        bool isFull();

        friend std::ostream& operator<<(std::ostream& os, const Course& course);
};

/*
La relacion que existe entre los objetos Course y Student es de agregacion ya que el curso tiene (has-a) una lista de estudiantes
pero los estudiantes pueden existir independientemente del curso. El curso actua como un todo y los estudintes son parte de ese todo, pero
si el curso se elimina no quiere decir que los estudiantes tambien se eliminen ya que estos pueden estar inscriptos en otros cursos.
*/