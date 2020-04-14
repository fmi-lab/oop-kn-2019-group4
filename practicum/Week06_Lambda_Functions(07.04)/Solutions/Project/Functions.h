#ifndef FUNCTION_H
#define FUNCTION_H 

#include <iostream>
#include <string.h>
#include <functional>

template<typename T>
void enterName(T& toBeNamed) {
    char firstName[100];
    char lastName[100];
    std::cout << "Enter person's firstName, lastName:" << std::endl;  
    std::cin.getline(firstName, 100);
    std::cin.getline(lastName, 100);
  
    toBeNamed.firstName = new char[strlen(firstName) + 1]; 
    toBeNamed.lastName = new char[strlen(lastName) + 1]; 
  
    strcpy(toBeNamed.firstName, firstName);
    strcpy(toBeNamed.lastName, lastName);
}

template<typename T>
void copyArray(T *& arr1, T const * arr2, int arr2size, int & arr1size) {

    if (arr1 != nullptr) {
        delete[] arr1;
    }

    arr1size = arr2size;
    arr1 = new T [arr2size];

    for (int i = 0; i < arr2size; ++i) {
        arr1[i] = arr2[i]; 
    }
}

template<typename T>
int findArrElementByName(char const * name, T const * arr, int size) {
    for (int i = 0; i < size; ++i) {
        if(strcmp(arr[i].getName(), name) == 0) {
            return i;
        }
    }

    return -1; //not found
}

template<typename T>
using predicate = bool (*) (T); // talk about this
//SUBCASES - they start the TEST_CASE from the start. Remember
//template<typename T, typename F>
template<typename T>
T * filter(T const * arr, int size, std::function<bool(T)> p, int& resultSize) {
    resultSize = 0;
    T * res = new T [size]; // I don't know the amount of elements will be filtered so I assume non will be
    
    for (int i = 0; i < size; ++i) {
        if(p(arr[i])) {
            res[resultSize++] = arr[i]; 
        }
    }

    return res;
}

#endif /* ifndef FUNCTION_H */
