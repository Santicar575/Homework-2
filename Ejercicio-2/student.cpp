#include "student.hpp"

Student::Student(std::string name, int id){
    this->name = name;
    this->id = id;
}

std::string Student::getName(){
    return name;
}

int Student::getId(){
    return id;
}

float Student::getAverage(){
    int average = 0, count = 0;
    for(std::tuple course : courses){
        average += std::get<1>(course);
        count++;
    }
    return average/count;
}

void Student::addCourse(std::string name, int grade){
    courses.push_back(std::make_tuple(name, grade));
}