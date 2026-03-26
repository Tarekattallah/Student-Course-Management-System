#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string name;

public:
    Person();
    Person(std::string n);
    std::string getName() const;
    void setName(std::string n);
};

#endif