#include<iostream>
#include<cstring>

class ContactInformation{
    char phone_number[11];
    char address[100];
    public:
    void setPhone(const char* phone){
        if(strlen(phone) == 10) {
            strcpy(phone_number,phone);
        }
    }

    void setAddress(const char* new_address) {
        strcpy(address, new_address);
    }

    const char* getAddress() const{
        return address;
    }

    const char* getPhone() const{
        return phone_number;
    }

    void print() const{
        std::cout   << "Phone number: " << phone_number << '\n'
                    << "Address: " << address << '\n';
    }
};

class Student{
    public:
    void print() const{
        std::cout   << "Faculty number: " << faculty_number << '\n'
                    << "Grades: " << avg_grades << '\n';
        contact_data.print();
        // std::cout << c.phone << c.adress;
    }

    void setFn(const int& new_fn){
        if( new_fn >= 81000 && new_fn <= 89000) {
            faculty_number = new_fn;
        }
    }

    void setGrades(const double& grades) {
        if(grades >= 2 && grades <= 6) {
            avg_grades = grades;
        }
    }

    int getFn() const{
        return faculty_number;
    }

    double getGrades() const {
        return avg_grades;
    }

    void addContactData(const char* phone, const char* address) {
        contact_data.setPhone(phone);
        contact_data.setAddress(address);
    }

    private:
    int faculty_number;
    double avg_grades;
    ContactInformation contact_data;
};

void testStudentCreation(){
    Student test_student;
    test_student.setFn(81133);
    test_student.setGrades(5.55);
    test_student.addContactData("0886453525", "bul. 'Vitosha' 33");
    test_student.print();
}

int main() {
    // const Student c_student;
    // c_student.getFn();
    // Student s;
    // s.setFN(81133);
    // s.setGrades(4.22);
    // std::cout << s.getFn();
    // s.print();
    // Student s1;
    // s1.print();
    testStudentCreation();
    return 0;
}