#ifndef PERSON_H
#define PERSON_H

class Person
{
    char *phone;
    char *address;

protected:
    char *name;

    void copy(const char *name, const char *phone, const char *address);

public:
    Person();
    Person(const char *name, const char *phone, const char *address);
    Person(Person const &otherPerson);
    Person &operator=(Person const &otherPerson);
    ~Person();

    char *getName() const { return this->name; }
    char *getPhone() const { return this->phone; }
    char *getAddress() const { return this->address; }
};

#endif /* ifndef PERSON_H */