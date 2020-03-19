#include <iostream>
#include <string.h>
#include "Task3_Teacher.h"
#include "Task3_EnterName.h"


//This can and probably should be put in another file and imported like the teacher
//I haven't done that with the idea that this builds upon Task2
class Student
{
public:
    char *firstName;
    char *lastName;
    int fn;
    int scoresSize;
    int *scores;

    double averageScore()
    {
        double sum = 0;

        for (int i = 0; i < scoresSize; i++)
        {
            sum += scores[i];
        }

        return sum / scoresSize;
    }

    void print()
    {
        std::cout << "First name: " << firstName << " Last name: " << lastName
                  << " FN: " << fn << " Average score: " << averageScore() << std::endl;
    }

    void create() {
        enterName<Student>(*this);
        std::cout << "Enter student faculty number: " << std::endl; 
        std::cin >> this->fn;
        std::cin.get();

        std::cout << "Enter number of subjects a student has and his scores" << std::endl;
        std::cin >> scoresSize;

        scores = new int[scoresSize];

        for (int j = 0; j < scoresSize; j++)
        {
            std::cout << "Enter score #" << j + 1 << std::endl;
            std::cin >> scores[j];
        }

        std::cin.get();

    }
};


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
}
