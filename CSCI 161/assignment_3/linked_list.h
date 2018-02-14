//********************************************************************
// File: linked_list.h
// Author: Matthew Hird
// Date: February 6, 2018
// Updated: 
//
// Purpose: Singly linked list that creates and controls nodes that
//      "store" data by pointing to ResData class objects.
//********************************************************************

#pragma once
#include "res_data.h"

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
    LinkedList();
    ~LinkedList();
    
    void push_front(ResData * data);
    ResData * pop_front();
    void pop_index(int index);
    void lookup();
    int get_node_count();
};
