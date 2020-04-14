#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Functions.h"

class Student {

    char *firstName;
    char *lastName;
    int fn;
    int scoresSize;
    int course;
    char * password;
    int *scores;
    
    void destroy();
    void copy(char const * _firstName, char const * _lastName, int _fn, int _scoresSize, int _course, char const * pass, int const * _scores);
    
public:
    Student() : firstName (nullptr), lastName(nullptr), fn(-1), scoresSize(0), course(0), password(nullptr), scores(nullptr) {};
    Student(char const * _firstName, char const * _lastName, int _fn, int _scoresSize, int _course, char const * pass, int const * _scores);
    Student(Student const& otherStudent);
    Student& operator=(Student const& otherStudent);
    ~Student();
    
    double averageScore() const;
    void print() const;
    void create();
    void serialize(std::ostream& out) const;
    void deserialize(std::istream& in);
    
    char const * getFName() const { return this->firstName; } 
    char const * getName() const { return this->firstName; }
    char const * getLName() const { return this->lastName; }
    char const * getPassword() const { return this-> password; }
    int getFn() const { return this->fn; }
    int getCourse() const { return this->course; }

    friend void enterName<Student> (Student& toBeNamed); 
};

#endif /* ifndef STUDENT_H */
