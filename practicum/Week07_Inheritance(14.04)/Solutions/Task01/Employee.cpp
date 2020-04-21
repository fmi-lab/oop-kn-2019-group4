#include <iostream>
#include <string.h>

#include "Employee.h"

void Employee::copy(const char *name, const char *phone, const char *address, int number, double salary)
{
    Person::copy(name, phone, address);

    this->number = number;
    this->salary = salary;
}

Employee::Employee()
{
    number = 0;
    salary = 0;
}

Employee::Employee(const char *name, const char *phone, const char *address, int number, double salary) //: Person(name, phone, address)
{
    this->copy(name, phone, address, number, salary);
}

Employee::Employee(Employee const &otherEmployee)
{
    this->copy(otherEmployee.getName(), otherEmployee.getPhone(), otherEmployee.getAddress(), otherEmployee.getNumber(), otherEmployee.getSalary());
}

Employee &Employee::operator=(Employee const &otherEmployee)
{
    if (this != &otherEmployee)
    {
        delete[] this->name;

        this->copy(otherEmployee.getName(), otherEmployee.getPhone(), otherEmployee.getAddress(), otherEmployee.getNumber(), otherEmployee.getSalary());
    }

    return *this;
}

Employee::~Employee()
{
}

void Employee::print()
{
    std::cout << name << " " << getPhone() << " " << getAddress() << " " << number << " " << salary << std::endl;
}