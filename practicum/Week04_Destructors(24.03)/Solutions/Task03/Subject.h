#ifndef SUBJECT_H
#define SUBJECT_H

#include "Student.h"
#include "Teacher.h"

class Subject {
public:
    Student * students;
    Teacher teacher;
    int studentsSize;

    Subject () : students(nullptr), studentsSize(0) {};
    Subject (Student * _students, int _studentsSize,  Teacher& _teacher);
    Subject(const Subject &otherSubject);
    Subject& operator=(const Subject & otherSubject);
    ~Subject();
    
    void destroy();
    void copy(Student * _students, int _studentsSize, Teacher _teacher);
    void serialize(char * fileName);
    void deserialize(char * fileName);
    void printStudentsAndTeacher();
};

#endif /* SUBJECT_H */
