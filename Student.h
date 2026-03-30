#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_
#include "Person.h"
#include <set>
#include <string>
using namespace std;

class Student : public Person
{
private:
    int m_id;
    double m_GPA;
    set<string> courses;

public:
    Student();
    Student(int id, double gpa, string name, string email = "");

    void SetId(int id);
    void SetGPA(double gpa);
    void EnrollCourse(string course);

    int  GetId() const;
    double GetGPA() const;
    set<string> GetCourse() const;

    void display() const override;
};

#endif