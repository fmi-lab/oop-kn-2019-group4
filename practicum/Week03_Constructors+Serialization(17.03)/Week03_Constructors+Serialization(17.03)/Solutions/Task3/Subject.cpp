#include "Subject.h"
#include <iostream>
#include <fstream>
#include <string.h>

void Subject::copy(Student * _students, int _studentsSize, Teacher& _teacher) {
    this->teacher = _teacher;

    this->studentsSize = _studentsSize;
    this->students = new Student [this->studentsSize];

    for (int i = 0; i < studentsSize; ++i) {
        this->students[i] = _students[i]; 
    }
}

Subject::Subject (Student * _students, int _studentsSize, Teacher& _teacher) {
    this->copy(_students, _studentsSize, _teacher);   
}


void Subject::serialize(char * fileName) {
    std::ofstream out(fileName);   
    out << "Subject " << studentsSize << " ";
    
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

    if(strcmp(fileData, "Subject") == 0) {
        in >> this->studentsSize;
        this->teacher.deserialize(in);
        this->students = new Student[this->studentsSize];
        
        for (int i = 0; i < studentsSize; ++i) {
           this->students[i].deserialize(in); 
        }
    }
   
    in.close();
}

void Subject::printStudentsAndTeacher() {
    this->teacher.print();

    for (int i = 0; i < this->studentsSize; ++i) {
        this->students[i].print();    
    }
}
