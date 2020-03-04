#include<iostream>
#include<fstream>
using std::cout, std::cin, std::endl;
using std::ifstream, std::ofstream, std::ios;

namespace bin_manip { 
    template<class T>
    bool read_element(ifstream& input, T& element){
        if(input.read((char*)& element, sizeof(T))) {
            return true;
        }
        return false;
    }

    template<class T, class ArrayWrapper=std::pair<T*, size_t> >
    bool seedTestData(const char* filename, const ArrayWrapper seedData){
        if (!seedData.first) {
            return false;
        }
        ofstream output(filename, ios::binary);
        for(int i=0; i < seedData.second; i++){
            if( !output.write((const char*)& seedData.first[i], sizeof(T))){
                output.close();
                return false;
            }
        }
        output.close();
        return true;
    }
}

struct Student{
    int faculty_number;
    double avg_grades;
};

void binaryFileDemoTests(const char* filename){
    std::pair<Student*, size_t> seedData;
    seedData.second = 3;
    seedData.first = new Student[seedData.second]{{81131, 5.5}, {81246, 4.5}, {82033, 4}};
    bin_manip::seedTestData<Student>(filename, seedData);
    std::ifstream input_stream(filename, ios::binary);
    Student temp_element;
    while(bin_manip::read_element(input_stream, temp_element)) {
        auto& [faculty_number, grades] = temp_element;
        faculty_number += 1000;
        cout << temp_element.faculty_number << " " << grades << endl;
    }
}
int main() {
    binaryFileDemoTests("InputFile.bin");
    return 0;
}