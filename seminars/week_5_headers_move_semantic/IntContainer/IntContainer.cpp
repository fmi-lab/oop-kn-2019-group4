#include<iostream>
#include "IntContainer.h"
void IntContainer::copy(const IntContainer& other) {
    capacity = other.capacity;
    _size = other._size;
    array = new int[other.capacity];
    for(int i=0;i < _size; i++){
        array[i] = other.array[i];
    }
}
void IntContainer::destroy() {
    delete [] array;
    array = nullptr;
    _size = 0;
    capacity = 0;
}
void IntContainer::resize() {
    capacity *= 2;
    int* new_array = new int[capacity];
    for(int i=0;i< _size; i++){
        new_array[i] = array[i];
    }
    delete [] array;
    array = new_array;
}
IntContainer::IntContainer(): IntContainer(4){}
IntContainer::IntContainer(const size_t& _capacity): capacity{_capacity}, _size{0}, array{new int[_capacity]} {}
IntContainer::~IntContainer() {
    destroy();
}
IntContainer& IntContainer::operator=(const IntContainer& other){
    if(this != &other){
        destroy();
        copy(other);
    }
    return *this;
}
size_t IntContainer::size() const {
    return _size;
}
int& IntContainer::operator[](const size_t& pos) {
    return array[pos];
}
const int& IntContainer::operator[](const size_t& pos) const{
    return array[pos];
}

void IntContainer::push_back(const int& element) {
    if(capacity - _size == 1) {
        resize();
    }
    array[_size++] = element; 
}

void IntContainer::pop_back() {
    if(_size != 0) {
        _size--;
    }
}