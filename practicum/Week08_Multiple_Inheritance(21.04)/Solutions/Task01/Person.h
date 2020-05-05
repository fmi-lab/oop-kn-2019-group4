#ifndef PERSON_H
#define PERSON_H

class Person
{
    char *name;

protected:
    void copy(const char *name);

public:
    Person();
    Person(const char *name);
    Person(Person const &otherPerson);
    Person &operator=(Person const &otherPerson);
    ~Person();

    char *getName() const { return this->name; }
};

#endif /* ifndef PERSON_H */