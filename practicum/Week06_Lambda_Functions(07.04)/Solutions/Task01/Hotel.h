#ifndef HOTEL_H
#define HOTEL_H

class Hotel
{
    char *name;
    int rooms;
    double price;

    void copy(const char *name, int rooms, double price);

public:
    Hotel();
    Hotel(const char *name, int rooms, double price);
    Hotel(Hotel const &otherHotel);
    Hotel &operator=(Hotel const &otherHotel);
    ~Hotel();

    char *getName() const { return this->name; }
    int getRooms() const { return this->rooms; }
    double getPrice() const { return this->price; }
};

#endif /* ifndef HOTEL_H */