#pragma once
#include "person.h"


class Stack
{
public:

    Stack();

    ~Stack();

    void push(Person* person);

    Person* pop();

    Person* peek();

    bool is_empty();

    void clear();


private:
    struct Node
    {
        Person* person;
        Node* next;
    };
    
    Node* head;
};