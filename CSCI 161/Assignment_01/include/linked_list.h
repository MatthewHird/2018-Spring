//********************************************************************
// File: linked_list.h
// Author: Matthew Hird
// Date: January 15, 2018
// Updated: January 19, 2018
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
    
public:
    LinkedList();  // Constructor declaration
    ~LinkedList(); // Deconstructor declaration
    
    void insertToFront(ResData* data);
    void insertToBack(ResData* data);
    ResData popFront(int key);
    ResData popBack(int key);
    ResData &lookup(int key);
    bool exists(int key);  
};