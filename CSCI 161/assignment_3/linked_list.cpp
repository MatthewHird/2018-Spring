//********************************************************************
// File: linked_list.cpp
// Author: Matthew Hird
// Date: February 6, 2018
// Updated: February 15, 2018, February 16, 2018, February 18, 2018,
//      February 19, 2018
//
// Purpose: A sorted, singly linked list. Nodes are inserted into the
//      list in chronological order based on the time value of the  
//      ResData object pointed at by each node. 
//********************************************************************

#include "linked_list.h"
#include <iostream>
#include <sstream>


LinkedList::LinkedList()
    : node_count(0)
{
    head = new Node;
    head->next = 0;   
}

LinkedList::~LinkedList()
{
    delete head;
}

// Takes in a ResData pointer as a parameter and creates a new node to point at it.
// The node is then inserted into the list in chronological order based on the time
// value of the ResData objects.
void LinkedList::push_chron(ResData* data)
{
    Node* ptr = head;
    Node* new_node = new Node;
    new_node->data = data; 
    
    for (int i = 0; i < node_count; i++) 
    {
        if (ptr->next->data->get_time() > new_node->data->get_time()) 
        {
            new_node->next = ptr->next;
            ptr->next = new_node;
            node_count++;
            return;
        }
        
        ptr = ptr->next;
    }
    
    new_node->next = 0;
    ptr->next = new_node;
    node_count++;
    return;
}

// Removes the first node from the list, deletes the node, and returns a pointer to the data
ResData* LinkedList::pop_front()
{
    Node* ptr = head->next;
    head->next = head->next->next;
    node_count--;
    ResData* temp = ptr->data;
    delete ptr;
    return temp;
}

// Goes through the nodes in order and retrieves the formatted data of each. All of the data
// is streamed into one object, and is returned as a single string. 
std::string LinkedList::lookup_all()
{
    std::ostringstream oss;
    
    Node* ptr = head->next;
    
    for (int i = 0; i < node_count; i++) 
    {
        oss << ptr->data->display_data();
        ptr = ptr->next;
    }
    
    return oss.str();
}

int LinkedList::get_node_count()
{
    return node_count;
}