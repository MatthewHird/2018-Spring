//********************************************************************
// File: linked_list.h
// Author: Matthew Hird
// Date: February 6, 2018
// Updated: February 15, 2018, February 16, 2018, February 19, 2018
//
// Purpose: A sorted, singly linked list. Nodes are inserted into the
//      list in chronological order based on the time value of the  
//      ResData object pointed at by each node. 
//********************************************************************

#pragma once
#include "res_data.h"
#include <sstream>


class LinkedList
{
private:
    struct Node
    {
        ResData* data;
        Node* next;
    };
    
    Node* head;
    int node_count;
    
public:
    LinkedList();
    ~LinkedList();
    
    // Inserts a node pointing to data into the list in chronological order 
    // based on the time value of data
    void push_chron(ResData* data); 
    
    // Removes the first item from the list, deletes the node, and returns a pointer to the
    // ResData that was stored
    ResData* pop_front();
    
    // Retrieves the formatted data from each node, combines all of the data into a single
    // string, and returns the string
    std::string lookup_all();

    // Returns the number of real nodes in the list
    int get_node_count();
};