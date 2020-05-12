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
    if(this->students) {
        delete[] this->students;
    }

    if(this->name) {
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

void Subject::serialize(const char * fileName) const {
    std::ofstream out(fileName);   
    out << "Subject " << strlen(this->name) << " " << this->name << " " << studentsSize << " ";
    
    this->teacher.serialize(out);

    for (int i = 0; i < studentsSize; ++i) {
       this->students[i].serialize(out); 
    }

    out.close();
}

void Subject::deserialize(const char * fileName) {
    std::ifstream inp(fileName);
    char fileData[100];
    inp >> fileData;
    int nameSize;
  
    if(strcmp(fileData, "Subject") == 0) {
        inp >> nameSize;
        this->name = new char [nameSize];
        inp >> this->name;

        inp >> this->studentsSize;
        this->teacher.deserialize(inp);
        this->students = new Student[this->studentsSize * 2];
        this->studentCapacity = this->studentsSize * 2; 

        for (int i = 0; i < studentsSize; ++i) {
           this->students[i].deserialize(inp); 
        }
    }
   
    inp.close();
}

void Subject::printStudentsAndTeacher() {
    
    std::cout << "Subject name: " << this->name << std::endl;

    std::cout << this->teacher << std::endl;
    
    for (int i = 0; i < this->studentsSize; ++i) {
        std::cout << this->students[i];    
    }
}

bool Subject::isEnrolled(int fn) const {
    int resultSize = 0;
    filter<Student>(this->students, this->studentsSize, 
                    [fn] (Student stud) { return stud.getFn() == fn; }, resultSize);

    return resultSize != 0;
}

bool Subject::addStudent(Student const& stud) {

    if(isEnrolled(stud.getFn())) {
        std::cout << "Already enrolled" << std::endl;
        return false;
    }

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
    return true;
}
