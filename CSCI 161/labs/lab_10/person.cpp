#include "person.h"
#include <iostream>


Person::Person()
    : child_count(0)
{
    children = new Person*[MAX_KIDS];
}


Person::Person(std::string in_name)
    : child_count(0)
    , name(in_name)
{
    children = new Person*[MAX_KIDS];
}


Person::~Person()
{
    delete []children;
}