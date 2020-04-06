#include <iostream>
#include <string.h>

#include "ComputerShop.h"

void ComputerShop::copy(char *name, int size, Computer *computers)
{
    this->name = new char[strlen(name) + 1];

    strcpy(this->name, name);

    this->size = size;

    this->computers = new Computer[size];

    for (int i = 0; i < size; i++)
    {
        this->computers[i] = Computer(computers[i]);
    }
}

ComputerShop::ComputerShop(char *name, int size, Computer *computers)
{
    this->copy(name, size, computers);
}

ComputerShop::ComputerShop(ComputerShop const &otherComputershop)
{
    this->copy(otherComputershop.name, size, otherComputershop.computers);
}

ComputerShop::~ComputerShop()
{
    if (name != NULL)
    {
        delete[] name;
    }

    if (computers != NULL)
    {
        delete[] computers;
    }
}

void ComputerShop::addComputer(Computer computer)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(computers[i].brand, computer.brand) == 0)
        {
            computers[i].quantity++;

            return;
        }
    }

    Computer *newComputers = new Computer[size + 1];
    for (int i = 0; i < size; i++) {
        newComputers[i] = computers[i];
    }
    newComputers[size++] = computer;

    computers = newComputers;
}

void ComputerShop::buyComputer(char *brand)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(computers[i].brand, brand) == 0)
        {
            if (computers[i].quantity > 0)
            {
                computers[i].quantity--;
                std::cout << "Success" << std::endl;
            }
            else
            {
                std::cout << "Insufficient quantity" << std::endl;
            }

            return;
        }
    }

    std::cout << "Brand not found" << std::endl;
}

void ComputerShop::print()
{
    std::cout << name << std::endl;

    for (int i = 0; i < size; i++)
    {
        computers[i].print();
    }
}