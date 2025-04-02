#include "course.hpp"
#include <algorithm>

Course::Course(std::string name) : name(name) {}

std::string Course::getName(){
    return this->name;
}

void Course::setName(std::string name){
    this->name = name;
}

int Course::searchStudent(int id){
    int index = 0;
    for(const std::unique_ptr<Student>& student : this->students){
        if(student->getId() == id){
            return index;
        }
        index++;
    }
    return -1;
}

bool Course::isFull(){
    return this->currentCapacity == this->maxCapacity;
}

bool Course::addStudent(std::unique_ptr<Student> student){
    //Si el estudiante no esta en el curso, lo agrego
    if(this->searchStudent(student->getId()) == -1 && !isFull()){
        this->students.push_back(std::move(student));
        return true;
    }
    return false;

}

bool Course::addStudent(std::string name, int id){
    if(this->searchStudent(id) == -1 && !isFull()){
        Student student(name,id);
        this->students.push_back(std::make_unique<Student>(student));
        this->currentCapacity++;
        return true;
    }
    return false;
}

bool Course::removeStudent(int id){
    int studentIndex = searchStudent(id);
    if(studentIndex == -1){
        return false;
    }else{
        this->students.erase(this->students.begin() + studentIndex);
        this->currentCapacity--;
        return true;
    }
}

std::ostream& operator<<(std::ostream& os, const Course& course){
    int count = 1;
    os<<"Lista de estudiantes del curso "<<course.name<<":"<<std::endl;
    for(const std::unique_ptr<Student>& student : course.students){
        os << count<<") "<<student->getName()<<" (Legajo: "<<student->getId()<<")"<<std::endl;
        count++;
    }
    return os;
}

//Como el objeto Curso tiene memoria alocada dinamicamente (el vector de punteros a objetos estudiantes) no se puede hacer una shallow copy
//ya que solo copiaría los punteros, lo que resultaría en múltiples cursos compartiendo los mismos objetos Estudiante.
//Esto podría causar problemas de gestión de memoria y potenciales dangling pointers si un curso elimina un estudiante mientras otro aún lo usa.
//Por eso creo una sobrecarga del constructor de cursos que permite realizar una deep copy creando nuevos punteros a estudiantes.

Course::Course(const Course& other) : name(other.name), currentCapacity(other.currentCapacity){
    for(const std::unique_ptr<Student>& student : other.students){
        this->students.push_back(std::make_unique<Student>(Student(*student)));
    }
}