#include <iostream>
#include <string.h>

#include "Student.h"

void Student::copy(const char *name, int number)
{
    Person::copy(name);

    this->number = number;
}

Student::Student()
{
    number = 0;
}

Student::Student(const char *name, int number)
{
    this->copy(name, number);
}

Student::Student(Student const &otherStudent)
{
    this->copy(otherStudent.getName(), otherStudent.getNumber());
}

Student &Student::operator=(Student const &otherStudent)
{
    if (this != &otherStudent)
    {
        this->copy(otherStudent.getName(), otherStudent.getNumber());
    }

    return *this;
}

Student::~Student()
{
}