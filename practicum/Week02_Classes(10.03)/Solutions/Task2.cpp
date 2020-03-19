#include <iostream>
#include <string.h>

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

    void printStudent()
    {
        std::cout << firstName << " " << lastName
                  << " " << fn << " " << averageScore() << std::endl;
    }

    void create() {
        char _firstName[100];
        char _lastName[100];


        std::cin.getline(_firstName, 100);
        std::cin.getline(_lastName, 100);

        std::cin >> fn;
        std::cin >> scoresSize;

        scores = new int[scoresSize];

        for (int j = 0; j < scoresSize; j++)
        {
            std::cout << "Enter score #" << j + 1 << std::endl;
            std::cin >> scores[j];
        }

        std::cin.get();

        firstName = new char[strlen(_firstName) + 1];
        lastName = new char[strlen(_lastName) + 1];

        strcpy(firstName, _firstName);
        strcpy(lastName, _lastName);

    }
};

void createStudents(Student *students, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter Student #" << i + 1 << "'s firstName, lastName, faculty number, number of scores, scores:" << std::endl;
        students[i].create();
    }
}

void printStudentArray(Student *students, int size)
{
    std::cout << "First name "
              << "Last Name "
              << "FN "
              << "Avarage Score" << std::endl;

    for (int i = 0; i < size; i++)
    {
        students[i].printStudent();        
    }
}

template <typename T>
bool firstNameSort(T fst, T snd)
{
    return strcmp(fst.firstName, snd.firstName) > 0;
}

template <typename T>
using sortAllFunc = bool (*)(T, T);

bool firstNameSort(Student fst, Student snd)
{
    return strcmp(fst.firstName, snd.firstName) > 0;
}

template <typename T>
void sortAll(T *stud, sortAllFunc<T> sortFunc, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (sortFunc(stud[i], stud[j]))
            {
                T swapStud = stud[i];
                stud[i] = stud[j];
                stud[j] = swapStud;
            }
        }
    }
}

int main()
{
    int size;
    std::cout << "Please enter the amount of students you desire: ";
    std::cin >> size;
    std::cin.get(); //This is here to clear the buffer for cin.getline

    Student *students = new Student[size];
    createStudents(students, size);

    sortAll<Student>(students, firstNameSort, size);

    printStudentArray(students, size);
}
