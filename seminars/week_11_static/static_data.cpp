#include<iostream>
#include<string>
#include<vector>
#include<cassert>
#include<cstring>

// ID := a->a
// Sum := a,b -> a + b
// Max := a,b -> std::max(a,b) 
template<class T>
class Formula {
    public:
    virtual const T value() const = 0;
    virtual ~Formula() = default;
};

template<class T>
class ID: public Formula<T> {
    T* a;
    public:
    ID():a{nullptr}{};
    ID(const T& elem): a{new T(elem)} {}

    const T value() const override {
        assert(a);
        return *a;
    }

    ~ID() = default;
};

template<class T>
class Sum: public Formula<T> {
    Formula<T>* first;
    Formula<T>* second;
    static T result;
    public:
    Sum():first{nullptr}, second{nullptr} {};
    Sum(Formula<T>* left, Formula<T>* right): first{left}, second{right} {
        result = first->value() + second->value();
    }

    const T value() const override {
        // assert(first && second);
        // return first->value() + second->value();
        return result;
    }

    ~Sum() {
        delete first;
        delete second;
    }
};
template<class T>
class FormulaFactory {
    public:
    static Formula<T>* make(const char* type) {
        if(strcmp(type, "id") == 0) {
            return new ID<T>;
        }
        if(strcmp(type, "sum") == 0) {
            return new Sum<T>;
        }
    }
};

struct Foo{
    static const int counter = 0;
};

template<class T>
T Sum<T>::result = 0;

class myString {
    std::string s;
    public:
    friend std::istream& operator >> (std::istream&, myString&);
    const char* content() const {
        return s.c_str();
    }
};

std::istream& operator >> (std::istream& in, myString& object) {
    char symbol;
    while(in.get(symbol) && symbol != '\n') {
        in.rdbuf();
        object.s.push_back(symbol);
    }
    return in;
}
// (1+2) + (3 + 5) <=> Sum(Sum(Id(1),Id(2)), Sum(Id(3),Id(5)))
int main() {
    ID<int> a(1);
    // std::cout << a.value() << std::endl;
    // Sum<int> b(new Sum<int>(new ID<int>(1),new ID<int>(2)), new Sum<int>(new ID<int>(3), new ID<int>(5)));
    // std::cout << b.value() << std::endl;
    // std::vector<Formula<int>*> v;
    // Formula<int>* f_p = FormulaFactory<int>::make("sum");
    // Sum<int> s1(new ID<int>(1),new ID<int>(2));
    // Sum<int> s2(new ID<int>(3),new ID<int>(4));
    // std::cout << s1.value() << std::endl;
    // std::cout << s2.value() << std::endl;
    // std::cout << Foo::counter;
    myString test_string;
    std::cin >> test_string;
    std::cout << test_string.content();
    std::string s;
    std::cin >> s;
    return 0;
}