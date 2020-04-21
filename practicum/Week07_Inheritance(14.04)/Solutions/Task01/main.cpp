#include <iostream>
#include <string.h>

#include "Employee.h"

int main()
{
    Employee employee1 = Employee("Pesho", "1234", "Sofia", 123, 1500);
    Employee employee2 = employee1;

    employee1.print();
    employee2.print();
}