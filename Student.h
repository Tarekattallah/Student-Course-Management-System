#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <vector>
#include <string>

class Student : public Person {
private:
    int id;
    double gpa;
    std::vector<std::string> courses;

public:
    Student(int i, std::string n, double g);

    int getId() const;
    double getGpa() const;
    void setGpa(double g);
    std::vector<std::string> getCourses() const;

    void enrollCourse(std::string course);
    void displayCourses() const;
};

#endif