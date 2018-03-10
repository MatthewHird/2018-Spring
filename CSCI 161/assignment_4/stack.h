//------------------------------------------------------------------------------
// @file stack.h
// @author     Matthew Hird
// @date       March 5, 2018
//
// @brief      
//------------------------------------------------------------------------------

#pragma once
#include "my_exceptions.h"


class Stack
{
private:
    struct Data 
    {};

    struct Node
    {
        Data* data;
        Node* next;
    };
    
    Node* head;
    int node_count;

public:
    Stack();
    ~Stack();

    void push(Data& data);
    Data& pop()throw(EmptyStack);
    Data& peek()throw(EmptyStack);

    bool is_empty();
    int get_size();

    void empty();
};