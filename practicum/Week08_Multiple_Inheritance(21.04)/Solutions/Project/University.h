#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Subject.h"
#include <vector>

class University {

    std::vector<User*> users;
    Subject * subjects;
    char * name;

    int subjectsSize;
    int subjectCapacity;

    void copy (std::vector<User *> _users, Subject const * _subjects,
               int _subjectsSize, char const * _name);
    void destroy();
    
    int findSubjectIndexByName(char const * name) const;
    int findUserIndexByName(char const * name) const;

public:

    University () : subjects(nullptr), name(nullptr), subjectsSize(0), subjectCapacity(0) {};
    University (std::vector<User *>, Subject const * _subjects,
                int _subjectsSize, char const * _name);
    University (University const&  other);
    University& operator=(University const& other);
    ~University ();
    
    const User * getUserById(size_t id) const;
    const User * getUserByName(const char * name) const;
    int getUserSize() const { return this->users.size(); }
    
    //Someone might ask why 3 functions? The whole idea is for them to work with different
    //types of data. So lets say I am in the login session and I have the user. Why should 
    //I search for him again so he can be added? The main logic is in addUserToSubject
    //The rest of them are just different cases if we have to search.
    bool addUserToSubject(const char * studentName, const char * SubjectName);
    bool addUserToSubject(User * usr, const char * subjectName);
    bool addUserToSubject(User * user, Subject& subj);

    void listStudentsInCourse(int course) const;
    void addUser(User const& user);
    
    friend class LoginSession;
};

#endif /* UNIVERSITY_H */
