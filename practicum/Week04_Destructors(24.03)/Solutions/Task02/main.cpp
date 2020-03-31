#include <iostream>
#include <string.h>

#include "ComputerShop.h"

int main()
{
    char *name = new char[20];
    char *brandToBuy = new char[20];
    int size;

    std::cout << "Enter shop name: ";
    std::cin.getline(name, 20);

    std::cout << "Enter number of computers: ";
    std::cin >> size;
    std::cin.get();

    Computer *computers = new Computer[size];

    for (int i = 0; i < size; i++)
    {
        computers[i].create();
    }

    ComputerShop computerShop = ComputerShop(name, size, computers);

    // Add computer
    Computer computerToAdd = Computer();
    computerToAdd.create();

    computerShop.addComputer(computerToAdd);

    // Buy computer
    std::cout << "Enter brand to buy: ";
    std::cin.getline(brandToBuy, 20);

    computerShop.buyComputer(brandToBuy);

    computerShop.print();
}