#include "Student.h"

Student::Student()
    : Person("", ""), m_id(0), m_GPA(0.0) {
}

Student::Student(int id, double gpa, string name, string email)
    : Person(name, email), m_id(id), m_GPA(gpa) {
}

void Student::SetId(int id)
{
    m_id = id;
}

void Student::SetGPA(double gpa)
{
    m_GPA = gpa;
}

void Student::EnrollCourse(string course)
{
    courses.insert(course);   // set ignores duplicates automatically
}

int Student::GetId() const
{
    return m_id;
}

double Student::GetGPA() const
{
    return m_GPA;
}

set<string> Student::GetCourse() const
{
    return courses;
}

void Student::display() const
{
    cout << "\t ----------------------------------\n";
    cout << "\t  ID    : " << m_id << "\n";
    cout << "\t  Name  : " << m_name << "\n";
    cout << "\t  GPA   : " << m_GPA << "\n";
    cout << "\t  Courses: ";
    if (courses.empty())
    {
        cout << "None\n";
    }
    else
    {
        for (const string& c : courses)
            cout << c << "  ";
        cout << "\n";
    }
    cout << "\t ----------------------------------\n";
}