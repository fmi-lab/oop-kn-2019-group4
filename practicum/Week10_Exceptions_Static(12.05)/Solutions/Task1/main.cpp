#include <iostream>
#include "Clone.h"

int Clone::currId = 0;

int main() {
    Clone test;
    Clone rex("Rex");
    Clone cody;
    cody.setName("Cody"); 
    test.setName("CT-1305");

    if(cody.getId() != 2 || rex.getId() != 1 || test.getId() != 0) {
        std::cout << "Error";
    } else {
        std::cout << test.getName() << " " << test.getId() << std::endl; 
        std::cout << rex.getName() << " " << rex.getId() << std::endl; 
        std::cout << cody.getName() << " " << cody.getId() << std::endl; 
    }

    return 0;
}
