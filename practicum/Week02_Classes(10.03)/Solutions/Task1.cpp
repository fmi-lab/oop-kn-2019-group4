#include <iostream>
#include <math.h>

class Triangle
{
public:
    int side1;
    int side2;
    int side3;

    int perimeter()
    {
        return side1 + side2 + side3;
    }

    int area()
    {
        double p = perimeter() / 2;

        return sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }
};

int main()
{
    Triangle triangle;

    triangle.side1 = 3;
    triangle.side2 = 4;
    triangle.side3 = 5;

    std::cout << "Perimeter is: " << triangle.perimeter() << std::endl;
    std::cout << "Area is: " << triangle.area();
}