#include<iostream>
#include<cassert>

struct Rat{
    int a;
    int b;
    Rat add(Rat);
};
template<class T>
T sum(T& first, T&second){
    return first + second;
}
class IntContainer{
    int array[100];
    size_t size = 1;
    public:
    friend std::ostream& operator <<(std::ostream&, const IntContainer&);
    friend IntContainer operator + (const IntContainer&, const IntContainer&);
    IntContainer operator + (const int& element) {
        IntContainer result(*this);
        if( size < 100){
            result.array[size] = element;
            size++;
        }
        return result;
    }
    IntContainer& operator += (const int& element) {
        if( size < 100){
            array[size] = element;
            size++;
        }
        return *this;
    }
    IntContainer operator + (const IntContainer& other) {
        assert(size + other.size < 100);
        IntContainer result(*this);
        for(int i=0; i< other.size; i++){
            result += other.array[i];
        }
        return result;
    }
    size_t getSize() const {
        return size;
    }
    explicit operator Rat() const {
        return {1,2};
    }
};

// IntContainer operator + (const IntContainer& first, const IntContainer& other) {
//         assert(size + other.size < 100);
//         IntContainer result(*first);
//         for(int i=0; i< other.size; i++){
//             result += other.array[i];
//         }
//         return result;
// }
std::ostream& operator <<(std::ostream& out, const IntContainer& element) {
    out << element.size;
    return out;
}
void f(IntContainer p) {

}
// + - * / % += -= *= = 
// a = a + b <=> a += b
// a = b = c = d
// && || ! == != > 
// << >>
// new delete
// -> *
// () []
// ++ --
// bool int char 
int main() {
    // int a;
    // int b;
    // Rat t;
    // int* ptr = nullptr;
    // if(ptr){

    // }
    // t.a;
    // t();
    IntContainer test_container;
    // int test_element = 10;
    // test_container += test_element; //test_container.operator+=(test_element);
    // std::cout << test_container << test_element; //operator << (operator << (cout, test_container),test_element)
    if(!test_container) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    std::cout << (bool) test_container;
    bool t(test_container);
    t = test_container;
    // [1,2,3] + [4,5,6] -> [1,2,3,4,5,6]
    

}