#include<iostream>
#include<cassert>

class IntContainer{
    int* array;
    size_t size;
    size_t capacity;
    void copy(const IntContainer& other){
        capacity = other.capacity;
        size = other.size;
        array = new (std::nothrow) int[capacity];
        for(int i = 0; i < size; i++){
            array[i] = other.array[i];
        }
    }
    void delete_container() {
        delete [] array;
        size = 0;
        capacity = 0;
    }
    public:
    IntContainer() = default;
    // IntContainer(const size_t& _capacity):capacity{_capacity}, size{0} {
    //     if (capacity == 0) {
    //         array = nullptr;
    //     } else {
    //         array = new int [capacity];
    //     }
    // }
    // IntContainer(const size_t& _capacity) = default;
    IntContainer(const IntContainer& other) {
        copy(other);
    }
    // IntContainer(const IntContainer& other) = default;
    IntContainer& operator =(const IntContainer& other) {
        if(this != &other){
            delete_container();
            copy(other);
        }
        return *this;
    }
    // IntContainer& operator =(const IntContainer& other) = default;
    // ~IntContainer(){
    //     delete_container();
    // }
    ~IntContainer() = default;
    // IntContainer(const size_t& _size, const int*& elements) {

    // }
    // // operator that 
    // IntContainer operator + (const int& element) {
    //     IntContainer result(*this);
    //     assert( _size < 100);
    //     result._array[_size++] = element;
    //     return result;
    // }
    // IntContainer& operator += (const int& element) {
    //     if( _size < 100){
    //         _array[_size++] = element;
    //     }
    //     return *this;
    // }
    // IntContainer operator + (const IntContainer& other) {
    //     assert((_size + other._size) < 100);
    //     IntContainer result(*this);
    //     for(int i=0; i< other._size; i++){
    //         result += other._array[i];
    //     }
    //     return result;
    // }
    size_t getSize() const {
        return size;
    }
};

int main() {
    int a ,b;
    int c(a);
    a = b + c;

    // const IntContainer test{};
    // IntContainer test_container{10}; //IntContainer test_container();
    IntContainer copy;
    // ...copy
    IntContainer other_copy(15);
    // other_copy adding...
    IntContainer other_other_copy(20);
    copy = other_copy = other_other_copy;//copy.operator=(other_copy.operator=(other_other_copy));
    // copy = test_container;
    IntContainer* pointer_to_container = new IntContainer;
    delete pointer_to_container;
}