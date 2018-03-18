//------------------------------------------------------------------------------
// @file       my_exceptions.h
// @author     Matthew Hird
// @date       March 17, 2018
//
// @brief      The declaration and implementation of custom exception classes
//             used in pex4.
//------------------------------------------------------------------------------

#pragma once
#include <exception>


class EmptyStack : public std::exception
{
public:
    /**
     * @brief      Returns a null terminated error message.
     *
     * @return     Error message.
     */
    const char* what() const throw()
    {
        return "Error: Stack is empty\n";
    };
};


class InvalidArguments : public std::exception
{
public:
    
    /**
     * @brief      Returns a null terminated error message.
     *
     * @return     Error message.
     */
    const char* what() const throw()
    {
        return "Error: Invalid arguments\n";
    };
};