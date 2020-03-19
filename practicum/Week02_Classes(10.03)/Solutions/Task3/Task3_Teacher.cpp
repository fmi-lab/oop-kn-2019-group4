#include "Task3_Teacher.h"
#include "Task3_EnterName.h"
#include <iostream>

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
