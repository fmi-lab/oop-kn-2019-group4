#include<iostream>
#include "IntContainer.h"
void IntContainer::copy(const IntContainer& other) {
    _capacity = other._capacity;
    _size = other._size;
    array = new int[other._capacity];
    for(int i=0;i < _size; i++){
        array[i] = other.array[i];
    }
}
void IntContainer::destroy() {
    delete [] array;
    array = nullptr;
    _size = 0;
    _capacity = 0;
}
void IntContainer::resize() {
    _capacity *= 2;
    int* new_array = new int[_capacity];
    for(int i=0;i< _size; i++){
        new_array[i] = array[i];
    }
    delete [] array;
    array = new_array;
}
IntContainer::IntContainer(): IntContainer(4){}
IntContainer::IntContainer(const size_t& new_capacity): _capacity{new_capacity}, _size{0}, array{new int[new_capacity]} {
    // std::cout << "Param called\n";
}
IntContainer::IntContainer(const IntContainer& other) {
    copy(other);
}
IntContainer::IntContainer(const std::initializer_list<int>& list) {
    // std::cout << "Init list called\n";
    _size = 0;
    _capacity = 2*list.size();
    array = new int[_capacity];
    for(int elem : list) {
        array[_size++] = elem;
    }
}
IntContainer::IntContainer(IntContainer&& other): array{other.array}, _size{other._size}, _capacity{other._capacity} {
    std::cout << "Moved\n";
    other.array = nullptr;
    other._size = 0;
    other._capacity = 0;
}
IntContainer::~IntContainer() {
    destroy();
}
IntContainer::operator bool() const {
    return _size != 0;
}
IntContainer& IntContainer::operator=(const IntContainer& other){
    // if(this != &other){
    //     destroy();
    //     copy(other);
    // }
    IntContainer other_copy(other);
    swap(other_copy);
    return *this;
}
void IntContainer::swap(IntContainer& other) {
    std::swap(array, other.array);
    std::swap(_size, other._size);
    std::swap(_capacity, other._capacity);
}
IntContainer& IntContainer::operator=(IntContainer&& other) {
    if(this == &other) return *this;
    array = other.array;
    _size = other._size;
    _capacity = other._capacity;
    other.array = nullptr;
    other._capacity = 0;
    other._size = 0;
    return *this;
}
size_t IntContainer::size() const {
    return _size;
}
size_t IntContainer::capacity() const {
    return _capacity;
}
int& IntContainer::operator[](const size_t& pos) {
    return array[pos];
}
const int& IntContainer::operator[](const size_t& pos) const{
    return array[pos];
}

void IntContainer::push_back(const int& element) {
    if(_capacity - _size == 1) {
        resize();
    }
    array[_size++] = element; 
}

void IntContainer::pop_back() {
    if(_size != 0) {
        _size--;
    }
}

void IntContainer::map(mapper m) {
    for(int i=0; i< _size; i++){
        m(array[i]);
    }
}

std::ostream& operator << (std::ostream& out, const IntContainer& c) {
    for(int i=0; i < c._size; i++){
        out << c.array[i] << " ";
    }
    return out;
}

IntContainer::MyIterator IntContainer::begin() const{
    return MyIterator{array};
}

IntContainer::MyIterator IntContainer::end() const {
    return MyIterator{array + _size};
}