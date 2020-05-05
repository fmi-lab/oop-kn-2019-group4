#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : virtual public Person
{
    int number;

protected:
    void copy(const char *name, int number);

public:
    Student();
    Student(const char *name, int number);
    Student(Student const &otherStudent);
    Student &operator=(Student const &otherStudent);
    ~Student();

    int getNumber() const { return this->number; }
};

#endif /* ifndef STUDENT_H */