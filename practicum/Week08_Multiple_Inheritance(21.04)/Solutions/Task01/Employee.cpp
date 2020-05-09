#include <iostream>
#include <string.h>

#include "Employee.h"

void Employee::copy(const char *name, double salary)
{
    Person::copy(name);

    this->salary = salary;
}

Employee::Employee()
{
    salary = 0;
}

Employee::Employee(const char *name, double salary)
{
    this->copy(name, salary);
}

Employee::Employee(Employee const &otherEmployee)
{
    this->copy(otherEmployee.getName(), otherEmployee.getSalary());
}

Employee &Employee::operator=(Employee const &otherEmployee)
{
    if (this != &otherEmployee)
    {
        this->copy(otherEmployee.getName(), otherEmployee.getSalary());
    }

    return *this;
}

Employee::~Employee()
{
}