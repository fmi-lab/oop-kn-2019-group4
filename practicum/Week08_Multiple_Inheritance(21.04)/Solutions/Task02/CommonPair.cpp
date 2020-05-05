#include <iostream>
#include <string.h>

#include "CommonPair.h"

void CommonPair::copy(int key, double value)
{
    Pair<int, double>::copy(key, value);
}

CommonPair::CommonPair()
{
}

CommonPair::CommonPair(int key, double value)
{
    this->copy(key, value);
}

CommonPair::CommonPair(CommonPair const &other)
{
    this->copy(other.getKey(), other.getValue());
}

CommonPair &CommonPair::operator=(CommonPair const &other)
{
    if (this != &other)
    {
        this->copy(other.getKey(), other.getValue());
    }

    return *this;
}

CommonPair::~CommonPair()
{
}