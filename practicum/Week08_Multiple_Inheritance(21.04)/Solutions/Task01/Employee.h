#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : virtual public Person
{
    double salary;

protected:
    void copy(const char *name, double salary);

public:
    Employee();
    Employee(const char *name, double salary);
    Employee(Employee const &otherEmployee);
    Employee &operator=(Employee const &otherEmployee);
    ~Employee();

    double getSalary() const { return this->salary; }
};

#endif /* ifndef EMPLOYEE_H */