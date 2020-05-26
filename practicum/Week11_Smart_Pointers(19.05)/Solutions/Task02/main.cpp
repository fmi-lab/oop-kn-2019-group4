#include <iostream>
#include <memory>

#include "Park.h"
#include "SmartPointer.cpp"

void fun()
{
    SmartPointer<Park> park(new Park("Fun"));

    std::cout << park->getName() << std::endl;
}

int main()
{
    SmartPointer<Park> park(new Park("Hunting"));

    std::cout << park->getName() << std::endl;

    // Fun
    for (;;)
    {
        fun();
    }
}