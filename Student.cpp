#include "Student.h"
#include <iostream>
#include <algorithm>

using namespace std;

Person::Person() {}

Person::Person(string n) : name(n) {}

string Person::getName() const {
    return name;
}

void Person::setName(string n) {
    name = n;
}

Student::Student(int i, string n, double g) : Person(n), id(i), gpa(g) {}

int Student::getId() const {
    return id;
}

double Student::getGpa() const {
    return gpa;
}

void Student::setGpa(double g) {
    if (g >= 0.0 && g <= 4.0) {
        gpa = g;
    }
    else {
        cout << "Error: GPA must be between 0.0 and 4.0\n";
    }
}

vector<string> Student::getCourses() const {
    return courses;
}

void Student::enrollCourse(string course) {
    for (size_t i = 0; i < courses.size(); i++) {
        if (courses[i] == course) {
            cout << "This course is already enrolled!\n";
            return;
        }
    }
    courses.push_back(course);
    cout << "Enrolled in course: " << course << endl;
}

void Student::displayCourses() const {
    if (courses.empty()) {
        cout << "Student is not enrolled in any courses\n";
        return;
    }
    cout << "Courses of student " << name << ":\n";
    for (size_t i = 0; i < courses.size(); i++) {
        cout << " - " << courses[i] << endl;
    }
}