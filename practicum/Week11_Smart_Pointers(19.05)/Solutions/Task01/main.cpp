#include <iostream>
#include <memory>

#include "Park.h"

void fun()
{
    Park *park = new Park("Fun");

    std::cout << (*park).getName() << std::endl;
}

int main()
{
    Park *park1 = new Park("Borisova");

    std::cout << park1->getName() << std::endl;

    delete (park1);

    // Unique
    std::unique_ptr<Park> park2(new Park("South"));

    std::cout << park2->getName() << std::endl;

    // Shared
    std::shared_ptr<Park> park3(new Park("Western"));
    std::shared_ptr<Park> park4;

    park4 = park3;

    std::cout << park3->getName() << std::endl;
    std::cout << park4->getName() << std::endl;
    // Weak
    std::weak_ptr<Park> park5;

    park5 = park3;

    // Can't be uses directly
    //std::cout << park5 -> getName()  << std::endl;

    std::shared_ptr<Park> park6 = park5.lock();

    std::cout << park6->getName() << std::endl;

    // Fun
    // for (;;)
    // {
    //     fun();
    // }
}