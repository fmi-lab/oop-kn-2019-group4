#ifndef COMPUTER_H
#define COMPUTER_H

class Computer
{
    char *brand;
    char *processor;
    char *video;
    char *hardDrive;
    double price;
    int quantity;

    void copy(const char *brand, const char *processor, const char *video, const char *hardDrive, double price, int quantity);

public:
    Computer();
    Computer(const char *brand, const char *processor, const char *video, const char *hardDrive, double price, int quantity);
    Computer(Computer const &otherComputer);
    Computer &operator=(Computer const &otherComputer);
    ~Computer();
    void create();
    void print();
    void modifyQuantity(int quantity);

    char *getBrand() const { return this->brand; }
    char *getProcessor() const { return this->processor; }
    char *getVideo() const { return this->video; }
    char *getHardDrive() const { return this->hardDrive; }
    double getPrice() const { return this->price; }
    int getQuantity() const { return this->quantity; }
};

#endif /* ifndef COMPUTER_H */