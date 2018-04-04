#include "stack.h"
#include "person.h"


Stack::Stack()
{
    head = nullptr;
}


Stack::~Stack()
{
    while (! is_empty())
    {
        pop();
    }
}


void Stack::push(Person* person)
{
    Node* ptr = new Node;
    ptr->person = person;

    ptr->next = head;
    head = ptr;
}


Person* Stack::pop()
{
    Node* ptr = head;
    Person* person = head->person;
    head = head->next;
    delete ptr;
    return person;
}


Person* Stack::peek()
{
    return head->person;
}


bool Stack::is_empty()
{
    return (head == nullptr);
}


void Stack::clear()
{
    while (! is_empty())
    {
        pop();
    }
}