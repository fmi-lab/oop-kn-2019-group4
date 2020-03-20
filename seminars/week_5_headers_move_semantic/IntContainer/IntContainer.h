#ifndef _INTCONTAINER_HH
#define _INTCONTAINER_HH

class IntContainer {

    int* array;
    size_t _size;
    size_t capacity;
    void copy(const IntContainer& other);
    void destroy();
    void resize();
    public:
    IntContainer();
    IntContainer(const size_t&);
    IntContainer(const IntContainer&);
    ~IntContainer();
    IntContainer& operator=(const IntContainer&);
    size_t size() const;
    int& operator[](const size_t&);
    const int& operator[](const size_t&) const;
    void push_back(const int&);
    void pop_back();
};
#endif