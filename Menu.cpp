#include "Menu.h"

void Menu::showMenu()
{
    cout << "\n";
    cout << "\t ================================================\n";
    cout << "\t    Student Course Management System            \n";
    cout << "\t ================================================\n";
    cout << "\t   1)  Add Student                              \n";
    cout << "\t   2)  Remove Student                          \n";
    cout << "\t   3)  Search Student                          \n";
    cout << "\t   4)  Display All Students                    \n";
    cout << "\t   5)  Enroll Student in Course                \n";
    cout << "\t   6)  Show Student Courses                    \n";
    cout << "\t   7)  Sort Students by GPA                    \n";
    cout << "\t   8)  Save to File                            \n";
    cout << "\t   9)  Load from File                          \n";
    cout << "\t   10) Exit                                    \n";
    cout << "\t ================================================\n";
    cout << "\t   Choice: ";
}

void Menu::run()
{
    int choice = 0;
    do
    {
        showMenu();
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\t   Invalid input. Please enter a number.\n";
            continue;
        }

        handleInput(choice);

    } while (choice != 10);
}

void Menu::handleInput(int choice)
{
    cin.ignore();   // flush leftover newline from cin >> choice

    switch (choice)
    {
    case 1:
    {
        int    id;
        double gpa;
        string name;
        string email;

        cout << "\t   Enter Student ID  : "; cin >> id;
        cout << "\t   Enter Name        : "; cin.ignore(); getline(cin, name);
        cout << "\t   Enter GPA (0-4.0) : "; cin >> gpa;
        cout << "\t   Enter Email       : "; cin.ignore(); getline(cin, email);


        if (gpa < 0.0 || gpa > 4.0)
        {
            cout << "\t   Invalid GPA. Must be between 0.0 and 4.0.\n";
            break;
        }

        manager.AddStudent(Student(id, gpa, name, email));
        cout << "\t   Student added successfully.\n";
        break;
    }
    case 2:
    {
        int id;
        cout << "\t   Enter Student ID to remove: "; cin >> id;

        if (manager.RemoveStudent(id))
            cout << "\t   Student removed successfully.\n";
        else
            cout << "\t   Student ID not found.\n";
        break;
    }
    case 3:
    {
        int id;
        cout << "\t   Enter Student ID to search: "; cin >> id;

        Student* s = manager.searchStudent(id);
        if (s)
            s->display();
        else
            cout << "\t   Student not found.\n";
        break;
    }
    case 4:
        manager.displayAll();
        break;

    case 5:
    {
        int    id;
        string course;
        cout << "\t   Enter Student ID : "; cin >> id;
        cout << "\t   Enter Course name: "; cin.ignore(); getline(cin, course);

        if (manager.enrollInCourse(id, course))
            cout << "\t   Enrolled in " << course << " successfully.\n";
        else
            cout << "\t   Student not found.\n";
        break;
    }
    case 6:
    {
        int id;
        cout << "\t   Enter Student ID: "; cin >> id;
        manager.showCourses(id);
        break;
    }
    case 7:
        manager.sortByGPA();
        break;
    case 8:
        manager.saveToFile("database.txt");
        break;
    case 9:
        manager.loadFromFile("database.txt");
        break;
    case 10:
        cout << "\t   Goodbye!\n";
        break;

    default:
        cout << "\t   Invalid choice. Please select 1-8.\n";
        break;
    }
}