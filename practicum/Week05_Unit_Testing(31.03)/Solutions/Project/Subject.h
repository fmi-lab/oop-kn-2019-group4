#ifndef SUBJECT_H
#define SUBJECT_H

#include "Student.h"
#include "Teacher.h"

class Subject {
    Student * students;
    Teacher teacher;
    int studentsSize;
    int studentCapacity;
    char * name;

    void destroy();
    void copy(Student const * _students, int _studentsSize, Teacher _teacher, char const * _name, int studentCapacity);
    
public:
    Subject () : students(nullptr), studentsSize(0), studentCapacity(0), name(nullptr) {};
    Subject (Student const * _students, int _studentsSize,  Teacher& _teacher, char const * _name, int studentCapacity);
    Subject(const Subject &otherSubject);
    Subject& operator=(const Subject & otherSubject);
    ~Subject();
   
    char * getName() const { return name; } 

    void serialize(char * fileName) const;
    void deserialize(char * fileName);
    void printStudentsAndTeacher();
    void addStudent(Student const& stud);
};

#endif /* SUBJECT_H */
