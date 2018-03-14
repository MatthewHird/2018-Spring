//------------------------------------------------------------------------------
// @file stack.cpp
// @author     Matthew Hird
// @date       March 5, 2018
//
// @brief      
//------------------------------------------------------------------------------

#include "stack.h"
#include "my_exceptions.h"


template<class Data>
Stack<Data>::Stack()
{
    head = nullptr;
}


template<class Data>
Stack<Data>::~Stack()
{

}


template<class Data>
void Stack<Data>::push(const Data& data)
{
    Node* ptr = new Node;
    ptr->data = data;

    ptr->next = head;
    head = ptr;
}


template<class Data>
Data Stack<Data>::pop()throw(EmptyStack)
{
    if (this->is_empty())
    {
        throw EmptyStack();
    }
    
    Node* ptr = head;
    Data data = head->data;
    head = head->next;
    delete ptr;
    return data;
}


template<class Data>
const Data& Stack<Data>::peek()throw(EmptyStack)
{
    if (this->is_empty())
    {
        throw EmptyStack();
    }
    
    return head->data;
}


template<class Data>
bool Stack<Data>::is_empty()
{
    return (head == nullptr);
}



template<class Data>
void Stack<Data>::clear()
{
    while (! is_empty())
    {
        this->pop();
    }
}