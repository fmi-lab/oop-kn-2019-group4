#ifndef TEACHER_H
#define TEACHER_H 

#include <fstream>
#include <ostream>
#include "Functions.h"
#include "User.h"

class Teacher : public User  {
    int grade;

    void copy(char const * _firstName, char const * _lastName, char const * pass, int _grade);
    void print(std::ostream& out) const override;

public:
   
    Teacher() : User("teacher"), grade(0) {};
    Teacher(char const * _firstName, char const * _lastName, char const * pass, int _grade);

    void create(const char* _type = nullptr) override;
    void serialize(std::ostream& out) const override;
    void deserialize(std::istream& in) override;
    User* clone() const override { return new Teacher(*this); } 

};

#endif /* ifndef TEACHER_H */
