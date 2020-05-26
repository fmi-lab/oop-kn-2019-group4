#include <iostream>
#include <string.h>

#include "Park.h"

void Park::copy(std::string name)
{
    this->name = name;
}

Park::Park()
{
}

Park::Park(std::string name)
{
    this->copy(name);
}

Park::Park(Park const &other)
{
    this->copy(other.name);
}

Park &Park::operator=(Park const &other)
{
    if (this != &other)
    {
        this->copy(other.name);
    }

    return *this;
}

Park::~Park()
{
}
