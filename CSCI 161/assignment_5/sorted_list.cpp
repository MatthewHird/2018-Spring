//------------------------------------------------------------------------------
// @file       sorted_list.cpp
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The main function for the program pex5.
//------------------------------------------------------------------------------

#include "sorted_list.h"
#include <iostream>


SortedList::SortedList()
{
    head = new Node;
    head->next = nullptr;
}


SortedList::~SortedList()
{
    Node* victim = head->next;
    while (victim != nullptr)
    {
        head->next = victim->next;
        delete victim;
        victim = head->next;
    }
    
    delete head;
}


void SortedList::insert(std::string k)
{
    Node* ptr = head;
    Node* new_entry = new Node;
    new_entry->name = k;


    while (ptr->next != nullptr && ptr->next->name < k)
    {
        ptr = ptr->next;
    }

    new_entry->next = ptr->next;
    ptr->next = new_entry;
}


void SortedList::remove(std::string k)
{
    Node* ptr = head;
    Node* victim = head->next;

    while (victim != nullptr)
    {
        if (victim->name == k)
        {
            ptr->next = victim->next;
            delete victim;
            return;
        }
        
        ptr = ptr->next;
        victim = victim->next;
    }
}


std::string SortedList::get_sorted_list()
{
    std::string all_names;
    Node* ptr = head->next;
    while (ptr != nullptr)
    {
       all_names += ptr->name + "\n";
       ptr = ptr->next;
    }
    
    return all_names;
}