#include "University.h"
#include "Functions.h"

void University::copy (Student const * _students, Teacher const * _teachers, Subject const * _subjects,
        int _teacherSize, int _studentsSize, int _subjectsSize, char const * _name, bool _privilidged) {

    this->name = new char [strlen(_name) + 1];
    strcpy(this->name, _name);
    
    this->privilidged = _privilidged;

    this->students = nullptr; //needed for the copyArray
    this->teachers = nullptr;
    this->subjects = nullptr;
    
    //for simplicity I decided to use the size for capacity and if you resize one of the arrays then the capacity will come into effect
    this->studentCapacity = _studentsSize;
    this->subjectCapacity = _subjectsSize;
    this->teacherCapacity = _teacherSize;

    copyArray<Student>(this->students, _students, _studentsSize, this->studentsSize);
    copyArray<Teacher>(this->teachers, _teachers, _teacherSize, this->teacherSize);
    copyArray<Subject>(this->subjects, _subjects, _subjectsSize, this->subjectsSize);
}

University::University (Student const * _students, Teacher const * _teachers, Subject const * _subjects,
        int _studentsSize, int _subjectsSize, int _teacherSize, char const * _name, bool _privilidged) {
    this->copy(_students, _teachers, _subjects, _teacherSize, _studentsSize, _subjectsSize, _name, _privilidged);
}

University::University (University const&  other) {
    this->copy(other.students, other.teachers, other.subjects, other.teacherSize, 
            other.studentsSize, other.subjectsSize, other.name, other.privilidged);
}

University& University::operator=(University const& other) {
    if(this != &other) {
        this->destroy();
        this->copy(other.students, other.teachers, other.subjects, other.teacherSize,
                other.studentsSize, other.subjectsSize, other.name, other.privilidged);
    }
    
    return *this;
}

void University::destroy() {

    if(this->students != nullptr) {
        delete[] this->students;
    }

    if(this->teachers != nullptr) {
        delete[] this->teachers;
    }

    if(this->subjects != nullptr) {
        delete[] this->subjects;
    }

    if(this->name != nullptr) {
        delete[] this->name;
    }
}

University::~University() {
    this->destroy();
}

void University::addStudent(Student const& stud) {

    if(this->studentsSize >= this->studentCapacity) {
        Student * newArr = new Student [ 2 * this->studentCapacity ];
        this->studentCapacity *= 2; 

        for (int i = 0; i < this->studentsSize; ++i) {
            newArr[i] = this->students[i];
        }

        delete[] this->students;
        this->students = newArr;
    }
    
    this->students[this->studentsSize++] = stud;
}

Student University::getStudentById(int id) const {

    if(id < this->studentsSize) { 
        return this->students[id];
    }
    
    std::cout << "Invalid id" << std::endl;
    return Student(); //returns a blank object if id is invalid
}

int University::findSubjectIndexByName(char const * name) {
    return findArrElementByName<Subject>(name, this->subjects, this->subjectsSize);
}

int University::findTeacherIndexByName(char const * name) {
    return findArrElementByName<Teacher>(name, this->teachers, this->teacherSize);
}

int University::findStudentIndexByName(char const * name) {
    return findArrElementByName<Student>(name, students, studentsSize);
}

bool University::login(char const * userName, char const * pass)  {
    int studentIndex = this->findStudentIndexByName(userName);
    int teacherIndex = this->findTeacherIndexByName(userName);
    
    if(studentIndex != -1 && strcmp(this->students[studentIndex].getPassword(), pass) == 0) {
        std::cout << "You successfully logged in " << this->students[studentIndex].getFName() << std::endl; 
        return true;
    }

    if(teacherIndex != -1 && strcmp(this->teachers[teacherIndex].getPassword(), pass) == 0) {
        std::cout << "You successfully logged in " << this->teachers[teacherIndex].getFName() << std::endl; 
        this->privilidged = true;
        return true;
    }

    std::cout << "Bad credentials!" << std::endl;
    return false;
}

void University::listStudentsInCourse(int course) {

    if(!this->privilidged || course > 4) {
        std::cout << "You have no rights! Or maybe the course is wrong?" << std::endl;
        return;
    }

    int resultSize = 0;
    Student * filteredStudents = filter<Student>(this->students, this->studentsSize, 
            [course] (Student x) { return x.getCourse() == course; }, resultSize);
    
    for (int i = 0; i < resultSize; ++i) {
        filteredStudents[i].print(); 
    }

    delete[] filteredStudents;
}

bool University::addStudentToSubject(char const * studentName, char const * subjectName) {
    int studentIndex = this->findStudentIndexByName(studentName);
    int subjectIndex = this->findSubjectIndexByName(subjectName);

    if(studentIndex == -1 || subjectIndex == -1) {
        return false;
    }

    std::cout << studentIndex << " " << subjectIndex << " " << std::endl;
    this->subjects[subjectIndex].addStudent(this->students[studentIndex]);

    return true;
}
