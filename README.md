# 🎓 Student Course Management System

<div align="center">

![C++](https://img.shields.io/badge/C++-17-blue?style=for-the-badge&logo=cplusplus&logoColor=white)
![OOP](https://img.shields.io/badge/OOP-Inheritance-green?style=for-the-badge)
![STL](https://img.shields.io/badge/STL-map%20%7C%20set%20%7C%20vector-orange?style=for-the-badge)
![File I/O](https://img.shields.io/badge/File%20I%2FO-fstream-purple?style=for-the-badge)

A console-based C++ application to manage students and their courses using Object-Oriented Programming concepts.

</div>

---

## 📋 Table of Contents

- [Features](#-features)
- [Architecture](#-architecture)
- [Project Structure](#-project-structure)
- [Menu Options](#-menu-options)
- [Database Format](#-database-format)
- [How to Run](#-how-to-run)
- [Notes](#-notes)

---

## ✨ Features

- ➕ Add a new student with unique ID and GPA validation
- ❌ Remove a student by ID
- 🔍 Search for a student by ID
- 📋 Display all registered students
- 📚 Enroll a student in a course (no duplicate courses)
- 🗂️ Show all courses for a specific student
- 📊 Sort students by GPA (descending order)
- 💾 Save all data to `database.txt`
- 📂 Load data from `database.txt`

---

## 🏗️ Architecture

```
Person  (base class)
└── Student  (derived class)
        └── managed by CourseManager
                        └── driven by Menu
```

| Class | Responsibility |
|-------|---------------|
| `Person` | Base class — stores name & email |
| `Student` | Derived class — adds ID, GPA, and a set of courses |
| `CourseManager` | Core logic: CRUD operations + file I/O |
| `Menu` | Console UI and input handling |

---

## 📁 Project Structure

```
Student-Course-Management-System/
│
├── Person.h                          # Base class declaration
├── Person.cpp                        # Base class implementation
│
├── Student.h                         # Derived class declaration
├── Student.cpp                       # Derived class implementation
│
├── CourseManager.h                   # Manager class declaration
├── CourseManager.cpp                 # Manager class implementation
│
├── Menu.h                            # Menu class declaration
├── Menu.cpp                          # Menu class implementation
│
├── StudentCourseManagementSystem.cpp # Entry point (main)
│
├── database.txt                      # Auto-generated persistent storage
└── README.md
```

---

## 🖥️ Menu Options

```
 ================================================
    Student Course Management System
 ================================================
   1)  Add Student
   2)  Remove Student
   3)  Search Student
   4)  Display All Students
   5)  Enroll Student in Course
   6)  Show Student Courses
   7)  Sort Students by GPA
   8)  Save to File
   9)  Load from File
   10) Exit
 ================================================
```

---

## 🗄️ Database Format

Each student is saved as a single line in `database.txt`:

```
ID|Name|Email|GPA|Course1,Course2,...
```

**Example:**
```
1001|Ahmed Ali|ahmed@example.com|3.75|Math,Physics,CS101
1002|Sara Khaled|sara@example.com|3.20|
```

---

## 🚀 How to Run

### Visual Studio (Windows)

1. Open the project folder in **Visual Studio 2019 or 2022**
2. Make sure all `.cpp` and `.h` files are included in the project
3. Build the solution → `Ctrl + Shift + B`
4. Run the program → `Ctrl + F5`

### g++ (Linux / macOS)

```bash
g++ -std=c++17 -o scms \
    StudentCourseManagementSystem.cpp \
    CourseManager.cpp Menu.cpp Student.cpp Person.cpp

./scms
```

---

## 📝 Notes

- Each student must have a **unique ID** — duplicates are rejected
- GPA must be between **0.0 and 4.0**
- A student **cannot enroll in the same course twice** (enforced by `set<string>`)
- Data is **saved automatically** when adding or removing students
- Use options **8 and 9** to manually save/load from `database.txt`
- After enrolling a student in a course, use **Save (option 8)** to persist the change

---

<div align="center">

**Developed by:** Altarek Mohamed Alsaied Twfiek &nbsp;|&nbsp; 📞 +201061258009 &nbsp;|&nbsp; 📅 March 2026

</div>
