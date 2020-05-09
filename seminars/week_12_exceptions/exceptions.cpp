#include<iostream>
#include<cassert>
#include<exception>
// std::exception;
// std::bad_alloc;
// std::logic_error;
struct my_exception: public std::exception {
    int a;
    int b;
    my_exception(int _a, int _b):a{_a}, b{_b}{}
    const char* what() const noexcept override { //throw()
        return "MyException::Division by zero\n";
    }
    int getA() noexcept{
        return a;
    }
    int getB() noexcept{
        return b;
    }
};

int func(int a, int b) {
    if (b != 0) {
        return a / b;
    }
    throw my_exception{a,b};
    std::cout << "Reached!\n"; 
}

int use_func(int a, int b) {
    try{
        return func(a,b);
    }catch(...) {
        throw "Division by zero";
    }
}

void allocate_mem(char*& dest, int size) {
    dest = new char[size];
}

int main() {
    char* t;
    std::cout << std::boolalpha << noexcept(func(2,3));
    try {
        allocate_mem(t,-1);
        std::cout << func(6,2) << std::endl;
        std::cout << func(0,6) << std::endl;
        // std::cout << func(6,0) << std::endl;
        std::cout << use_func(6,0) << std::endl;
    }
    catch(const char* e) {
        std::cout << e << std::endl;
    }
    catch(int e) {
        std::cout << e;
    }
    catch(int e) {
        std::cout << "Me\n";
    }
    catch(std::runtime_error e) {
        std::cout << e.what();
    }
    // catch(my_exception e) {
    //     std::cout << e.what();
    //     std::cout << "Args:" << e.getA() << " " << e.getB() << std::endl;
    // }
    catch(std::bad_alloc e) {
        std::cout << e.what();
    }
    catch(...) {
        throw "Unkown error";
    }
    std::cout << "reached";
    return 0;
}