#include "LoginSession.h"

LoginSession& LoginSession::operator=(const LoginSession& other) {
    if(this != &other) {
        this->destroy();
        this->copy(other.uni, other.user);
    }

    return *this;
}

LoginSession::LoginSession(const LoginSession& other) {
    this->copy(other.uni, other.user);
}

LoginSession::LoginSession(const University& _uni, const User * _usr) {
    this->copy(_uni, _usr);
}

bool LoginSession::login(std::string userName, std::string pass)  {
    const User * _user = uni.getUserByName(userName.c_str());
    
    //Check if user firstname is different from nullptr. Shoul implement exceptions
    if(_user->getFName() && strcmp(_user->getPassword(), pass.c_str()) == 0) {
        std::cout << "You successfully logged in " << _user->getFName() << std::endl; 
        this->user = _user->clone();
        return true;
    }

    std::cout << "Bad credentials!" << std::endl;
    this->user = nullptr;
    return false;
}

void LoginSession::listStudentsInCourse(int course) {
    if(strcmp(this->user->getType(), "teacher") == 0) {
        this->uni.listStudentsInCourse(course);   
        return;
    }

    std::cout << "You do not have sufficient rights!!" << std::endl;
} 

void LoginSession::enrollInCourse(const char * courseName) {
    if(strcmp(this->user->getType(), "student") != 0) {
        std::cout << "You are not a student!!" << std::endl;
        return;
    }

    this->uni.addUserToSubject(this->user, courseName);

    std::cout << "Succesfully enrolled: " << this->user->getName() 
              << " to " << courseName << std::endl;
}

void LoginSession::copy(const University& _uni, const User * _usr) {
    if(_usr) {
        this->user = _usr->clone();
    } else {
        this->user = nullptr;
    }

    this->uni = _uni;
}

LoginSession::~LoginSession() {
    this->destroy();
}

void LoginSession::destroy() {
    if(this->user) {
        delete this->user;
        this->user = nullptr;
    }
}

void LoginSession::registerUser() {
    Student stud;
    stud.create();

    this->uni.addUser(stud);
}
