#ifndef CLONE_H
#define CLONE_H

#include "string"

class Clone {
    static int currId;
    std::string name;
    int id;
    
public:
    Clone() : name(""), id(currId++) {}
    Clone(std::string name) : name(name), id(currId++) {}
    
    int getId() const { return id; }
    std::string getName() const { return name; }  
    void setName(std::string _name) { this->name = _name; }
};
#endif /* ifndef CLONE_H */
