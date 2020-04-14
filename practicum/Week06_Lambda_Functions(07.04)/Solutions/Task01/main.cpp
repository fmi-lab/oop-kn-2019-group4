#include <iostream>
#include <functional>
#include <string.h>
#include "Hotel.h"

template <typename ResT, typename ElemT>
ResT reduce(ElemT arr[],
            int arrsize,
            std::function<ResT(ResT, ElemT)> f,
            ResT null_val)
{
    ResT result = null_val;

    for (int i = 0; i < arrsize; i++)
    {
        result = f(result, arr[i]);
    }

    return result;
}

int calc(double accumulated, Hotel hotel)
{
    return accumulated + (hotel.getRooms() * hotel.getPrice());
}

int main()
{
    Hotel hotel1 = Hotel("Hotel 1", 10, 25.5);
    Hotel hotel2 = Hotel("Hotel 2", 10, 18.5);
    Hotel hotel3 = Hotel("Hotel 2", 10, 14.5);

    Hotel arr[] = {hotel1, hotel2, hotel3};

    std::cout << reduce<double, Hotel>(arr, 3, calc, 0);
}