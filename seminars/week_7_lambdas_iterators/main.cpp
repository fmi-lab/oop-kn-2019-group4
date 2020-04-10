#include<iostream>
#include "IntContainer.h"

void addOne(int& elem) {
    elem += 1;
}
int main() {
    IntContainer test_container{1,2,3,4};
    // test_container.push_back(1);
    // test_container.push_back(2);
    // int counter=0;
    // std::cout << counter;
    // std::cout << std::endl;
    // test_container.map([&counter](int& elem)->void {
    //     elem +=1;
    //     counter+=1;
    // });

    // std::cout << test_container;
    // std::cout << std::endl;
    // std::cout << counter;
    for(auto elem : test_container) {
        std::cout << elem;
    }
    for(IntContainer::MyIterator i = test_container.begin(); i != test_container.end(); i++){
        
    }
}