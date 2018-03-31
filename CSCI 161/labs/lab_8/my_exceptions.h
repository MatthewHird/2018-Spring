#pragma once
#include <exception>


class FullQueue : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Error: Full queue";
    };
};


class EmptyQueue : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Error: Empty queue";
    };
};