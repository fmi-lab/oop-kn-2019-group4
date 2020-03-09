#include <iostream>
#include <string.h>

struct Student {
    char * firstName;
    char * lastName;
    int fn;
};

struct Teacher {
    char * firstName;
    char * lastName;
    int grade;
};

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

void printStudentArray(Student * studs, int size) {
    std::cout << "First name " << "Last Name " << "FN" << std::endl; 
   
    for(int i = 0; i < size; i++) {
        std::cout << studs[i].firstName << " " << studs[i].lastName
                  << " " << studs[i].fn << std::endl;
    }
}

void printTeacherArray(Teacher* teachs, int size) {
    std::cout << "First name " << "Last Name " << "Grade" << std::endl; 
   
    for(int i = 0; i < size; i++) {
        std::cout << teachs[i].firstName << " " << teachs[i].lastName
                  << " " << teachs[i].grade << std::endl;
    }
}

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
void enterName(T& toBeNamed, int number) {
    char firstName[100];
    char lastName[100];
    std::cout << "Enter person #" << number << "'s firstName, lastName:" << std::endl;  
    std::cin.getline(firstName, 100);
    std::cin.getline(lastName, 100);
  
    toBeNamed.firstName = new char[strlen(firstName) + 1]; 
    toBeNamed.lastName = new char[strlen(lastName) + 1]; 
  
    strcpy(toBeNamed.firstName, firstName);
    strcpy(toBeNamed.lastName, lastName);
}
 
void createStudents(Student * students, int size) {
    for(int i = 0; i < size; i++) {
        enterName<Student>(students[i], i);
        std::cout << "Enter student faculty number: " << std::endl; 
        std::cin >> students[i].fn;
        std::cin.get();
    }   
}
  
void createTeachers(Teacher * teachs, int size) {
    for(int i = 0; i < size; i++) {
        enterName<Teacher>(teachs[i], i);    
        std::cout << "Enter teacher's grade: " << std::endl; 
        std::cin >> teachs[i].grade;
        std::cin.get();
    }   
}

int main() {
    int size;
    std::cout << "Please enter the amount of students you desire: ";
    std::cin >> size;
    std::cin.get(); //This is here to clear the buffer for cin.getline

    Student * students = new Student[size];
    createStudents(students, size);

    sortAll<Student>(students, firstNameSort<Student>, size);
    printStudentArray(students, size);

    std::cout << std::endl; 

    sortAll<Student>(students, fnSort, size);
    printStudentArray(students, size);

    //This could be done with a template function but I think that would be too much
    int teacherSize;
    std::cout << "Please enter the amount of teacher you desire: ";
    std::cin >> teacherSize;
    std::cin.get(); //This is here to clear the buffer for cin.getline

    Teacher * teachers = new Teacher[size];
    createTeachers(teachers, teacherSize);
    
    sortAll<Teacher>(teachers, firstNameSort<Teacher>, teacherSize);
    printTeacherArray(teachers, teacherSize);
}
