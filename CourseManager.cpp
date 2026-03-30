#include "CourseManager.h"
#include <sstream>

void CourseManager::AddStudent(Student s)
{
    if (students.count(s.GetId()))
    {
        cout << "\t   Error: Student ID " << s.GetId() << " already exists.\n";
        return;
    }
    students[s.GetId()] = s;

    
    saveToFile("database.txt");
    appendStudentToFile("database.txt", s);
}

bool CourseManager::RemoveStudent(int id)
{
    loadFromFile("database.txt");

    bool removed = students.erase(id) > 0;

    if (removed)
        saveToFile("database.txt");

    return removed;
}

Student* CourseManager::searchStudent(int id)
{
    auto it = students.find(id);
    if (it != students.end())
        return &it->second;
    return nullptr;

    ifstream data("database.txt");
    if (!data.is_open())
        return nullptr;
}

void CourseManager::displayAll() const
{
    if (students.empty())
    {
        cout << "\t   No students registered.\n";
        return;
    }
    for (const auto& pair : students)
        pair.second.display();
}

void CourseManager::sortByGPA()
{
    if (students.empty())
    {
        cout << "\t   No students registered.\n";
        return;
    }

    // copy into a vector so we can sort
    vector<Student> v;
    for (auto& p : students)
        v.push_back(p.second);

    sort(v.begin(), v.end(),
        [](const Student& a, const Student& b)
        {
            return a.GetGPA() > b.GetGPA();   // highest GPA first
        });

    cout << "\t   === Students sorted by GPA ===\n";
    for (const Student& s : v)
        s.display();
}

bool CourseManager::enrollInCourse(int id, string course)
{
    Student* s = searchStudent(id);
    if (!s) return false;
    s->EnrollCourse(course);
    return true;
}

void CourseManager::showCourses(int id)
{
    Student* s = searchStudent(id);
    if (!s)
    {
        cout << "\t   Student not found.\n";
        return;
    }
    const set<string> courses = s->GetCourse();
    if (courses.empty())
    {
        cout << "\t   No courses enrolled.\n";
        return;
    }
    cout << "\t   Courses for " << s->GetName() << ":\n";
    for (const string& c : courses)
        cout << "\t     - " << c << "\n";
}


void CourseManager::saveToFile(string filename) {
    ofstream data(filename, ios::out);
    if(!data.is_open())
    {
        cout << "\t   Error: could not open file for saving.\n";
        return;
    }
    for (auto & pair : students)
    {
        Student& stud = pair.second;
        data << stud.GetId() << "|" << stud.GetName() << "|" << stud.GetEmail() << "|" << stud.GetGPA() << "|";

        const set<string> courses = stud.GetCourse();
        int i = 0;
        for (const string& course : courses) 
        {
            data << course;
            if (++i < (int)courses.size()) data << ",";
        }
        data << "\n";
    }
    data.close();
    cout << "\t   Data saved to " << filename << "\n";
}
void CourseManager::loadFromFile(string filename) {
    ifstream data(filename, ios::in);

    if (!data.is_open())
    {
        cout << "\t   Error: could not open file for loading.\n";
        return;
    }

    students.clear();
    string line;


    while (getline(data, line))
    {
        if (line.empty()) continue;

        stringstream stringstreamline(line);
        string token;


        //parse id
        getline(stringstreamline, token, '|');
        int id = stoi(token);

        //parse name
        string name;
        getline(stringstreamline, name, '|');

        //parse email
        string email;
        getline(stringstreamline, email, '|');

        //parse GPA
        getline(stringstreamline, token, '|');
        double gpa = stod(token);

       

        // build student and enroll courses
        Student stud(id, gpa, name, email);


        string coursesStr;
        getline(stringstreamline, coursesStr);

        stringstream cs(coursesStr);
        string course;
        while (getline(cs, course, ','))
            if (!course.empty())
                stud.EnrollCourse(course);

        students[id] = stud;
    }

    data.close();
    cout << "\t   Data loaded from " << filename << "\n";
}

void CourseManager::appendStudentToFile(string filename, Student& stud)
{
    if (students.count(stud.GetId()) > 1) 
    {
        cout << "\t   Student already exists in memory, won't append.\n";
        return;
    }
    ofstream data(filename, ios::app);

    if (!data.is_open())
    {
        cout << "Error opening file\n";
        return;
    }

    data << stud.GetId() << "|"
        << stud.GetName() << "|"
        << stud.GetEmail() << "|"
        << stud.GetGPA() << "|";

    const set<string>& courses = stud.GetCourse();

    int i = 0;
    for (const string& course : courses)
    {
        data << course;
        if (++i < (int)courses.size()) data << ",";
    }

    data << "\n";
}