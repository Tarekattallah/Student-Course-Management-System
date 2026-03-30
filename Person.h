#pragma once
#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string m_name;
    string m_email;

public:
    Person();
    Person(string name, string email);

    void SetName(string name);
    void SetEmail(string email);

    string GetName() const;
    string GetEmail() const;

    virtual void display() const;
};

#endif