//********************************************************************
// File: linked_list.h
// Author: Matthew Hird
// Date: February 6, 2018
// Updated: February 15, 2018, February 16, 2018
//
// Purpose: Singly linked list that creates and controls nodes that
//      "store" data by pointing to ResData class objects.
//********************************************************************

#pragma once
#include "res_data.h"
#include <sstream>
using namespace std;


class LinkedList
{
private:
    struct Node{
        ResData * data;
        Node * next;
    };
    
    Node * head;
    int node_count;
    
public:
    LinkedList();
    ~LinkedList();
    
    void push_chron(ResData * data);
    ResData * pop_front();
    string lookup_all();
    int get_node_count();
};