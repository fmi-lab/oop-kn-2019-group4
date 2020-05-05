#include <iostream>
#include <string.h>

#include "Pair.h"

template <typename T, typename U>
void Pair<T, U>::copy(T key, U value)
{
    this->key = key;
    this->value = value;
}

template <typename T, typename U>
Pair<T, U>::Pair()
{
    key = 0;
    value = 0;
}

template <typename T, typename U>
Pair<T, U>::Pair(T key, U value)
{
    this->copy(key, value);
}

template <typename T, typename U>
Pair<T, U>::Pair(Pair const &other)
{
    this->copy(other.getKey(), other.getValue());
}

template <typename T, typename U>
Pair<T, U> &Pair<T, U>::operator=(Pair const &other)
{
    if (this != &other)
    {
        this->copy(other.getKey(), other.getValue());
    }

    return *this;
}

template <typename T, typename U>
Pair<T, U>::~Pair()
{
}

// No need to call this TemporaryFunction() function,
// it's just to avoid link error.
void TemporaryFunction ()
{
    Pair<int, int> TempObj1(0, 0);
    Pair<int, int> TempObj2;
}

// It's just to avoid link error in CommonPair.cpp.
template class Pair<int, double>;