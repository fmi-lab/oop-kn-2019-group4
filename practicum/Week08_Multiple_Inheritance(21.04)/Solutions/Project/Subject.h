#include "Student.h"
#include "Teacher.h"

#ifndef SUBJECT_H
#define SUBJECT_H

class Subject {
    Student * students;
    Teacher teacher;
    int studentsSize;
    int studentCapacity;
    char * name;

    void destroy();
    void copy(Student const * _students, int _studentsSize, Teacher _teacher, char const * _name, int studentCapacity);
    bool isEnrolled(int fn) const;
public:
    Subject () : students(nullptr), studentsSize(0), studentCapacity(0), name(nullptr) {};
    Subject (Student const * _students, int _studentsSize,  Teacher& _teacher, char const * _name, int studentCapacity);
    Subject(const Subject &otherSubject);
    Subject& operator=(const Subject & otherSubject);
    ~Subject();
   
    char * getName() const { return name; } 

    void serialize(const char * fileName) const;
    void deserialize(const char * fileName);
    void printStudentsAndTeacher();
    bool addStudent(Student const& stud);
};

#endif /* SUBJECT_H */
