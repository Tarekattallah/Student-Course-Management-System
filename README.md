Student Course Management System
Console-Based C++ Application
Developed by: Altarek Mohamed Alsaied Twfiek
March 2026


Overview
A fully functional console-based C++ application for managing students and their course enrolments. Built with OOP principles, it supports persistent file storage and a clean interactive menu interface.

Features
•	Add a new student with unique ID and GPA validation (0.0 – 4.0)
•	Remove a student by ID (syncs to file automatically)
•	Search for a student by ID
•	Display all registered students
•	Enroll a student in one or more courses (no duplicates)
•	View all courses for a specific student
•	Sort all students by GPA (descending)
•	Save all data to database.txt
•	Load data from database.txt into memory

Menu Options
The application presents the following interactive menu:

#	Option	Description
1	Add Student	Creates a new student record (unique ID + GPA validation)
2	Remove Student	Deletes a student by ID and updates database.txt
3	Search Student	Finds and displays a student by ID
4	Display All Students	Lists every registered student
5	Enroll Student in Course	Adds a course (no duplicates) to a student's record
6	Show Student Courses	Displays all courses for a given student
7	Sort Students by GPA	Displays students sorted highest GPA first
8	Save to File	Writes all records to database.txt
9	Load from File	Reads records from database.txt into memory
10	Exit	Exits the application

Architecture & Class Design
Class Hierarchy
The project uses inheritance to model the domain:

Person  (base class)
└── Student  (derived class)

Person (Base Class)
•	Fields: m_name, m_email
•	Virtual display() method — overridden in Student

Student (Derived from Person)
•	Additional fields: m_id (int), m_GPA (double), courses (set<string>)
•	set<string> prevents duplicate course enrolments automatically
•	Overrides display() with tabbed, formatted output

CourseManager
•	Maintains a map<int, Student> keyed by student ID
•	Provides all CRUD operations: add, remove, search, display, sort, enroll
•	File I/O: saveToFile(), loadFromFile(), appendStudentToFile()
•	File format: pipe-delimited (|) with comma-separated courses

Menu
•	Owns a CourseManager instance
•	run() loop with input validation and cin error recovery
•	handleInput() dispatches to the appropriate manager method

Project Structure

File	Description
Person.h / Person.cpp	Base class with name & email
Student.h / Student.cpp	Derived class: ID, GPA, courses
CourseManager.h / .cpp	Core logic + file I/O
Menu.h / Menu.cpp	Console UI & input handling
StudentCourseManagementSystem.cpp	Entry point (main)
database.txt	Auto-generated persistent storage

Database File Format (database.txt)
Each student is stored as a single pipe-delimited line:

ID|Name|Email|GPA|Course1,Course2,...

Example:
1001|Ahmed Ali|ahmed@example.com|3.75|Math,Physics,CS101
1002|Sara Khaled|sara@example.com|3.20|

Notes:
•	Courses are comma-separated; empty if none enrolled
•	File is written with ios::out (full overwrite) on save
•	New students are appended with ios::app via appendStudentToFile()
•	loadFromFile() clears in-memory map before reading

How to Compile and Run
Visual Studio (Windows)
•	Open the project folder in Visual Studio 2019 or 2022
•	Ensure all .cpp and .h files are included in the project
•	Build the solution with Ctrl + Shift + B
•	Run with Ctrl + F5

g++ (Linux / macOS)
g++ -std=c++17 -o scms StudentCourseManagementSystem.cpp \
    CourseManager.cpp Menu.cpp Student.cpp Person.cpp
./scms

Technologies Used
•	C++17
•	OOP — Inheritance, virtual methods, encapsulation
•	STL: map, set, vector, algorithm (sort), fstream, sstream

Constraints & Validation
•	Student ID must be unique — duplicates are rejected
•	GPA must be between 0.0 and 4.0 inclusive
•	A student cannot enrol in the same course twice (enforced by set<string>)
•	Non-numeric menu input is caught and the user is prompted to retry

Known Issues & Notes
•	searchStudent() contains unreachable code after the return statement (file read block) — can be safely removed
•	appendStudentToFile() guards against count > 1, but the condition should be == 1 to correctly skip duplicates
•	enrollInCourse() updates in-memory only; call Save to File (option 8) afterwards to persist changes


Developed by Altarek Mohamed Alsaied Twfiek  |  March 2026
