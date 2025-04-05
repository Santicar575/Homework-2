#include "course.hpp"
#include <algorithm>

Course::Course(std::string name) : name(name) {}

std::string Course::getName() const{
    return this->name;
}

void Course::setName(std::string name){
    this->name = name;
}

int Course::searchStudent(int id) const{
    int index = 0;
    for(const std::shared_ptr<Student>& student : this->students){
        if(student->getId() == id){
            return index;
        }
        index++;
    }
    return -1;
}

bool Course::isFull() const{
    return this->currentCapacity == this->maxCapacity;
}

bool Course::addStudent(const std::shared_ptr<Student>& student){
    //Si el estudiante no esta en el curso, lo agrego
    if(this->searchStudent(student->getId()) == -1 && !isFull()){
        student->addCourse(this->getName(),-1);
        this->students.push_back(student);
        this->currentCapacity++;
        return true;
    }
    return false;
}

bool Course::addStudent(std::string name, int id){
    if(this->searchStudent(id) == -1 && !isFull()){
        Student student(name,id);
        student.addCourse(this->getName(),-1);
        this->students.push_back(std::make_shared<Student>(student));
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
    std::vector<std::shared_ptr<Student>> sortedStudents = course.students;
    std::sort(sortedStudents.begin(), sortedStudents.end(),[](const std::shared_ptr<Student>& a, const std::shared_ptr<Student>& b){
        return *a < *b;
    });
    os<<"Lista de estudiantes del curso "<<course.name<<":"<<std::endl;
    for(const std::shared_ptr<Student>& student : sortedStudents){
        os << count<<") "<<student->getName()<<" (Legajo: "<<student->getId()<<")"<<std::endl;
        count++;
    }
    return os;
}

/*
Creo una especie de shallow copy que mantiene los mismos estudiantes en el curso copiado (mismos punteros) pero con vectores diferentes (pudiendo agregar y eliminar estudiantes sin afectar a los cursos).
Esto es util para no duplicar estudiantes en memoria y que los cursos tengan los mismos estudiantes.
*/

Course::Course(const Course& other) : name(other.name), currentCapacity(other.currentCapacity){
    for(const std::shared_ptr<Student>& student : other.students){
        this->addStudent(student);
    }
}