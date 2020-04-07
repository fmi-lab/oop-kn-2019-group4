#ifndef COMPUTER_SHOP_H
#define COMPUTER_SHOP_H

#include "Computer.h"

class ComputerShop
{
    char *name;
    int size;
    Computer *computers;

    void copy(const char *name, int size, Computer *computers);

public:
    ComputerShop();
    ComputerShop(const char *name, int size, Computer *computers);
    ComputerShop(ComputerShop const &otherComputerShop);
    ComputerShop &operator=(ComputerShop const &otherComputerShop);
    ~ComputerShop();
    void addComputer(Computer computer);
    void buyComputer(const char *brand, double money);
    void print();
    Computer* getComputersInStock();

    char *getName() { return this->name; }
    int getSize() { return this->size; }
    Computer *getComputers() { return this->computers; }
};

#endif /* ifndef COMPUTER_SHOP_H */