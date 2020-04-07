#include <iostream>
#include <string.h>

#include "Computer.h"

void Computer::copy(const char *brand, const char *processor, const char *video, const char *hardDrive, double price, int quantity)
{
    this->brand = new char[strlen(brand) + 1];
    this->processor = new char[strlen(processor) + 1]; 
    this->video = new char[strlen(video) + 1];
    this->hardDrive = new char[strlen(hardDrive) + 1];

    strcpy(this->brand, brand);
    strcpy(this->processor, processor);
    strcpy(this->video, video);
    strcpy(this->hardDrive, hardDrive);

    this->price = price;
    this->quantity = quantity;
}

Computer::Computer()
{
    brand = new char[20];
    processor = new char[20];
    video = new char[20];
    hardDrive = new char[20];
    price = 0;
    quantity = 0;
}

Computer::Computer(const char *brand, const char *processor, const char *video, const char *hardDrive, double price, int quantity)
{
    this->copy(brand, processor, video, hardDrive, price, quantity);
}

Computer::Computer(Computer const &otherComputer)
{
    this->copy(otherComputer.brand, otherComputer.processor, otherComputer.video, otherComputer.hardDrive, otherComputer.price, otherComputer.quantity);
}

Computer &Computer::operator=(Computer const &otherComputer)
{
    //this is here so we don't write computer = computer. We don't want to copy ourselves
    if (this != &otherComputer)
    {
        delete[] this->brand;
        delete[] this->processor;
        delete[] this->video;
        delete[] this->hardDrive;

        this->copy(otherComputer.brand, otherComputer.processor, otherComputer.video, otherComputer.hardDrive, otherComputer.price, otherComputer.quantity);
    }

    return *this;
}

Computer::~Computer()
{
    if (brand != NULL)
    {
        delete[] brand;
    }

    if (processor != NULL)
    {
        delete[] processor;
    }

    if (video != NULL)
    {
        delete[] video;
    }

    if (hardDrive != NULL)
    {
        delete[] hardDrive;
    }
}

void Computer::create()
{
    std::cout << "Enter brand: ";
    std::cin.getline(brand, 20);

    std::cout << "Enter processor: ";
    std::cin.getline(processor, 20);

    std::cout << "Enter video: ";
    std::cin.getline(video, 20);

    std::cout << "Enter hardDrive: ";
    std::cin.getline(hardDrive, 20);

    std::cout << "Enter price: ";
    std::cin >> price;

    std::cout << "Enter quantity: ";
    std::cin >> quantity;
    std::cin.get();
}

void Computer::print()
{
    std::cout << brand << " " << processor << " " << video << " " << hardDrive << " " << price << " " << quantity << std::endl;
}

void Computer::modifyQuantity(int quantity)
{
    this->quantity += quantity;
}
