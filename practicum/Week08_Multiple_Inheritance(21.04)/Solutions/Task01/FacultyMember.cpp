#include <iostream>
#include <string.h>

#include "FacultyMember.h"

void FacultyMember::copy(const char *name, int number, double salary)
{
    Student::copy(name, number);
    Employee::copy(name, salary);
}

FacultyMember::FacultyMember()
{
}

FacultyMember::FacultyMember(const char *name, int number, double salary)
{
    this->copy(name, number, salary);
}

FacultyMember::FacultyMember(FacultyMember const &other)
{
    this->copy(other.getName(), other.getNumber(), other.getSalary());
}

FacultyMember &FacultyMember::operator=(FacultyMember const &other)
{
    if (this != &other)
    {
        this->copy(other.getName(), other.getNumber(), other.getSalary());
    }

    return *this;
}

FacultyMember::~FacultyMember()
{
}