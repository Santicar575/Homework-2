#pragma once
#include <string>
#include <vector>
#include <utility>

class Student{
    private:
        std::string name;
        int id;
        std::vector<std::pair<std::string,int>> courses;
        bool isAlpha(std::string str);
    public:
        Student(std::string name, int id);
        Student(const Student& other);
        void addCourse(std::string name, int grade);
        std::string getName() const;
        int getId() const;
        float getAverage() const;
        bool operator<(const Student& other) const;
};