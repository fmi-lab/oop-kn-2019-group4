#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person
{
    int number;
    double salary;

    void copy(const char *name, const char *phone, const char *address, int number, double salary);

public:
    Employee();
    Employee(const char *name, const char *phone, const char *address, int number, double salary);
    Employee(Employee const &otherEmployee);
    Employee &operator=(Employee const &otherEmployee);
    ~Employee();

    void print();

    int getNumber() const { return this->number; }
    double getSalary() const { return this->salary; }
};

#endif /* ifndef EMPLOYEE_H */