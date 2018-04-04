//------------------------------------------------------------------------------
// @file       my_exceptions.h
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The declaration and implementation of custom exception classes
//             used in pex5. Each of the exceptions is a subclass of 
//             std::exception.
//------------------------------------------------------------------------------

#pragma once
#include <exception>


class InvalidInput : public std::exception
{
public:
    /**
     * @brief      Returns a null terminated error message.
     *
     * @return     Error message.
     */
    const char* what() const throw()
    {
        return "Error: Invalid input\n";
    };
};


class EmptyInput : public std::exception
{
public:
    /**
     * @brief      Returns a null terminated error message.
     *
     * @return     Error message.
     */
    const char* what() const throw()
    {
        return "Error: Empty input\n";
    };
};


class FullContainer : public std::exception
{
public:
    /**
     * @brief      Returns a null terminated error message.
     *
     * @return     Error message.
     */
    const char* what() const throw()
    {
        return "Error: Full container\n";
    };
};


class EmptyContainer : public std::exception
{
public:
    /**
     * @brief      Returns a null terminated error message.
     *
     * @return     Error message.
     */
    const char* what() const throw()
    {
        return "Error: Empty container\n";
    };
};


class DuplicateKey : public std::exception
{
public:
    /**
     * @brief      Returns a null terminated error message.
     *
     * @return     Error message.
     */
    const char* what() const throw()
    {
        return "Error: Duplicate key\n";
    };
};


class MissingKey : public std::exception
{
public:
    /**
     * @brief      Returns a null terminated error message.
     *
     * @return     Error message.
     */
    const char* what() const throw()
    {
        return "Error: Missing key\n";
    };
};