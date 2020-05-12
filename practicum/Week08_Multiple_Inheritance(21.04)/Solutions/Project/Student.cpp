#include <fstream>
#include <iostream>
#include <ostream>
#include <string.h>
#include "Student.h"

void Student::copy(int _fn, int _scoresSize, int _course, int const * _scores) {
    this->fn = _fn;
    this->course = _course;

    this->scoresSize = _scoresSize;
    this->scores = new int [this->scoresSize];

    for (int i = 0; i < this->scoresSize; ++i) {
        this->scores[i] = _scores[i];   
    }
}

void Student::destroy() {
    if(this->scores) {
        delete[] this->scores;
        this->scores = nullptr;
    }
}

Student::Student(char const * _firstName, char const * _lastName, int _fn, int _scoresSize, 
                 int _course, char const * pass, int const * _scores) : User(_firstName, _lastName, pass, "student") {
    this->copy(_fn, _scoresSize, _course, _scores);   
}

Student::Student(Student const& otherStudent) : User(otherStudent) {
    this->copy(otherStudent.fn, otherStudent.scoresSize, otherStudent.course, otherStudent.scores);   
}

Student& Student::operator=(Student const& otherStudent) {

    if(this != &otherStudent) { //this is here so we don't write student = student. We don't want to copy ourselves
        this->destroy(); 
        User::operator=(otherStudent);
        this->copy(otherStudent.fn, otherStudent.scoresSize, 
                   otherStudent.course, otherStudent.scores);   
    }

    return *this;
}

Student::~Student() {
    this->destroy();
}

double Student::averageScore() const {
    double sum = 0;

    for (int i = 0; i < scoresSize; i++)
    {
        sum += scores[i]; }

    return sum / scoresSize;
}

void Student::print(std::ostream& out) const {
    User::print(out);
    out << " FN: " << this->fn << " Course: " << this->course << " Average: " << this->averageScore();
}

void Student::create(const char * _type) {
    User::create("student");

    std::cout << "Enter student faculty number: " << std::endl; 
    std::cin >> this->fn;

    std::cout << "Enter the course: " << std::endl;
    std::cin >> this->course;

    std::cout << "Enter number of subjects a student has and his scores: " << std::endl;
    std::cin >> this->scoresSize;

    this->scores = new int[scoresSize];

    for (int j = 0; j < scoresSize; j++)
    {
        std::cout << "Enter score #" << j + 1 << std::endl;
        std::cin >> scores[j];
    }

    std::cin.get();
}

void Student::serialize(std::ostream& out) const {
    User::serialize(out);
    out << this->fn << " " << this->course << " " << this->scoresSize << " ";
    
    for (int i = 0; i < this->scoresSize; ++i) {
        out << this->scores[i] << " ";
    }
}

void Student::deserialize(std::istream& inp) {
    this->destroy();
    User::deserialize(inp);

    inp >> this->fn
        >> this->course
        >> this->scoresSize; 
   
    this->scores = new int [ scoresSize ];

    for (int i = 0; i < this->scoresSize; ++i) {
        inp >> this->scores[i];   
    }
}
