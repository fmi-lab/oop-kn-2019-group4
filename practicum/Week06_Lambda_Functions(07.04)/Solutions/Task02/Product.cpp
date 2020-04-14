#include <iostream>
#include <string.h>

#include "Product.h"

void Product::copy(const char *name, double price)
{
    this->name = new char[strlen(name) + 1];

    strcpy(this->name, name);

    this->price = price;
}

Product::Product()
{
    name = nullptr;
    price = 0;
}

Product::Product(const char *name, double price)
{
    this->copy(name, price);
}

Product::Product(Product const &otherProduct)
{
    this->copy(otherProduct.getName(), otherProduct.getPrice());
}

Product &Product::operator=(Product const &otherProduct)
{
    if (this != &otherProduct)
    {
        delete[] this->name;

        this->copy(otherProduct.getName(), otherProduct.getPrice());
    }

    return *this;
}

Product::~Product()
{
    if (name != NULL)
    {
        delete[] name;
    }
}