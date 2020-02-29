#include<iostream>

using int_procedure = void (*) (const int&);

template<class T>
using template_procedure = void (*) (const T&);

void output_integer(const int& elem){
    std::cout << "Element: " << elem << '\n';
}

void integer_processor(const int& element,  int_procedure proc){
    proc(element);
}

template<class T>
void output_element(const T& element){
    std::cout << element << '\n';
}

template<class T>
void template_elem_processor(const T& element, template_procedure<T> proc){
    proc(element);
}

struct MyArray{
    int* array_container;
    size_t array_size;
};

using predicate = bool (*)(const int&);
MyArray filter(MyArray arr_to_filter, predicate p){
    size_t filtered_count=0;
    for(int i=0;i < arr_to_filter.array_size; i++){
        if (p(arr_to_filter.array_container[i])) {
            filtered_count++;
        }
    }
    MyArray result;
    result.array_size = filtered_count;
    result.array_container = new int[result.array_size];
    size_t current_index = 0;
    for(int i=0;i<arr_to_filter.array_size; i++){
        if(p(arr_to_filter.array_container[i])){
            result.array_container[current_index++] = arr_to_filter.array_container[i];
        }
    }
    return result;
}

bool isEven(const int& elem){
    return (elem % 2) == 0;
}

template<class T, class K=T>
K sum(T a, T b){
    return a + b;
}
// a bad way of initializing dynamic array
void consume_array(const size_t& size){
    int array[size];
    // futher operations...
}

// using templates we can initialize static arrays
template<class T, int Size=10>
void consume_array(){
    T array[Size];
    // further operations...
}

void sumTests(){
    // implicit initialization
    std::cout << sum(2,3) << '\n';
    // explicit initialization
    std::cout << sum<double, double>(3.2, 4.5) << '\n';
}
void higherOrderFunctionsTests(){
    // will the next function work if I change the first parameter to be a non-const?
    integer_processor(12, output_integer);
    // same question applies here
    template_elem_processor<int>(12, output_element);
}

void filterTests() {
    MyArray arr_to_filter;
    arr_to_filter.array_container = new int[10]{1,2,3,4,5,6,7,8,9,10};
    arr_to_filter.array_size = 10;
    MyArray result = filter(arr_to_filter, isEven);
    std::cout << result.array_size << std::endl;
    for(int i=0; i < result.array_size; i++){
        std::cout << result.array_container[i] << " ";
    }
    delete [] result.array_container;
    delete [] arr_to_filter.array_container;
}
void matrixInitalization() {
    int** matrix = new int*[5];
    for(int i = 0; i < 5; i++){
        matrix[i] = new int[5];
    }
    for(int i=0;i < 5; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
}

// TODO: Another higher oder function that you can try to implement is map.
// How it works(pseudo code):
// map([1,2,3,4,5,6,7,8], addOne) -> [2,3,4,5,6,7,8,9]
// Map usually takes two arguments - a collection and a procedure. Usually the procedure should require only one argument but it could have multiple ones with default values.
// It iterates over that collection(in the case above over an array) and applies the procedure on every element
// Usually it return new collection with the modified elements and preserves the old one.
// Another example: map([1,2,3], doubleEvens) -> [1,4,3]
// Your tasks is to complete the function below so that it implements a map that covers the above definition.

// Uncomment the lines below to proceed
// using mapper = /* that is how we are naming the type of the procedure */

// // make it a template function. Also lets assume that the function can be applied only on arrays
// /*return type*/ map(/*collection_type*/ collection, mapper m){
//     //finish the body of this function
// }

int main() {
    sumTests();
    higherOrderFunctionsTests();
    filterTests();
    matrixInitalization();
    // mapTests(); -> tests for the map function
    return 0;
}