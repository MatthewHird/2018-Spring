#pragma once
#include <iostream>


class Person
{
protected:
    std::string name;

public:
    Person();
    Person(std::string in_name);
    Person(const Person& other);
    ~Person();

    std::string get_name() const;
    void set_name(std::string in_name);
    void display() const;
};


class Student : public Person
{
private:
    int credits;
    double gpa;
public:
    Student();
    Student(std::string in_name, int creds, double gp_avg);
    Student(const Student& other);
    ~Student();

    void operator=(const Student& other);
    void display() const;

    void set_credits(int creds);
    int get_credits();
    void set_gpa(double gp_avg);
    double get_gpa();
};