# Student Course Management System

A simple console-based C++ application to manage students and their courses using OOP concepts.

## Features
- Add a new student (with unique ID and GPA validation)
- Remove a student by ID
- Search for a student by ID
- Display all students
- Enroll a student in a course (no duplicate courses)
- Show courses of a specific student
- Sort students by GPA (descending order)
- Exit the program

## Technologies Used
- C++ 
- Object-Oriented Programming (Inheritance)
- STL Containers (`vector`)
- STL Algorithms (`sort`)

## Project Structure
Student-Course-Management-System/
├── Person.h
├── Student.h
├── Student.cpp
├── StudentCourseManagement.cpp
└── README.md
text- `Person.h`      → Base class (contains name)
- `Student.h`     → Derived class (inherits from Person)
- `Student.cpp`   → Implementation of Student class
- `StudentCourseManagement.cpp` → Main program with menu

## How to Compile and Run

1. Open the project folder in **Visual Studio**.
2. Make sure all 4 source files are added to the project.
3. Build the solution (`Ctrl + Shift + B`).
4. Run the program (`Ctrl + F5`).

## Requirements
- Visual Studio 2019 or 2022
- C++ language standard (default is fine)

## Notes
- Each student must have a unique ID.
- GPA must be between 0.0 and 4.0.
- A student cannot enroll in the same course twice.

---

**Developed by:** [Altarek Mohamed Alsaied Twfiek]  
**Student ID:** [+201061258009]  
**Date:** March 2026
