#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <string.h>

#include "ComputerShop.h"
#include "doctest.h"

TEST_CASE("Buy computer")
{
    // given
    const char *brand1 = "Brand1";
    const char *brand2 = "Brand2";
    const char *proccessor = "i7";
    const char *video = "1070";
    const char *hardDrive = "512";
    const int size = 2;
    Computer *computers = new Computer[size];

    computers[0] = Computer(brand1, proccessor, video, hardDrive, 1999.99, 2);
    computers[1] = Computer(brand2, proccessor, video, hardDrive, 1599.99, 0);

    ComputerShop computerShop = ComputerShop("Shop1", size, computers);

    // when
    computerShop.buyComputer(brand1, 2500);

    // then
    CHECK(computers[0].getQuantity() == 2);

    // when
    computerShop.buyComputer(brand1, 1000);

    // then
    CHECK(computers[0].getQuantity() == 2);
}

TEST_CASE("Add computer")
{
    // given
    const char *brand1 = "Brand1";
    const char *brand2 = "Brand2";
    const char *brand3 = "Brand3";
    const char *proccessor = "i7";
    const char *video = "1070";
    const char *hardDrive = "512";
    const int size = 2;
    Computer *computers = new Computer[size];

    computers[0] = Computer(brand1, proccessor, video, hardDrive, 1999.99, 2);
    computers[1] = Computer(brand2, proccessor, video, hardDrive, 1599.99, 0);

    ComputerShop computerShop = ComputerShop("Shop1", size, computers);

    // when
    computerShop.addComputer(Computer(brand3, proccessor, video, hardDrive, 1999.99, 2));

    // then
    CHECK(computerShop.getSize() == 3);
}

TEST_CASE("Get computers in stock")
{
    // given
    const char *brand1 = "Brand1";
    const char *brand2 = "Brand2";
    const char *brand3 = "Brand3";
    const char *proccessor = "i7";
    const char *video = "1070";
    const char *hardDrive = "512";
    const int size = 3;
    Computer *computers = new Computer[size];

    computers[0] = Computer(brand1, proccessor, video, hardDrive, 1999.99, 2);
    computers[1] = Computer(brand2, proccessor, video, hardDrive, 1599.99, 0);
    computers[2] = Computer(brand3, proccessor, video, hardDrive, 1599.99, 1);

    ComputerShop computerShop = ComputerShop("Shop1", size, computers);

    // when
    Computer *computersInStock = computerShop.getComputersInStock();

    // then
    CHECK(computersInStock[0].getQuantity() == 2);
    CHECK(computersInStock[1].getQuantity() == 1);
}

int main()
{
    // char *name = new char[20];
    // char *brandToBuy = new char[20];
    // int size;
    // double money;

    // std::cout << "Enter shop name: ";
    // std::cin.getline(name, 20);

    // std::cout << "Enter number of computers: ";
    // std::cin >> size;
    // std::cin.get();

    // Computer *computers = new Computer[size];

    // for (int i = 0; i < size; i++)
    // {
    //     computers[i].create();
    // }

    // ComputerShop computerShop = ComputerShop(name, size, computers);

    // // Add computer
    // Computer computerToAdd = Computer();
    // computerToAdd.create();

    // computerShop.addComputer(computerToAdd);

    // // Buy computer
    // std::cout << "Enter brand to buy: ";
    // std::cin.getline(brandToBuy, 20);

    // std::cout << "Enter money you have: ";
    // std::cin>> money;

    // computerShop.buyComputer(brandToBuy, money);

    // computerShop.print();

    doctest::Context().run();
}