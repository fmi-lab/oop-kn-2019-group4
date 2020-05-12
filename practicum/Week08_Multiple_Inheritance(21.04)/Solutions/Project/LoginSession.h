#ifndef LOGIN_SESSION_H
#include "User.h"
#include "University.h"
#include <string>
#include <vector>

class LoginSession {
    User* user; 
    University uni;

    void copy(const University& _uni, const User * _usr);
    void destroy();
public:
    bool login(std::string userName, std::string pass);
    void listStudentsInCourse(int course); 
    void enrollInCourse(const char * courseName);
    void registerUser();

    LoginSession() : user(nullptr) {};
    LoginSession(const LoginSession& other);
    LoginSession& operator=(const LoginSession& other);
    LoginSession(const University& _uni, const User* usr = nullptr);   
    ~LoginSession();
};

#define LOGIN_SESSION_H
#endif /* ifndef LOGIN_SESSION_H */
