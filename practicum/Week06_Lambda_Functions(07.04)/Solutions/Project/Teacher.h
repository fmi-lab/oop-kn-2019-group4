#ifndef TEACHER_H
#define TEACHER_H 
#include <fstream>
#include <ostream>
#include "Functions.h"

class Teacher {
    char * firstName;
    char * lastName;
    char * password;
    int grade;

    void destroy();
    void copy(char const * _firstName, char const * _lastName, char const * pass, int _grade);
 
public:
   
    Teacher() : firstName(nullptr), lastName(nullptr), password(0), grade(2) {};
    Teacher(char const * _firstName, char const * _lastName, char const * pass, int _grade);
    Teacher(Teacher const& otherTeacher);
    Teacher& operator=(Teacher const& otherTeacher);
    ~Teacher();

    void print() const;
    void create();
    void serialize(std::ostream& out) const;
    void deserialize(std::istream& in);
   
    char const * getFName() const { return this->firstName; }
    char const * getName() const { return this->firstName; }
    char const * getLName() const { return this->lastName; }
    char const * getPassword() const { return this->password; }

    friend void enterName<Teacher>(Teacher& toBeNamed); 
};

#endif /* ifndef TEACHER_H */
