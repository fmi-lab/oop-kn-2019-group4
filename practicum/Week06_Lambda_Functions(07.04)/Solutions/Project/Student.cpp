#include <fstream>
#include <iostream>
#include <string.h>

#include "Student.h"
#include "Functions.h"

void Student::copy(char const * _firstName, char const * _lastName, int _fn, int _scoresSize, 
            int _course, char const * pass, int const * _scores) {
    this->firstName = new char[ strlen(_firstName) + 1 ];
    this->lastName = new char[ strlen(_lastName) + 1 ];
    this->password = new char[ strlen(pass) + 1 ];

    strcpy(this->firstName, _firstName);
    strcpy(this->lastName, _lastName);
    strcpy(this->password, pass);

    this->fn = _fn;
    this->course = _course;

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


Student::Student(char const * _firstName, char const * _lastName, int _fn, int _scoresSize, 
        int _course, char const * pass, int const * _scores) {
    this->copy(_firstName, _lastName, _fn, _scoresSize, _course, pass, _scores);   
}

Student::Student(Student const& otherStudent) {
    this->copy(otherStudent.firstName, otherStudent.lastName, otherStudent.fn, otherStudent.scoresSize, 
            otherStudent.course, otherStudent.password, otherStudent.scores);   
}

Student& Student::operator=(Student const& otherStudent) {
    if(this != &otherStudent) { //this is here so we don't write student = student. We don't want to copy ourselves
        this->destroy(); 
        this->copy(otherStudent.firstName, otherStudent.lastName, otherStudent.fn, otherStudent.scoresSize, 
                otherStudent.course, otherStudent.password, otherStudent.scores);   
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
        sum += scores[i];
    }

    return sum / scoresSize;
}

void Student::print() const {
    std::cout << "First name: " << firstName << " Last name: " << lastName
              << " FN: " << fn << " Average score: " << averageScore() << std::endl;
}

void Student::create() {
    enterName<Student>(*this);
    std::cout << "Enter student faculty number: " << std::endl; 
    std::cin >> this->fn;
    std::cin.get();
    
    char pass[100];
    std::cout << "Enter the student password: " << std::endl;
    std::cin.getline(pass, 100);
    
    this->password = new char [strlen(pass) + 1];
    strcpy(this->password, pass);

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
    out << strlen(this->firstName) << " " << strlen(this->lastName) << " " << strlen(this->password) << " " 
        << this->firstName << " " << this->lastName << " " << this->password << " " 
        << this->fn << " " << this->course << " " << this->scoresSize << " ";
    
    for (int i = 0; i < this->scoresSize; ++i) {
        out << this->scores[i] << " ";
    }
}

void Student::deserialize(std::istream& in) {
    int size;
    
    this->destroy();

    in >> size; //firstName size
    this->firstName = new char [ size + 1 ]; //size + 1 for terminating zero
    in >> size; //lastName size
    this->lastName = new char [ size + 1 ];
    in >> size;;
    this->password = new char [ size + 1 ];

    in >> this->firstName
       >> this->lastName
       >> this->password
       >> this->fn
       >> this->course
       >> this->scoresSize; 
   
    this->scores = new int [ scoresSize ];

    for (int i = 0; i < this->scoresSize; ++i) {
        in >> this->scores[i];   
    }
}
