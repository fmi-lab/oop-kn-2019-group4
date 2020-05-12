#include "Teacher.h"
#include "Functions.h"
#include "User.h"

#include <iostream>
#include <ostream>
#include <string.h>

Teacher::Teacher(char const * _firstName, char const * _lastName, char const * pass, int _grade) 
    : User(_firstName, _lastName, pass, "teacher") {
        this->grade = _grade;   
}

void Teacher::print(std::ostream& out) const {
    User::print(out);
    out << " Grade: " << grade;
}

void Teacher::create(const char * _type) {
    User::create("teacher");

    std::cout << "Enter teacher's grade: " << std::endl;
    std::cin >> this->grade;
    std::cin.get();
}


void Teacher::serialize(std::ostream& out) const {
    User::serialize(out);
    out << this->grade << " ";
}

void Teacher::deserialize(std::istream& inp) {
    User::deserialize(inp);
    inp >> this->grade;
}
