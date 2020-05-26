template <class T>
class SmartPointer
{
    T *ptr; // Actual pointer

public:
    explicit SmartPointer(T *p = nullptr) { ptr = p; }

    // Destructor
    ~SmartPointer() { delete (ptr); }

    // Overloading dereferncing operator
    T &operator*() { return *ptr; }

    // Overloading arrow operator
    T *operator->() { return ptr; }
};