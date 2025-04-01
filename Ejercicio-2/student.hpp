#pragma once
#include <string>
#include <vector>
#include <tuple>

class Student{
    private:
        std::string name;
        int id;
        std::vector<std::tuple<std::string,int>> courses;
    public:
        Student(std::string name, int id);
        void addCourse(std::string name, int grade);
        std::string getName();
        int getId();
        float getAverage();
};