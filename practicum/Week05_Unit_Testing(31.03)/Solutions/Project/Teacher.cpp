#include "Teacher.h"
#include "Functions.h"
#include <iostream>
#include <string.h>

void Teacher::copy(char const * _firstName, char const * _lastName, int _grade) {
    this->firstName = new char [strlen(_firstName) + 1]; //+1 for terminating zero
    this->lastName = new char [strlen(_lastName) + 1];
    
    strcpy(this->firstName, _firstName);
    strcpy(this->lastName, _lastName);
    
    this->grade = _grade;
}
void Teacher::destroy() {
    if(this->firstName != nullptr) {
        delete[] firstName;
    }

    if(this->lastName != nullptr) {
        delete[] lastName;
    }
}

Teacher& Teacher::operator=(Teacher const& otherTeacher) {
    if(this != &otherTeacher) { //this is here so we don't write teacher = teacher. We don't want to copy ourselves
          this->destroy();
          this->copy(otherTeacher.firstName, otherTeacher.lastName, otherTeacher.grade);
    }

    return *this;
}

Teacher::Teacher(char const * _firstName, char const * _lastName, int _grade) {
    this->copy(_firstName, _lastName, _grade);
}

Teacher::Teacher(Teacher const& otherTeacher) {
    this->copy(otherTeacher.firstName, otherTeacher.lastName, otherTeacher.grade);
}

Teacher::~Teacher() {
    this->destroy();
}

void Teacher::print() const {
    std::cout << "First name: " << firstName << " Last name: " << lastName
                  << " Grade: " << grade << std::endl;
}

void Teacher::create() {
    enterName<Teacher>(*this);    
    std::cout << "Enter teacher's grade: " << std::endl; 
    std::cin >> this->grade;
    std::cin.get();
}


void Teacher::serialize(std::ostream& out) const {
    out << strlen(this->firstName) << " " << strlen(this->lastName) << " " << this->firstName << " " << this-> lastName
        << " " << this->grade << " ";
}

void Teacher::deserialize(std::istream& in) {
    int size;
    
    in >> size;
    this->firstName = new char [ size + 1 ]; //size + 1 for terminating zero
    
    in >> size;
    this->lastName = new char [ size + 1 ];
    
    in >> this->firstName
       >> this->lastName
       >> this->grade;
}
