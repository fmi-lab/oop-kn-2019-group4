#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <ostream>
#include <string>

#include "Functions.h"
#include "User.h"

class Student : public User {

    int fn;
    int scoresSize;
    int course;
    int * scores;
    
    void destroy();
    void copy(int _fn, int _scoresSize, int _course, int const * _scores);
    void print(std::ostream& out) const override;

public:
    Student() : User("student"), fn(-1), scoresSize(0), course(0), scores(nullptr) {};
    Student(char const * _firstName, char const * _lastName, int _fn, int _scoresSize,
            int _course, char const * pass, int const * _scores);
    Student(Student const& otherStudent);
    Student& operator=(Student const& otherStudent);
    ~Student();
    
    double averageScore() const;
    void create(const char * _typ = nullptr) override;
    void serialize(std::ostream& out) const override;
    void deserialize(std::istream& inp) override;

    User * clone() const override { return new Student(*this); } 
    
    int getFn() const { return this->fn; }
    int getCourse() const override { return this->course; }

    friend void enterName<Student> (Student& toBeNamed); 
};

#endif /* ifndef STUDENT_H */
