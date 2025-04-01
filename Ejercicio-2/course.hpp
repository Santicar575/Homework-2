#pragma once
#include <string>
#include <vector>
#include "student.hpp"

class Course{
    private:
        std::string name;
        std::vector<Student> students;
};