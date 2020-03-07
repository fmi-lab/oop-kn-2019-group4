#include<iostream>
// In order to work with filestreams we should include the following library
#include<fstream>
// Instead of specifying the namespace of the following objects and types we can explicitly state that we are using them from specific one.
// In our case we are using std
using std::cout, std::cin, std::endl;
using std::ifstream, std::ofstream, std::ios;

// We will wrap our functions into separate namespace so that there isn't any risk of conflicting function declarations and to be more clear where
// these functions come
namespace bin_manip { 
    // A function that reads single element and saves it in the second parameter. It's a template one since we can read any type of objects.
    template<class T>
    bool read_element(ifstream& input, T& element){
        // input is a stream object. If the following operation fails, the stream will be in bad state.
        // One way to check this status is to treat the stream as it is some boolean type.
        // If the read operation fails, nothing will be read. If so we won't execute if's body and we will return false as the operation is unsuccessfull
        if(input.read((char*)& element, sizeof(T))) {
            return true;
        }
        return false;
    }

    // In order to test bin_manip::read_element we want to seed some data in the file before we try to read something form it.
    // This is again template since we can seed whatever we want. Second template parameter is for the collection that will hold the seed data.
    // If nothing is provided we will expect the type to be std::pair with first parameter that holds the data as an array and second paramter that holds the size of the array.
    // Note that inside the function body we expect the ArrayWrapper object to have member data called first and second and also they should not be encapsulated (they can be used outside type definition/they are public)
    template<class T, class ArrayWrapper=std::pair<T*, size_t> >
    bool seedTestData(const char* filename, const ArrayWrapper seedData){
        if (!seedData.first) {
            return false;
        }
        ofstream output(filename, ios::binary);
        for(int i=0; i < seedData.second; i++){
            // Same as with the #read method in the previous function
            if( !output.write((const char*)& seedData.first[i], sizeof(T))){
                output.close();
                return false;
            }
        }
        // After we are finished with the file we should close it if we won't use it further where we have opened it.
        output.close();
        return true;
    }
}

struct Student{
    int faculty_number;
    double avg_grades;
    void print() {
        cout << faculty_number << avg_grades;
    }
};

void binaryFileDemoTests(const char* filename){
    std::pair<Student*, size_t> seedData;
    seedData.second = 3;
    seedData.first = new Student[seedData.second]{{81131, 5.5}, {81246, 4.5}, {82033, 4}};
    bin_manip::seedTestData<Student>(filename, seedData);
    std::ifstream input_stream(filename, ios::binary);
    Student temp_element;
    // read_element returns true/false depending on if the read operation was successfull or not. We are using in the while loop to read as much data as we can.
    // Note that we use temp_element as a storage for the data that we are reading from the file. If read_element can't read any more and the input stream has failed for some reason
    // temp_element will contain the last successfully read data from the file. When the loop is over it will have the last read element.
    while(bin_manip::read_element(input_stream, temp_element)) {
        // The good old way to use struct's data is this:
        // temp_element.first <- calling member data
        // We can destructure agregates by using the following syntax:
        auto [faculty_number, grades] = temp_element; //This is called Structured binding declaration and it is available in c++17
        
        // By using the auto statement we make the compiler to determine the type of a variable at compile time.
        // auto a = 10; <- a will be deduced to int
        // Note that is we want the type to be some type of reference we should state that
        // int a = 10;
        // auto& b = a; <- b will be of type int&
        // auto c = a; <- c will be of type int

        // So if we don't want to copy the data and use it by reference we can do the following:
        // auto& [faculty_number, grades] = temp_element;
        // If we use them by reference and modify one of the destructured elements, we will modify the object itself.
        // faculty_number += 1000;
        // cout << temp_element.faculty_number << " " << grades << endl; <- faculty_number will be increased by 1000
        cout << faculty_number << " " << grades << endl;
        // same as -> cout << temp_element.faculty_number << " " << temp_element.grades << endl;
        // Note that this works only for agregate types
    }
}
int main() {
    binaryFileDemoTests("InputFile.bin");
    return 0;
}