#ifndef USER_H
#define USER_H 

#include <ostream>
#include <iostream>

class User {
    char * firstName;
    char * lastName;
    char * password;
    char * type;

    void destroy();
    void copy(const char * _firstName, const char * _lastName, const char * _password, const char * _type);

protected:
    virtual void print(std::ostream& out = std::cout) const;

public:
    User() : firstName(nullptr), lastName(nullptr), password(nullptr) {};
    User(const char * _type);
    User(const char * _firstName, const char * _lastName, const char * _password, const char * _type = nullptr);
    User(const User& other);
    User& operator=(const User& other);
    virtual ~User() { this->destroy(); }
    
    virtual void serialize(std::ostream& out) const;
    virtual void deserialize(std::istream& inp);
    virtual void create(const char * _type);
    virtual User * clone() const  { return new User(*this); };
    virtual int getCourse() const { return -1; };

    char const * getFName() const { return this->firstName; } 
    char const * getName() const { return this->firstName; }
    char const * getLName() const { return this->lastName; }
    char const * getPassword() const { return this->password; }
    char const * getType() const { return this->type; }

    friend std::ostream& operator<<(std::ostream& out, const User&  user);
};

std::ostream& operator<<(std::ostream& out, const User& user);

#endif /* ifndef USER */
