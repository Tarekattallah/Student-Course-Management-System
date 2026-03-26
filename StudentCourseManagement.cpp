#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Student.h"

using namespace std;

vector<Student> students;

void showMenu() {
    cout << "\n=== Student Course Management System ===\n";
    cout << "1. Add Student\n";
    cout << "2. Remove Student\n";
    cout << "3. Search Student\n";
    cout << "4. Display All Students\n";
    cout << "5. Enroll Student in Course\n";
    cout << "6. Show Student Courses\n";
    cout << "7. Sort Students by GPA\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "\n--- Add New Student ---\n";
            int id;
            string name;
            double gpa;
            bool idExists = false;

            cout << "Enter Student ID: ";
            cin >> id;
            cin.ignore();

            for (size_t i = 0; i < students.size(); i++) {
                if (students[i].getId() == id) {
                    idExists = true;
                    break;
                }
            }

            if (idExists) {
                cout << "Error: This ID is already used!\n";
            }
            else {
                cout << "Enter Student Name: ";
                getline(cin, name);

                cout << "Enter GPA (0.0 - 4.0): ";
                cin >> gpa;

                if (gpa < 0.0 || gpa > 4.0) {
                    cout << "Error: GPA must be between 0.0 and 4.0\n";
                }
                else {
                    students.push_back(Student(id, name, gpa));
                    cout << "Student added successfully!\n";
                }
            }
        }
        else if (choice == 2) {
            cout << "\n--- Remove Student ---\n";
            int id;
            cout << "Enter Student ID to remove: ";
            cin >> id;
            cin.ignore();

            bool found = false;
            for (size_t i = 0; i < students.size(); i++) {
                if (students[i].getId() == id) {
                    students.erase(students.begin() + i);
                    cout << "Student removed successfully!\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Error: Student with this ID not found!\n";
            }
        }
        else if (choice == 3) {
            cout << "\n--- Search Student ---\n";
            int id;
            cout << "Enter Student ID to search: ";
            cin >> id;
            cin.ignore();

            bool found = false;
            for (size_t i = 0; i < students.size(); i++) {
                if (students[i].getId() == id) {
                    cout << "Student Found!\n";
                    cout << "ID   : " << students[i].getId() << endl;
                    cout << "Name : " << students[i].getName() << endl;
                    cout << "GPA  : " << students[i].getGpa() << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Error: Student with this ID not found!\n";
            }
        }
        else if (choice == 4) {
            cout << "\n--- Display All Students ---\n";
            if (students.empty()) {
                cout << "No students yet!\n";
            }
            else {
                for (size_t i = 0; i < students.size(); i++) {
                    cout << "Student " << (i + 1) << ":\n";
                    cout << "ID   : " << students[i].getId() << endl;
                    cout << "Name : " << students[i].getName() << endl;
                    cout << "GPA  : " << students[i].getGpa() << endl;
                    cout << "------------------------\n";
                }
            }
        }
        else if (choice == 5) {
            cout << "\n--- Enroll Student in Course ---\n";
            int id;
            string course;
            cout << "Enter Student ID: ";
            cin >> id;
            cin.ignore();

            bool found = false;
            for (size_t i = 0; i < students.size(); i++) {
                if (students[i].getId() == id) {
                    found = true;
                    cout << "Enter Course Name: ";
                    getline(cin, course);

                    bool courseExists = false;
                    for (size_t j = 0; j < students[i].getCourses().size(); j++) {
                        if (students[i].getCourses()[j] == course) {
                            courseExists = true;
                            break;
                        }
                    }

                    if (courseExists) {
                        cout << "This course is already enrolled!\n";
                    }
                    else {
                        students[i].enrollCourse(course);
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Error: Student with this ID not found!\n";
            }
        }
        else if (choice == 6) {
            cout << "\n--- Show Student Courses ---\n";
            int id;
            cout << "Enter Student ID: ";
            cin >> id;
            cin.ignore();

            bool found = false;
            for (size_t i = 0; i < students.size(); i++) {
                if (students[i].getId() == id) {
                    found = true;
                    students[i].displayCourses();
                    break;
                }
            }
            if (!found) {
                cout << "Error: Student with this ID not found!\n";
            }
        }
        else if (choice == 7) {
            cout << "\n--- Sort Students by GPA ---\n";
            if (students.empty()) {
                cout << "No students to sort!\n";
            }
            else {
                sort(students.begin(), students.end(),
                    [](const Student& a, const Student& b) {
                        return a.getGpa() > b.getGpa();
                    });
                cout << "Students sorted by GPA successfully!\n";
                cout << "Check option 4 to see the sorted list.\n";
            }
        }
        else if (choice == 8) {
            cout << "Thank you for using the system. Goodbye!\n";
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}