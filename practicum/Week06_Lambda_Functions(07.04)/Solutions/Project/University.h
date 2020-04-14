#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Subject.h"

class University {

    Teacher * teachers;
    Student * students; 
    Subject * subjects;
    char * name;

    int teacherSize;
    int teacherCapacity;
    int studentsSize;
    int studentCapacity;
    int subjectsSize;
    int subjectCapacity;
    // There should probably be a login class that remembers your session and as who you are logged in but I will use this for simplicity
    bool privilidged;
                    


    void copy (Student const * _students, Teacher const * _teachers, Subject const * _subjects,
               int _teacherSize, int _studentsSize, int _subjectsSize, char const * _name, bool _privilidged);

    void destroy();

    int findSubjectIndexByName(char const * name);
    int findStudentIndexByName(char const * name);
    int findTeacherIndexByName(char const * name);

public:

    University () : teachers(nullptr), students(nullptr), subjects(nullptr), name(nullptr), teacherSize(0), teacherCapacity(0), studentsSize(0),
                    studentCapacity(0), subjectsSize(0), subjectCapacity(0), privilidged(false) {};
    University (Student const * _students, Teacher const * _teachers, Subject const * _subjects,
                int _studentsSize, int _subjectsSize, int _teacherSize, char const * _name, bool _privilidged);
    University (University const&  other);
    University& operator=(University const& other);
    ~University ();
    
    Student getStudentById(int id) const;
    int getStudentSize() const { return this->studentsSize; }
    
    void listStudentsInCourse(int course);
    bool addStudentToSubject(char const * studentName, char const * subjectName);
    bool login(char const * userName, char const * pass); 
    void addStudent(Student const& stud);
    //gets the student based on his index in the array
};

#endif /* UNIVERSITY_H */
