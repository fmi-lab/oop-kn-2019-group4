#include "Teacher.h"
#include "EnterName.h"
#include <iostream>

void Teacher::copy(char * _firstName, char * _lastName, int _grade) {
    this->firstName = new char [strlen(_firstName) + 1]; //+1 for terminating zero
    this->lastName = new char [strlen(_lastName) + 1];
    
    strcpy(this->firstName, _firstName);
    strcpy(this->lastName, _lastName);
    
    this->grade = _grade;
}

Teacher::Teacher(char * _firstName, char * _lastName, int _grade) {
    this->copy(_firstName, _lastName, _grade);
}

Teacher::Teacher(Teacher const& otherTeacher) {
    this->copy(otherTeacher.firstName, otherTeacher.lastName, otherTeacher.grade);
}


void Teacher::print() {
    std::cout << "First name: " << firstName << " Last name: " << lastName
                  << " Grade: " << grade << std::endl;
}

void Teacher::create() {
    enterName<Teacher>(*this);    
    std::cout << "Enter teacher's grade: " << std::endl; 
    std::cin >> this->grade;
    std::cin.get();
}
