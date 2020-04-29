#include<iostream>
#include<vector>
#include "LList.cpp"

template<class T>
using mapper = void(*)(T&);

template<class T>
class Container {
    public:
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
    virtual size_t capacity() const = 0;
    // virtual void pop_back() = 0;
    // virtual void push_back(const T&) = 0;
    // virtual T& operator[](const size_t&) = 0;
    // virtual void map(mapper) = 0;
    virtual ~Container() {
        std::cout << "~Container\n";
    };
    virtual Container<T>* clone() = 0;
};

template<class T>
class ArrayContainer: public Container<T> {
    T* array;
    size_t _size;
    size_t _capacity;
    void resize() {
        _capacity *= 2;
        T* new_array = new T[_capacity];
        for(int i=0; i< _size; i++){
            new_array[i] = array[i];
        }
        delete [] array;
        array = new_array;
    }
    public:
    ArrayContainer(): ArrayContainer(4){}
    ArrayContainer(const size_t& new_capacity): _capacity{new_capacity}, _size{0}, array{new int[new_capacity]} {}
    bool empty() const override{
        return _size == 0; 
    }
    size_t size() const override{
        return _size;
    }
    size_t capacity() const override {
        return _capacity;
    }
    ArrayContainer* clone() override {
        std::cout << "ArrayContainer_clone\n";
        return new ArrayContainer<T>(*this);
    }
    // void pop_back() override {
    //     if(_size == 0) {
    //         return;
    //     }
    //     _size--;
    // }
    // ~ArrayContainer() {
    //     std::cout << "~ArrayContainer\n";
    //     delete array;
    // }
    // T& operator[](const size_t& pos) override {
    //     return array[pos];
    // }
    // void push_back(const T& elem) override {
    //     if(_capacity - _size == 1) {
    //         resize();
    //     }
    //     array[_size++] = elem;
    // }
    // void map(mapper m) {
    //     for(int i=0; i< _size; i++){
    //         m(array[i]);
    //     }
    // }
};
template<class T>
class ListContainer:public Container<T> {
    LList<T> list;
    public:
    bool empty() const override{
        return true; 
    }
    size_t size() const override{
        return 0;
    }
    size_t capacity() const override {
        return 0;
    }
    ListContainer* clone() override {
        std::cout << "ListContainer_clone\n";
        return new ListContainer<T>(*this);
    }
    // void pop_back() override {
    //     if(_size == 0) {
    //         return;
    //     }
    //     _size--;
    // }
    // ~ListContainer() {
    //     std::cout << "~ArrayContainer\n";
    //     delete array;
    // }
    // T& operator[](const size_t& pos) override {
    //     return array[pos];
    // }
    // void push_back(const T& elem) override {
    //     if(_capacity - _size == 1) {
    //         resize();
    //     }
    //     array[_size++] = elem;
    // }
    // void map(mapper m) {
    //     for(int i=0; i< _size; i++){
    //         m(array[i]);
    //     }
    // }
};

int main() {
    // IntContainer c;
    Container<int>* pointer = new ArrayContainer<int>;
    // pointer->push_back(1);
    std::vector<Container<int>* > v;
    v.push_back(new ArrayContainer<int>);
    v.push_back(new ListContainer<int>);
    std::vector<Container<int>* > v1;
    for(auto elem : v) {
        // Container<int>* temp_pointer;
        // elem->clone(temp_pointer);
        v1.push_back(elem->clone());
    }
    
    // Container<int>* pointer2 = pointer->clone();
    // pointer->clone(pointer2);
    
    std::cout << pointer->empty();
    delete pointer;
    return 0;
}