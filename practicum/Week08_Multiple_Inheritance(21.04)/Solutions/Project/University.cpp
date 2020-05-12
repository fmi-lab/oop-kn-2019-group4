#include "University.h"
#include "Functions.h"
#include <iterator>
#include <vector>

void University::copy(std::vector<User *> _users, Subject const * _subjects,
                      int _subjectsSize, char const * _name) {

    this->name = new char [strlen(_name) + 1];
    strcpy(this->name, _name);
    this->subjects = nullptr;

    for (size_t i = 0; i < _users.size(); ++i) {
        this->users.push_back(_users[i]->clone());
    }

    //for simplicity I decided to use the size for capacity and if you resize one of the arrays then the capacity will come into effect
    this->subjectCapacity = _subjectsSize;
    copyArray<Subject>(this->subjects, _subjects, _subjectsSize, this->subjectsSize);
}

University::University (std::vector<User*> _users, Subject const * _subjects,
                        int _subjectsSize, char const * _name) {
    this->copy(_users, _subjects, _subjectsSize, _name);
}

University::University (University const&  other) {
    this->copy(other.users, other.subjects, other.subjectsSize, other.name);
}

University& University::operator=(University const& other) {
    if(this != &other) {
        this->destroy();
        this->copy(other.users, other.subjects, other.subjectsSize, other.name);
    }
    
    return *this;
}

void University::destroy() {

    for (size_t i = 0; i < this->users.size(); ++i) {
        if(this->users[i]) {
            delete this->users[i];
            this->users[i] = nullptr;
        }
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

void University::addUser(User const& usr) {
    User * usrCopy = usr.clone();
    this->users.push_back(usrCopy);
}

const User * University::getUserById(size_t id) const {

    if(id < this->users.size()) { 
        return this->users[id];
    }
    
    std::cout << "Invalid id" << std::endl;
    //Should use exception
    return new User(); //returns a blank object if id is invalid
}

int University::findSubjectIndexByName(char const * name) const {
    return findArrElementByName<Subject>(name, this->subjects, this->subjectsSize);
}

const User * University::getUserByName(char const * name) const {
    int index = this->findUserIndexByName(name);
    std::cout <<"User: " << name << std::endl;
    //Should use exceptions
    if(index != -1) {
        return this->users[index];
    }   

    std::cout << "Hello" << std::endl;
    return new User();
}

int University::findUserIndexByName(char const * name) const {
    for (size_t i = 0; i < this->users.size(); ++i) {
        if(strcmp(this->users[i]->getFName(), name) == 0) {
            return i;
        }
    }
    
    return -1;
}

void University::listStudentsInCourse(int course) const {
    //Filter returns the users that we need but the memory is not copied so there is no need to delete the filteredStudents
    //Because they are the same os the ones in users
    std::vector<User*> filteredStudents = filter<User*>(this->users, [course] (User * x) { return x->getCourse() == course; });
    
    for (size_t i = 0; i < filteredStudents.size(); ++i) {
        std::cout << *filteredStudents[i] << std::endl; 
    }
}

bool University::addUserToSubject(const char * studentName, const char * subjectName) {
    int userIndex = this->findUserIndexByName(studentName);
    int subjectIndex = this->findSubjectIndexByName(subjectName);

    if(userIndex == -1 || subjectIndex == -1) {
        return false;
    }
    
    return this->addUserToSubject(this->users[userIndex], this->subjects[subjectIndex]);
}

bool University::addUserToSubject(User * usr, const char * subjectName) {
    int subjectIndex = this->findSubjectIndexByName(subjectName);

    if(subjectIndex == -1) {
        std::cout << "Subject nonexistent" << std::endl;
        return false;
    }
    
    return this->addUserToSubject(usr, this->subjects[subjectIndex]);
}

bool University::addUserToSubject(User * user, Subject& subj) {
    //DO NOT USE THIS!!! This is done due to lack of time and converts parent to child essentially
    //The better approach is to have Users in the subjects class. This can be used to make a student point to a user aswell
    //This returns an object that can be checked for validity aswell hence the if after it 
    Student * stud = dynamic_cast<Student *>(user); 
    
    if(stud) {
        return subj.addStudent(*stud);
    }
    
    return false;
}
