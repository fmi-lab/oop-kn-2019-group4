#ifndef COMPUTER_SHOP_H
#define COMPUTER_SHOP_H

#include "Computer.h"

class ComputerShop
{

public:
    char *name;
    int size;
    Computer *computers;

    void copy(char *name, int size, Computer *computers);
    ComputerShop(char *name, int size, Computer *computers);
    ComputerShop(ComputerShop const &otherComputerShop);
    ~ComputerShop();
    void addComputer(Computer computer);
    void buyComputer(char *brand);
    void print();
};

#endif /* ifndef COMPUTER_SHOP_H */