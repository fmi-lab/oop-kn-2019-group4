#ifndef STUDENT
#define STUDENT_H
#include <iostream>

class Student {

public:
    char *firstName;
    char *lastName;
    int fn;
    int scoresSize;
    int *scores;

    Student() : firstName (nullptr), lastName(nullptr), fn(-1), scoresSize(0), scores(nullptr) {};
    Student(char * _firstName, char * _lastName, int _fn, int _scoresSize, int * _scores);
    Student(Student const& otherStudent);
    Student& operator=(Student const& otherStudent);
    
    void copy(char * _firstName, char * _lastName, int _fn, int _scoresSize, int * _scores);
    double averageScore();
    void print();
    void create();
    void serialize(std::ostream& out);
    void deserialize(std::istream& in);
};

#endif /* ifndef STUDENT_H */
