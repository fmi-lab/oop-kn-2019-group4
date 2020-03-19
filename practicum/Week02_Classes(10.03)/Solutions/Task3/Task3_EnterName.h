#pragma once
#include <iostream>
#include <string.h>

template<typename T>
void enterName(T& toBeNamed) {
    char firstName[100];
    char lastName[100];
    std::cout << "Enter person's firstName, lastName:" << std::endl;  
    std::cin.getline(firstName, 100);
    std::cin.getline(lastName, 100);
  
    toBeNamed.firstName = new char[strlen(firstName) + 1]; 
    toBeNamed.lastName = new char[strlen(lastName) + 1]; 
  
    strcpy(toBeNamed.firstName, firstName);
    strcpy(toBeNamed.lastName, lastName);
}
