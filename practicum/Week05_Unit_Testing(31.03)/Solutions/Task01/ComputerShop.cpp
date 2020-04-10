#include <iostream>
#include <string.h>

#include "ComputerShop.h"

void ComputerShop::copy(const char *name, int size, Computer *computers)
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

ComputerShop::ComputerShop()
{
    name = nullptr;
    size = 0;
    computers = nullptr;
}

ComputerShop::ComputerShop(const char *name, int size, Computer *computers)
{
    this->copy(name, size, computers);
}

ComputerShop::ComputerShop(ComputerShop const &otherComputershop)
{
    this->copy(otherComputershop.name, size, otherComputershop.computers);
}

ComputerShop &ComputerShop::operator=(ComputerShop const &otherComputerShop)
{
    if (this != &otherComputerShop)
    {
        delete[] this->name;
        delete[] this->computers;

        this->copy(otherComputerShop.name, otherComputerShop.size, otherComputerShop.computers);
    }

    return *this;
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
        if (strcmp(computers[i].getBrand(), computer.getBrand()) == 0)
        {
            computers[i].modifyQuantity(1);

            return;
        }
    }

    Computer *newComputers = new Computer[size + 1];
    for (int i = 0; i < size; i++)
    {
        newComputers[i] = computers[i];
    }
    newComputers[size++] = computer;

    computers = newComputers;
}

void ComputerShop::buyComputer(const char *brand, double money)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(computers[i].getBrand(), brand) == 0)
        {
            if (computers[i].getQuantity() > 0 && money >= computers[i].getPrice())
            {
                computers[i].modifyQuantity(-1);
                std::cout << "Success" << std::endl;
            }
            else
            {
                std::cout << "Insufficient quantity or money" << std::endl;
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

Computer *ComputerShop::getComputersInStock()
{
    int inStockSize = 0;
    for (int i = 0; i < size; i++)
    {
        if (computers[i].getQuantity() > 0)
        {
            inStockSize++;
        }
    }

    Computer *computersInStock = new Computer[inStockSize];

    for (int i = 0, j = 0; i < size; i++)
    {
        if (computers[i].getQuantity() > 0)
        {
            computersInStock[j++] = computers[i];
        }
    }

    return computersInStock;
}