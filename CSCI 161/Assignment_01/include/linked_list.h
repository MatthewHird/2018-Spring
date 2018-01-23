//********************************************************************
// File: linked_list.h
// Author: Matthew Hird
// Date: January 15, 2018
// Updated: January 22, 2018
//
// Purpose: a brief description of what's in the file
//
// Notes: optional - any additional notes on the use of the file
//
// References: optional - a list of related reference materials
//********************************************************************

#pragma once 
#include "../include/res_data.h"


class LinkedList
{
private:  
    struct Node{
        ResData * data;
        Node * next;
    };
    Node * head;
    Node * tail;
    int node_count;
    
public:
    LinkedList();  // Constructor declaration
    ~LinkedList(); // Deconstructor declaration
    
    void insert_chronologically(ResData * data);
    void insert_to_front(ResData * data);
    void insert_to_back(ResData * data);
    void pop_front();
    void lookup_all();
    bool does_exist(); 
    int get_node_count();
};