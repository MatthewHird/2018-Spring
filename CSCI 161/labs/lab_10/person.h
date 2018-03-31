#pragma once
#include <iostream>


class Person
{
public:
    Person();
    Person(std::string in_name);
    Person(const Person& other);
    ~Person();

    int get_child_count();

private:
    std::string name;
    std::string parent;
    std::string* children;
    int child_count;
};