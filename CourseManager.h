#pragma once
#ifndef COURSEMANAGER_H_
#define COURSEMANAGER_H_
#include "Student.h"
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CourseManager
{
private:
    map<int, Student> students;

public:
    void AddStudent(Student s);
    bool RemoveStudent(int id);
    Student* searchStudent(int id);

    void displayAll() const;
    void sortByGPA();
    bool enrollInCourse(int id, string course);
    void showCourses(int id);

    void  saveToFile(string filename);    
    void  loadFromFile(string filename);
    void appendStudentToFile(string filename, Student& stud);
};

#endif