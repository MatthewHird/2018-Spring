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
public:
    Stack();
    ~Stack();

    void push(const Data& data);
    Data pop()throw(EmptyStack);
    const Data& peek()throw(EmptyStack);

    bool is_empty();
    void clear();

private:
    struct Node
    {
        Data data;
        Node* next;
    };
    Node* head;
};

#include "stack.inl"