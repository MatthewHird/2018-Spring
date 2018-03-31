//------------------------------------------------------------------------------
// @file       my_list.h
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The main function for the program pex5.
//------------------------------------------------------------------------------

#pragma once
#include <iostream>


class MyList
{
public:
    MyList();
    ~MyList();

    void insert(std::string k);
    void remove(std::string k);
    std::string get_my_list();

private:
    struct Node
    {
        Node* next;
        std::string name;
    };

    Node* head;
};