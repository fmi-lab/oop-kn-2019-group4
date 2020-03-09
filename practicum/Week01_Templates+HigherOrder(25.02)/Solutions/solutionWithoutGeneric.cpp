#include <iostream>
#include <string.h>

struct Student {
    char * firstName;
    char * lastName;
    int fn;
};

using sortStudentFunc = bool (*) (Student, Student);

void sortStudents(Student * stud, sortStudentFunc sortFunc, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(sortFunc(stud[i], stud[j])) {
               Student swapStud = stud[i];
               stud[i] = stud[j];
               stud[j] = swapStud;
            }            
        }
    }
}

bool firstNameSort(Student fst, Student snd) {
    return strcmp(fst.firstName, snd.firstName) > 0; 
}

bool lastNameSort(Student fst, Student snd) {
    return strcmp(fst.lastName, snd.lastName) > 0;
} 


bool fnSort(Student fst, Student snd) {
    return fst.fn > snd.fn;
}

void printStudentArray(Student * studs, int size) {
    std::cout << "First name " << "Last Name " << "FN" << std::endl; 
   
    for(int i = 0; i < size; i++) {
        std::cout << studs[i].firstName << " " << studs[i].lastName
                  << " " << studs[i].fn << std::endl;
    }
}

void createStudents(Student * students, int size) {
    for(int i = 0; i < size; i++) {
        char firstName[100];
        char lastName[100];
        std::cout << "Enter Student #" << i << "'s firstName, lastName and faculty number:" << std::endl;  
        std::cin.getline(firstName, 100);
        std::cin.getline(lastName, 100);

        std::cin >> students[i].fn;
        std::cin.get();

        students[i].firstName = new char[strlen(firstName) + 1];
        students[i].lastName = new char[strlen(lastName) + 1];

        strcpy(students[i].firstName, firstName);
        strcpy(students[i].lastName, lastName);
    }
}

int main() {
    int size;
    std::cout << "Please enter the amount of students you desire: ";
    std::cin >> size;
    std::cin.get(); //This is here to clear the buffer for cin.getline

    Student * students = new Student[size];
    createStudents(students, size);

    sortStudents(students, firstNameSort, size);
    printStudentArray(students, size);

    std::cout << std::endl; 

    sortStudents(students, fnSort, size);
    printStudentArray(students, size);
}
