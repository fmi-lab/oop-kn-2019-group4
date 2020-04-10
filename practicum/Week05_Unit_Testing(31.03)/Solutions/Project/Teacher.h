#ifndef TEACHER_H
#define TEACHER_H 
#include <fstream>
#include <ostream>
#include "Functions.h"

class Teacher {
    char *firstName;
    char *lastName;
    int grade;

    void destroy();
    void copy(char const * _firstName, char const * _lastName, int _grade);
 
public:
   
    Teacher() : firstName(nullptr), lastName(nullptr), grade(2) {};
    Teacher(char const * _firstName, char const * _lastName, int _grade);
    Teacher(Teacher const& otherTeacher);
    Teacher& operator=(Teacher const& otherTeacher);
    ~Teacher();

    void print() const;
    void create();
    void serialize(std::ostream& out) const;
    void deserialize(std::istream& in);
   
    char * getFName() const { return this->firstName; }
    char * getName() const { return this->firstName; }
    char * getLName() const { return this->lastName; }


    friend void enterName<Teacher>(Teacher& toBeNamed); 
};

#endif /* ifndef TEACHER_H */
