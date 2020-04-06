#include <iostream>
#include <string.h>
#include "Teacher.h"
#include "EnterName.h"
#include "Subject.h" //Includes student.h

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
    return strcmp(fst.firstName, snd.firstName) > 0;
} 

template<typename T>
bool lastNameSort(T fst, T snd) {
    return strcmp(fst.lastName, snd.lastName) > 0;
} 

bool fnSort(Student fst, Student snd) {
    return fst.fn > snd.fn; 
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
    Subject maths(studs, studentsSize, teacher);
    maths.serialize(fileName);
}

void deserializationTesting(char * fileName) {
    Subject newSubject;
    newSubject.deserialize(fileName);
    newSubject.printStudentsAndTeacher();
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
    
    std::cout << constructorTest.firstName << std::endl;
    std::cout << constructorTest2.firstName << std::endl;

    char fileName[100] = "students.txt";
    serializationTesting(teachers[0], students, size, fileName);
    deserializationTesting(fileName);
}
