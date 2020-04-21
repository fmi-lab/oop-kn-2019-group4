#include <iostream>
#include <string.h>

#include "Person.h"

void Person::copy(const char *name, const char *phone, const char *address)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->phone = new char[strlen(phone) + 1];
    strcpy(this->phone, phone);

    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
}

Person::Person()
{
    name = nullptr;
    phone = nullptr;
    address = nullptr;
}

Person::Person(const char *name, const char *phone, const char *address)
{
    this->copy(name, phone, address);
}

Person::Person(Person const &otherPerson)
{
    this->copy(otherPerson.getName(), otherPerson.getPhone(), otherPerson.getAddress());
}

Person &Person::operator=(Person const &otherPerson)
{
    if (this != &otherPerson)
    {
        delete[] this->name;

        this->copy(otherPerson.getName(), otherPerson.getPhone(), otherPerson.getAddress());
    }

    return *this;
}

Person::~Person()
{
    if (name != NULL)
    {
        delete[] name;
    }

    if (phone != NULL)
    {
        delete[] phone;
    }

    if (address != NULL)
    {
        delete[] address;
    }
}