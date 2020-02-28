#include<iostream>

using sample_function_type = void (*) (const int&);

void g(const int& elem){
    std::cout << "G() called: " << elem << '\n';
}

// void (*func) (const int&)
void f(const int& elem,  sample_function_type func){
    func(elem);
}

struct MyArr{
    int* arr;
    size_t arr_size;
    void print() {
        std::cout << arr_size;
    }
};

using predicate = bool (*)(const int&);
MyArr filter(MyArr arr_to_filter, predicate p){
    size_t filtered_count=0;
    for(int i=0;i < arr_to_filter.arr_size; i++){
        if (p(arr_to_filter.arr[i])) {
            filtered_count++;
        }
    }
    MyArr result;
    result.arr_size = filtered_count;
    result.arr = new int[result.arr_size];
    size_t current_index = 0;
    for(int i=0;i<arr_to_filter.arr_size; i++){
        if(p(arr_to_filter.arr[i])){
            result.arr[current_index++] = arr_to_filter.arr[i];
        }
    }
    return result;
}

bool isEven(const int& elem){
    return (elem % 2) == 0;
}

template<class T, class K=T, int Size=10>
K sum(T a, T b){
    T arr[Size];
    return a < b;
}

void f(int size){
    int arr[size];
}
int main() {
    sum<int, int>(2,3);
    sum<int, double>(3.2, 4.5);
    // f(2, g);
    MyArr arr_to_filter;
    arr_to_filter.arr = new int[10]{1,2,3,4,5,6,7,8,9,10};
    arr_to_filter.arr_size = 10;
    MyArr result = filter(arr_to_filter, isEven);
    std::cout << result.arr_size << std::endl;
    for(int i=0; i < result.arr_size; i++){
        std::cout << result.arr[i] << " ";
    }
    int** matrix = new int*[5];
    for(int i = 0; i < 5; i++){
        matrix[i] = new int[5];
    }
    for(int i=0;i < 5; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
    delete [] result.arr;
    delete [] arr_to_filter.arr;
    return 0;
}