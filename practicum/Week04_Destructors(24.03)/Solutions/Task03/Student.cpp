#include <fstream>
#include <iostream>
#include <string.h>

#include "Student.h"
#include "EnterName.h"

void Student::copy(char * _firstName, char * _lastName, int _fn, int _scoresSize, int * _scores) {
    this->firstName = new char[strlen(_firstName) + 1];
    this->lastName = new char[strlen(_lastName) + 1];

    strcpy(this->firstName, _firstName);
    strcpy(this->lastName, _lastName);

    this->fn = _fn;
    
    this->scoresSize = _scoresSize;
    this->scores = new int [this->scoresSize];

    for (int i = 0; i < this->scoresSize; ++i) {
        this->scores[i] = _scores[i];   
    }   
}

void Student::destroy() {
    if(this->firstName != nullptr) {
        delete[] this->firstName;
    }

    if(this->lastName != nullptr) {
        delete[] this->lastName;
    }

    if(this->scores != nullptr) {
        delete[] this->scores;
    }
}


Student::Student(char * _firstName, char * _lastName, int _fn, int _scoresSize, int * _scores) {
    this->copy(_firstName, _lastName, _fn, _scoresSize, _scores);   
}

Student::Student(Student const& otherStudent) {
    this->copy(otherStudent.firstName, otherStudent.lastName, otherStudent.fn, otherStudent.scoresSize, otherStudent.scores);   
}

Student& Student::operator=(Student const& otherStudent) {
    if(this != &otherStudent) { //this is here so we don't write student = student. We don't want to copy ourselves
        this->destroy(); 
        this->copy(otherStudent.firstName, otherStudent.lastName, otherStudent.fn, otherStudent.scoresSize, otherStudent.scores);   
    }

    return *this;
}

Student::~Student() {
    this->destroy();
}

double Student::averageScore() {
    double sum = 0;

    for (int i = 0; i < scoresSize; i++)
    {
        sum += scores[i];
    }

    return sum / scoresSize;
}

void Student:: print() {
    std::cout << "First name: " << firstName << " Last name: " << lastName
              << " FN: " << fn << " Average score: " << averageScore() << std::endl;
}

void Student::create() {
    enterName<Student>(*this);
    std::cout << "Enter student faculty number: " << std::endl; 
    std::cin >> this->fn;
    std::cin.get();

    std::cout << "Enter number of subjects a student has and his scores" << std::endl;
    std::cin >> this->scoresSize;

    this->scores = new int[scoresSize];

    for (int j = 0; j < scoresSize; j++)
    {
        std::cout << "Enter score #" << j + 1 << std::endl;
        std::cin >> scores[j];
    }

    std::cin.get();
}

void Student::serialize(std::ostream& out) {
    out << strlen(this->firstName) << " " << strlen(this->lastName) << " " << this->firstName << " " << this->lastName 
        << " " << this->fn << " " << this->scoresSize << " ";
    
    for (int i = 0; i < this->scoresSize; ++i) {
        out << this->scores[i] << " ";
    }
}

void Student::deserialize(std::istream& in) {
    int size;
    
    in >> size; //firstName size
    delete[] this->firstName;
    this->firstName = new char [ size + 1 ]; //size + 1 for terminating zero
    in >> size; //lastName size
    this->lastName = new char [ size + 1 ];
    
    in >> this->firstName
       >> this->lastName
       >> this->fn
       >> this->scoresSize; 
   
    this->scores = new int [ scoresSize ];

    for (int i = 0; i < this->scoresSize; ++i) {
        in >> this->scores[i];   
    }
}
