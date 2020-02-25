#include<iostream>

struct Contact{
    int phone;
    char address[100];
    void print() {
        std::cout << phone << " " << address << '\n';
    }
};
class Student{
    public:
    void print() const{
        std::cout << "Print: " << fN << " " << avg_grades << '\n';
        // std::cout << c.phone << c.adress;
        c.print();
    }
    void setFN(const int& elem){
        fN = elem;
    }
    void setGrades(const double& elem) {
        avg_grades = elem;
    }
    int getFn() const{
        return fN;
    }
    private:
    int fN;
    double avg_grades;
    Contact c;
};

int main(){
    // const Student c_student;
    // c_student.getFn();
    Student s;
    s.setFN(81133);
    s.setGrades(4.22);
    std::cout << s.getFn();
    s.print();
    Student s1;
    s1.print();
}