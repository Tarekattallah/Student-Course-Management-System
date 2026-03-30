#include "Person.h"

Person::Person()
    : m_name(""), m_email("") {
}

Person::Person(string name, string email)
    : m_name(name), m_email(email) {
}

void Person::SetName(string name)
{
    m_name = name;
}

void Person::SetEmail(string email)
{
    m_email = email;
}

string Person::GetName() const
{
    return m_name;
}

string Person::GetEmail() const
{
    return m_email;
}

void Person::display() const
{
    cout << "Name  : " << m_name << "\n";
    cout << "Email : " << m_email << "\n";
}