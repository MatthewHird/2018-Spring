//------------------------------------------------------------------------------
// @file stack.h
// @author     Matthew Hird
// @date       March 5, 2018
//
// @brief      
//------------------------------------------------------------------------------

#pragma once
#include "my_exceptions.h"

template <class Data>
class Stack
{
private:
    struct Node
    {
        Data* data;
        Node* next;
    };
    
    Node* head;

public:
    Stack();
    ~Stack();

    void push(Data& data);
    Data& pop()throw(EmptyStack);
    Data& peek()throw(EmptyStack);

    bool is_empty();
    void clear();
};

#include "stack.inl"