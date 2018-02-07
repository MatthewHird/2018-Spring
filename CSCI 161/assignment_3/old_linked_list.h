//********************************************************************
// File: linked_list.h
// Author: Matthew Hird
// Date: January 15, 2018
// Updated: January 30, 2018
//
// Purpose: Singly linked list that creates and controls nodes that
//      "store" data by pointing to ResData class objects.
//********************************************************************

#pragma once 
#include "res_data.h"


class LinkedList
{
private:  
    struct Node{            // Declaration of the Node struct. Contains two pointers. One to the
        ResData * data;     // data it is "storing" and one to the next node in the list
        Node * next;
    };
    Node * head;
    Node * tail;
    int node_count;
    
public:
    LinkedList();  // Constructor declaration
    ~LinkedList(); // Destructor declaration
    
    void insert_chronologically(ResData * data);    // Inserts data node in chronological order
    void insert_to_front(ResData * data);           // Inserts node at the front of the list
    void insert_to_back(ResData * data);            // Inserts node at the back of the list
    void pop_front();       // Outputs data from the node at the front of the list, then deletes the node
    void lookup_all();      // Outputs data from each node in the list
    bool does_exist();      // Checks whether the list has any nodes or not
    int get_node_count();   // Returns a count of nodes currently in the list
};