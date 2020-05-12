#include "User.h"
#include <cstring>
#include <ostream>
#include <sched.h>

User::User(const char * _type) : firstName(nullptr), lastName(nullptr), password(nullptr) {
    this->type = new char [ strlen(_type) + 1 ];  
    strcpy(this->type, _type);
}

void User::copy(const char * _firstName, const char * _lastName, const char * _password, const char * _type) {
    this->firstName = new char [ strlen(_firstName) + 1 ]; //+1 for terminating zero
    this->lastName  = new char [ strlen(_lastName) + 1 ];
    this->password  = new char [ strlen(_password) + 1 ];

    strcpy(this->firstName, _firstName);
    strcpy(this->lastName, _lastName);
    strcpy(this->password, _password);

    if(_type) {
        this->type = new char [ strlen(_type) + 1];
        strcpy(this->type, _type);
    } else {
        this->type = nullptr;
    }
}

User::User(const char * _firstName, const char * _lastName, const char * _password, const char * _type) {
    this->copy(_firstName, _lastName, _password, _type);  
}

User::User(const User& other) {
    this->copy(other.firstName, other.lastName, other.password, other.type);  
}

User& User::operator=(const User& other) {
    if ( this != &other) {
        this->destroy();      
        this->copy(other.firstName, other.lastName, other.password, other.type);  
    }

    return *this;
}

void User::print(std::ostream& out) const {
    out << "First name: " << this->firstName << " Last name: " << this->lastName;
}

void User::destroy() {
    if(this->firstName) {
        delete[] this->firstName;
        this->firstName = nullptr;
    }

    if(this->lastName) {
        delete[] this->lastName;
        this->lastName = nullptr;
    }

    if(this->password) {
        delete[] this->password;
        this->password = nullptr;
    }

    if(this->type) {
        delete[] this->type;
        this->type = nullptr;
    }
}

void User::serialize(std::ostream& out) const {
    out << strlen(this->firstName) << " " << strlen(this->lastName) << " " << strlen(this->password) << " " 
       << this->firstName << " " << this->lastName << " " << this->password << " "; 
}

void User::deserialize(std::istream& inp)  {
    int size;
    
    //Destroys object data so it can be replaced
    this->destroy();

    inp >> size; //firstName size
    this->firstName = new char [ size + 1 ]; //size + 1 for terminating zero
    inp >> size; //lastName size
    this->lastName = new char [ size + 1 ];
    inp >> size;;
    this->password = new char [ size + 1 ];

    inp >> this->firstName
        >> this->lastName
        >> this->password;
}

void User::create(const char * _type) {
    char firstName[100];
    char lastName[100];

    std::cout << "Enter person's firstName, lastName:" << std::endl;  
    std::cin.getline(firstName, 100);
    std::cin.getline(lastName, 100);
  
    this->firstName = new char[strlen(firstName) + 1]; 
    this->lastName = new char[strlen(lastName) + 1]; 
  
    strcpy(this->firstName, firstName);
    strcpy(this->lastName, lastName); 
    
    char pass[100];
    std::cout << "Enter the user's password: " << std::endl;
    std::cin.getline(pass, 100);
    
    this->password = new char [strlen(pass) + 1];
    strcpy(this->password, pass);

    this->type = new char [ strlen(_type) + 1 ];
    strcpy(this->type, _type);

 //   std::cin.get();
}

std::ostream& operator<<(std::ostream& out, const User& user) {
    user.print(out);
    return out;
}

