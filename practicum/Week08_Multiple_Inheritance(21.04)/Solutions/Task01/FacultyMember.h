#ifndef FACULTY_MEMBER_H
#define FACULTY_MEMBER_H

#include "Student.h"
#include "Employee.h"

class FacultyMember : public Student, public Employee
{
protected:
    void copy(const char *name, int number, double salary);

public:
    FacultyMember();
    FacultyMember(const char *name, int number, double salary);
    FacultyMember(FacultyMember const &other);
    FacultyMember &operator=(FacultyMember const &other);
    ~FacultyMember();
};

#endif /* ifndef FACULTY_MEMBER_H */