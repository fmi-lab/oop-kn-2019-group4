#include<iostream>
#include<algorithm>
#include<cassert>
// Template function that evaluates the sum of two arguments
// Note that both arguments are of the same type but the result can be a different one
// We can have default template value and it can be existing typename or the value of template
// parameter that is already determined
template<class T=int, class R=T>
R sum(const T& a, const T& b){
    return a + b;
}

// Template function display that takes one argument and outputs its data by calling
// respective method. Note that we are restricting the range of available type candidates
// to the ones that have #print implemented
template<class T>
void display(const T& element) {
    element.print();
}

template<class T>
T min(const T& first_arg, const T& second_arg){
    // std::less is a struct so we should create an object and then call its operator
    std::less<T> compare;
    return compare(first_arg, second_arg) ? first_arg : second_arg;
}

// We can have template structs/classes and the same rules apply
template<class U, class V>
struct Pair{
    // Pair() {
    //     first = a;
    //     second = b;
    // }
    // Pair(int a, int b);
    // Pair(int a, double b);
    // Pair(std::initializer_list<int>&);
    U first;
    V second;
};

// Note that the default value is optional
// but the function cannot be initialized unless both parametes have values
template<class T, int S=10>
void useStaticArray(){
    T arr[S];
}

void sumTest() {
    int first_test_arg = sum(2,3);
    std::cout << first_test_arg << '\n';
    assert(first_test_arg == 5);
    int second_test_arg = sum<double, int>(3.25, 2.35);
    std::cout << second_test_arg << '\n';
    assert(second_test_arg != 5.70);
    assert(second_test_arg == 5);
}

void minTest() {
    int first_result = min(2,3);
    std::cout << first_result << '\n';
    assert(first_result == 2);
}

void pairTest() {
    Pair<int, double> test_pair {2, 3.25};
    std::cout << test_pair.first << " " << test_pair.second << '\n';
    assert(test_pair.first == 2 && test_pair.second == 3.25);
    // We can have more complex pair and it works just fine
    Pair< Pair<int, int>, Pair<double, double> > complex_pair {{1,2}, {3.25, 2.55}};
    assert(complex_pair.first.first == 1 && complex_pair.second.second == 2.55);
}
int main() {
    sumTest();
    minTest();
    pairTest();

    // main from seminars:
    // int var;
    // Pair<int,int> p5;
    // f(1,2.35, "cha", p5);
    // double_func functions[10];
    // functions[0] = test;
    // var = 10;
    // int other_var{10};
    // printArr<int, 2>();
    // // Pair p1;
    // // p1.first = 1;
    // // p1.second = 2;
    // Pair p1{2,10};
    // // Pair arr[] = {{1,2}, Pair(2,1)};
    // // Pair p(Pair());
    // // Pair p3(2,10);
    // std::cout << p1.first;
    // Pair p2(p1);
    // Pair p4;

    // sum(2,3);
    // sum<Pair<int>, int>(p1,p2);
}
