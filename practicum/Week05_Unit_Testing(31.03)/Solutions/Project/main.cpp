#include <iostream> 
#include <string.h>
#include "Teacher.h"
#include "Functions.h"
#include "Subject.h" //includes student.h
#include "University.h"

template <typename T>
using sortAllFunc= bool (*) (T, T);

template <typename T>
void sortAll(T* stud, sortAllFunc<T> sortFunc, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(sortFunc(stud[i], stud[j])) {
                T swapStud = stud[i];
                stud[i] = stud[j];
                stud[j] = swapStud;
            }            
        }
    }
}

template<typename T>
bool firstNameSort(T fst, T snd) {
    return strcmp(fst.getFName(), snd.getName()) > 0;
} 

template<typename T>
bool lastNameSort(T fst, T snd) {
    return strcmp(fst.getLName(), snd.getLName()) > 0;
} 

bool fnSort(Student fst, Student snd) {
    return fst.getFn() > snd.getFn();
}

template<typename T>
void printArray(T* arr, int size) {
    for(int i = 0; i < size; i++) {
        arr[i].print();
    }
}
 
template<typename T>  
void createObjArr(T * object, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << "Object #" << i << std::endl;
        object[i].create();
    }   
}

void serializationTesting(Teacher& teacher, Student * studs, int studentsSize, char * fileName) {
    Subject maths(studs, studentsSize, teacher, "Maths", studentsSize * 2);
    maths.serialize(fileName);
}

void deserializationTesting(char * fileName) {
    Subject newSubject;
    newSubject.deserialize(fileName);
    newSubject.printStudentsAndTeacher();
}

void universityTesting(Teacher * teacher, Student * studs, int studentsSize, int teacherSize) {
    Subject * subjects = new Subject[2];    
    subjects[0] = Subject(studs, studentsSize, teacher[0], "Maths", studentsSize * 2);
    subjects[1] = Subject(studs, studentsSize, teacher[0], "Programming", studentsSize * 2);

    //Testing all the constructors
    University nbu;
    University suni(studs, teacher, subjects, studentsSize, 2, teacherSize, "SofiaUni");
    University tuni(suni);
    nbu = suni;
   
    //Testing the addition of a student
    int scoresArr[3] = {1,2,3};
    Student newStud("Ivo", "Ivanov", 81821, 3, scoresArr);

    suni.addStudent(newStud);
    
    int newStudentsSize = suni.getStudentSize();

    if(newStudentsSize == studentsSize) {
        std::cout << "Not working size has not changed!" << std::endl;
    }

    Student addedStud = suni.getStudentById(newStudentsSize - 1); //gets the last student
    
    std::cout << addedStud.getFName() << std::endl;
    
    //Testing adding a student to a subject
    if(suni.addStudentToSubject("Ivo", "Programming")) {
        std::cout << "Adding student to subject successfull" << std::endl;
    }

    delete[] subjects;
}

int main() {
    int size;
    std::cout << "Please enter the amount of students you desire: ";
    std::cin >> size;
    std::cin.get(); //This is here to clear the buffer for cin.getline

    Student * students = new Student[size];
    createObjArr<Student>(students, size);

    sortAll<Student>(students, firstNameSort<Student>, size);
    printArray<Student>(students, size);

    std::cout << std::endl; 

    sortAll<Student>(students, fnSort, size);
    printArray<Student>(students, size);

    //This could be done with a template function but I think that would be too much
    int teacherSize;
    std::cout << "Please enter the amount of teacher you desire: ";
    std::cin >> teacherSize;
    std::cin.get(); //This is here to clear the buffer for cin.getline

    Teacher * teachers = new Teacher[size];
    createObjArr<Teacher>(teachers, teacherSize);
    
    sortAll<Teacher>(teachers, firstNameSort<Teacher>, teacherSize);
    printArray<Teacher>(teachers, teacherSize);
    
    Teacher constructorTest(teachers[0]);
    Student constructorTest2(students[0]);
    
    std::cout << constructorTest.getFName()<< std::endl;
    std::cout << constructorTest2.getLName()<< std::endl;

    char fileName[100] = "students.txt";
    serializationTesting(teachers[0], students, size, fileName);
    deserializationTesting(fileName);
    universityTesting(teachers, students, size, teacherSize);
}
