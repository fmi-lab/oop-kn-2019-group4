#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
    char *name;
    double price;

    void copy(const char *name, double price);

public:
    Product();
    Product(const char *name, double price);
    Product(Product const &otherProduct);
    Product &operator=(Product const &otherProduct);
    ~Product();

    char *getName() const { return this->name; }
    double getPrice() const { return this->price; }
    void setPrice(double price) { this->price = price; }
};

#endif /* ifndef PRODUCT_H */