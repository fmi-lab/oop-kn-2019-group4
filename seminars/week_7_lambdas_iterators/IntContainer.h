#ifndef _INTCONTAINER_HH
#define _INTCONTAINER_HH
#include <functional>
using mapper = std::function<void(int&)>;



class IntContainer {
    int* array;
    size_t _size;
    size_t _capacity;
    void copy(const IntContainer& other);
    void destroy();
    void resize();
    void swap(IntContainer&);
    public:
    class MyIterator {
        int* elem;
        public:
        MyIterator(int* pointer): elem{pointer} {}
        bool operator ==(const MyIterator& other){
            return elem == other.elem;
        }
        bool operator !=(const MyIterator& other){
            return elem != other.elem;
        }
        int operator *(){
            return *elem;
        }
        void operator ++(){
            elem++;
        }
        ~MyIterator(){
            delete elem;
        }
    };
    IntContainer();
    IntContainer(const size_t&);
    IntContainer(const IntContainer&);
    IntContainer(const std::initializer_list<int>&);
    ~IntContainer();
    IntContainer& operator=(const IntContainer&);
    IntContainer(IntContainer&&);
    IntContainer& operator=(IntContainer&&);
    size_t size() const;
    size_t capacity() const;
    int& operator[](const size_t&);
    const int& operator[](const size_t&) const;
    void push_back(const int&);
    void pop_back();
    explicit operator bool() const;
    void map(mapper);
    IntContainer::MyIterator begin() const;
    IntContainer::MyIterator end() const;
    friend std::ostream& operator << (std::ostream& out, const IntContainer& c);
};
#endif