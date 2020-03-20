#include<iostream>
#include "IntContainer/IntContainer.h"

void f() {
    struct Test{

    };
}

int main() {
    IntContainer test;
    for(int i=0;i < 10; i++){
        test.push_back(i+1);
    }
    std::cout << test.size() << std::endl;

    for(int i=0; i < test.size(); i++){
        std::cout << test[i];
    }
    return 0;
}
