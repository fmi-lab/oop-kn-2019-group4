#include <exception>
#include <iostream>
#include "Clone.h"
#include "Army.h"
#include "MyException.h"

int Clone::currId = 0;

int main() {
    Clone test;
    Clone rex("Rex");
    Clone cody("Cody");
    test.setName("CC-1305");

    Army army;
    army.addClone(rex);
    army.addClone(cody);
    army.addClone(test);

    try {
        army.findCloneById(3);
    } catch (missingTrooperException& e) {
        std::cout << "Caught my own exception: ";
        std::cout << e.what() << std::endl; 
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "Trooper name is: " << army.findCloneById(2).getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
