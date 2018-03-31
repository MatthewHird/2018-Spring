#include "person.h"


//##############################################################################
// Person class implementation



Person::Person()
{
    name = "unnamed";
}


Person::Person(std::string in_name)
{
    name = in_name;
}


Person::Person(const Person& other)
{
    name = other.name;
}


Person::~Person()
{

}



std::string Person::get_name() const
{
    return name;
}


void Person::set_name(std::string in_name)
{
    name = in_name;
}


void Person::display() const
{
    std::cout << "Name: " << name << "\n\n";
}


//##############################################################################
// Student subclass of Person


Student::Student()
    : Person()
{
    credits = 0;
    gpa = 0;
}


Student::Student(std::string in_name, int creds, double gp_avg)
    : Person(in_name)
{
    credits = creds;
    gpa = gp_avg;
}


Student::Student(const Student& other)
    : Person(other)
{
    credits = other.credits;
    gpa = other.gpa;
}


Student::~Student()
{

}



void Student::operator=(const Student& other)
{
    name = other.name;
    credits = other.credits;
    gpa = other.gpa;
}


void Student::display() const
{
    std::cout << "Name: " << name << "\n"
              << "Credits: " << credits << "\n"
              << "GPA: " << gpa << "\n\n";
}


void Student::set_credits(int creds)
{
    credits = creds;
}


int Student::get_credits()
{
    return credits;
}


void Student::set_gpa(double gp_avg)
{
    gpa = gp_avg;
}


double Student::get_gpa()
{
    return gpa;
}