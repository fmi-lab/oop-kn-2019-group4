#include <iostream>
#include <string.h>

#include "Person.h"

void Person::copy(const char *name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Person::Person()
{
    name = nullptr;
}

Person::Person(const char *name)
{
    this->copy(name);
}

Person::Person(Person const &otherPerson)
{
    this->copy(otherPerson.getName());
}

Person &Person::operator=(Person const &otherPerson)
{
    if (this != &otherPerson)
    {
        delete[] this->name;

        this->copy(otherPerson.getName());
    }

    return *this;
}

Person::~Person()
{
    if (name != NULL)
    {
        delete[] name;
    }
}