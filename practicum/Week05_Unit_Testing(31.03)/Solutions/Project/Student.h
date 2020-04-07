#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Functions.h"

class Student {

    char *firstName;
    char *lastName;
    int fn;
    int scoresSize;
    int *scores;
    
    void destroy();
    void copy(char const * _firstName, char const * _lastName, int _fn, int _scoresSize, int const * _scores);
    
public:
    Student() : firstName (nullptr), lastName(nullptr), fn(-1), scoresSize(0), scores(nullptr) {};
    Student(char const * _firstName, char const * _lastName, int _fn, int _scoresSize, int const * _scores);
    Student(Student const& otherStudent);
    Student& operator=(Student const& otherStudent);
    ~Student();
    
    double averageScore() const;
    void print() const;
    void create();
    void serialize(std::ostream& out) const;
    void deserialize(std::istream& in);
    
    char * getFName() const { return this->firstName; } 
    char * getName() const { return this->firstName; }
    char * getLName() const { return this->lastName; }
    int getFn() const { return this->fn; }

    friend void enterName<Student> (Student& toBeNamed); 
};

#endif /* ifndef STUDENT_H */
