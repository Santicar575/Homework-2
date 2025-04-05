#include "student.hpp"

bool Student::isAlpha(std::string str){
    for(char c : str){
        if(!std::isalpha(c) && !std::isspace(c)) return false;
    }
    return true;
}

Student::Student(std::string name, int id){
    (this->isAlpha(name)) ? this->name = name : throw "Invalid name";
    this->id = id;
}

Student::Student(const Student& other) : name(other.name),id(other.id){
    for(std::pair<std::string,int> course : other.courses){
        this->courses.push_back(course);
    }
}

std::string Student::getName() const {
    return name;
}

int Student::getId() const {
    return id;
}

float Student::getAverage() const{
    int count = 0, average = 0, grade;
    for(std::pair<std::string, int> course : courses){
        grade = course.second;
        if(grade >= 0){ //Si la nota es un -1 significa que esta cursando el curso y no se tiene en cuenta para el promedio general
            average += grade;
            count++;
        }        
    }
    return (count == 0) ? 0 : static_cast<float>(average/count);
}

void Student::addCourse(std::string name, int grade){
    courses.push_back(std::make_pair(name, grade));
}

bool Student::operator<(const Student& other) const{
    return this->getName() < other.getName();
}