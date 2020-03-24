#ifndef TEACHER_H
#define TEACHER_H 
#include <fstream>
#include <ostream>

class Teacher {
public:
    char *firstName;
    char *lastName;
    int grade;
    
    Teacher() : firstName(nullptr), lastName(nullptr), grade(2) {};
    Teacher(char * _firstName, char * _lastName, int _grade);
    Teacher(Teacher const& otherTeacher);
    Teacher& operator=(Teacher const& otherTeacher);

    void copy(char * _firstName, char * _lastName, int _grade);
    void print();
    void create();
    void serialize(std::ostream& out);
    void deserialize(std::istream& in);
};


#endif /* ifndef TEACHER_H */
