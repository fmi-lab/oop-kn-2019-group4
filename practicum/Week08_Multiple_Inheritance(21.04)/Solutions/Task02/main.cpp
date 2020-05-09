#include <iostream>
#include <string.h>

#include "CommonPair.h"

int main()
{
    Pair<int, int> pair1(10, 15);

    std::cout << pair1.getKey() << " " << pair1.getValue() << std::endl;

    CommonPair pair2(20, 25.5);

    std::cout << pair2.getKey() << " " << pair2.getValue() << std::endl;
}