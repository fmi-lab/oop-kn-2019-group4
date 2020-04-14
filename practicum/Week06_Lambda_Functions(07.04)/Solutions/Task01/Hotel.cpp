#include <iostream>
#include <string.h>

#include "Hotel.h"

void Hotel::copy(const char *name, int rooms, double price)
{
    this->name = new char[strlen(name) + 1];

    strcpy(this->name, name);

    this->rooms = rooms;
    this->price = price;
}

Hotel::Hotel()
{
    name = nullptr;
    rooms = 0;
    price = 0;
}

Hotel::Hotel(const char *name, int rooms, double price)
{
    this->copy(name, rooms, price);
}

Hotel::Hotel(Hotel const &otherHotel)
{
    this->copy(otherHotel.getName(), otherHotel.getRooms(), otherHotel.getPrice());
}

Hotel &Hotel::operator=(Hotel const &otherHotel)
{
    if (this != &otherHotel)
    {
        delete[] this->name;

        this->copy(otherHotel.getName(), otherHotel.getRooms(), otherHotel.getPrice());
    }

    return *this;
}

Hotel::~Hotel()
{
    if (name != NULL)
    {
        delete[] name;
    }
}