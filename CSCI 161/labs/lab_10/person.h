#pragma once
#include <iostream>


class Person
{
public:
    Person();
    Person(std::string in_name);
    ~Person();

    std::string name;
    Person** children;
    int child_count;
    static const int MAX_KIDS = 5;
};