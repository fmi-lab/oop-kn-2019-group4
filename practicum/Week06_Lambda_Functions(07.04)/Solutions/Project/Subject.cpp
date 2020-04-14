#include "Subject.h"
#include <iostream>
#include <fstream>
#include <string.h>

void Subject::copy(Student const * _students, int _studentsSize, Teacher _teacher, char const * _name, int _studentCapacity) {
    this->teacher = _teacher;
    
    this->name = new char [strlen(_name) + 1];
    strcpy(this->name, _name); 

    this->studentsSize = _studentsSize;
    this->studentCapacity = _studentCapacity;
    this->students = new Student [this->studentCapacity];

    for (int i = 0; i < studentsSize; ++i) {
        this->students[i] = _students[i]; 
    }
}

void Subject::destroy() {
    if(this->students != nullptr) {
        delete[] this->students;
    }

    if(this->name != nullptr) {
        delete[] this->name;
    }
}

Subject::Subject (Student const * _students, int _studentsSize, Teacher& _teacher, char const * _name, int _studentCapacity) {
    this->copy(_students, _studentsSize, _teacher, _name, _studentCapacity);   
}

Subject::Subject(const Subject &otherSubject) {
    this->copy(otherSubject.students, otherSubject.studentsSize, otherSubject.teacher, otherSubject.name, otherSubject.studentCapacity);   
}

Subject& Subject::operator=(const Subject & otherSubject) {
    if(this != &otherSubject) {
        this->destroy();
        this->copy(otherSubject.students, otherSubject.studentsSize, otherSubject.teacher, otherSubject.name, otherSubject.studentCapacity);
    }

    return *this;
}

Subject::~Subject() {
   this->destroy(); 
}

void Subject::serialize(char * fileName) const {
    std::ofstream out(fileName);   
    out << "Subject " << strlen(this->name) << " " << this->name << " " << studentsSize << " ";
    
    this->teacher.serialize(out);

    for (int i = 0; i < studentsSize; ++i) {
       this->students[i].serialize(out); 
    }

    out.close();
}

void Subject::deserialize(char * fileName) {
    std::ifstream in(fileName);
    char fileData[100];
    in >> fileData;
    int nameSize;
    if(strcmp(fileData, "Subject") == 0) {
        in >> nameSize;
        this->name = new char [nameSize];
        in >> this->name;

        in >> this->studentsSize;
        this->teacher.deserialize(in);
        this->students = new Student[this->studentsSize * 2];
        this->studentCapacity = this->studentsSize * 2; 

        for (int i = 0; i < studentsSize; ++i) {
           this->students[i].deserialize(in); 
        }
    }
   
    in.close();
}

void Subject::printStudentsAndTeacher() {
    
    std::cout << "Subject name: " << this->name << std::endl;

    this->teacher.print();
    
    for (int i = 0; i < this->studentsSize; ++i) {
        this->students[i].print();    
    }
}

void Subject::addStudent(Student const& stud) {

    if(this->studentsSize >= this->studentCapacity) {
        Student * newArr = new Student [ 2 * this->studentCapacity ];
        this->studentCapacity *= 2; 

        for (int i = 0; i < this->studentsSize; ++i) {
            newArr[i] = this->students[i];
        }

        delete[] this->students;
        this->students = newArr;
    }
    
    this->students[this->studentsSize++] = stud;
}
