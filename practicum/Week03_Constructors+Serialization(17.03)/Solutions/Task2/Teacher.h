#pragma once

class Teacher {
public:
    char *firstName;
    char *lastName;
    int grade;
    
    Teacher() : firstName(nullptr), lastName(nullptr), grade(2) {};
    Teacher(char * _firstName, char * _lastName, int _grade);
    Teacher(Teacher const& otherTeacher);

    void copy(char * _firstName, char * _lastName, int _grade);
    void print();
    void create();
};


