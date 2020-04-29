#include<iostream>

class A {
    virtual void p()=0;
    public:
    void doP(){
        p();
    }
};

class B: public A{
    void p() {
        std::cout << "B::p()\n";
    }
};

struct Node {
    int elem;
    Node* next;
};

void reverse(Node*& start) {
    Node* prev = nullptr;
    Node* curr = start;
    Node* next = nullptr;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start = prev;
}

int main() {
    return 0;
}