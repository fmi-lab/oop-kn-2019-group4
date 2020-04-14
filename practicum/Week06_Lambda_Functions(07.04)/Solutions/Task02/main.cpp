#include <iostream>
#include <functional>
#include <string.h>
#include "Product.h"

template <class T>
void map(T arr[],
         int size,
         std::function<void(T &)> op)
{
    for (int i = 0; i < size; ++i)
    {
        op(arr[i]);
    }
}

void reducePrice(Product &product)
{
    if (product.getPrice() - 50 < 5)
    {
        product.setPrice(5);
    }
    else
    {
        product.setPrice(product.getPrice() - 50);
    }
}

void increasePrice(Product &product)
{
    product.setPrice(product.getPrice() + product.getPrice() / 10);
}

void print(Product arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Name: " << arr[i].getName() << "Price: " << arr[i].getPrice() << std::endl;
    }
}

int main()
{
    Product product1 = Product("Product 1", 125.5);
    Product product2 = Product("Product 2", 58.5);
    Product product3 = Product("Product 3", 34.5);

    Product arr[] = {product1, product2, product3};

    map<Product>(arr, 3, reducePrice);

    print(arr, 3);

    map<Product>(arr, 3, increasePrice);

    print(arr, 3);
}