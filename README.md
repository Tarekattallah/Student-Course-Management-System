Student Course Management System
A simple console-based C++ application to manage students and their courses using OOP concepts.
Features

Add a new student (with unique ID and GPA validation)
Remove a student by ID
Search for a student by ID
Display all students
Enroll a student in a course (no duplicate courses)
Show courses of a specific student
Sort students by GPA (descending order)
Save data to file
Load data from file
Exit the program

Technologies Used

C++
Object-Oriented Programming (Inheritance)
STL Containers (map, set, vector)
STL Algorithms (sort)
File I/O (fstream)

Project Structure
Student-Course-Management-System/
├── Person.h
├── Person.cpp
├── Student.h
├── Student.cpp
├── CourseManager.h
├── CourseManager.cpp
├── Menu.h
├── Menu.cpp
├── StudentCourseManagementSystem.cpp
└── README.md

Person.h / Person.cpp           → Base class (contains name & email)
Student.h / Student.cpp         → Derived class (inherits from Person, adds ID, GPA, courses)
CourseManager.h / CourseManager.cpp → Core logic: CRUD operations + file I/O
Menu.h / Menu.cpp               → Console menu and input handling
StudentCourseManagementSystem.cpp → Main entry point
database.txt                    → Auto-generated persistent storage file

How to Compile and Run

Open the project folder in Visual Studio.
Make sure all source files are added to the project.
Build the solution (Ctrl + Shift + B).
Run the program (Ctrl + F5).

Requirements

Visual Studio 2019 or 2022
C++ language standard (C++17 or later recommended)

Notes

Each student must have a unique ID.
GPA must be between 0.0 and 4.0.
A student cannot enroll in the same course twice.
Data is saved automatically when adding or removing students.
Use options 8 and 9 to manually save/load from database.txt.


Developed by: Altarek Mohamed Alsaied Twfiek
Contact: +201061258009
Date: March 2026
