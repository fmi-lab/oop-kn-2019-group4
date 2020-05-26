#ifndef PARK_H
#define PARK_H

#include <string>

class Park
{
    std::string name;

protected:
    void copy(std::string name);

public:
    Park();
    Park(std::string name);
    Park(Park const &other);
    Park &operator=(Park const &other);
    ~Park();

    std::string getName() const { return this->name; }
};

#endif /* ifndef PARK_H */