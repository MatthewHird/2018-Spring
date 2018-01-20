//********************************************************************
// File: linked_list.cpp
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

#include "../include/linked_list.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
    head = new Node;
    tail = head;
    head->next = 0;
}

LinkedList::~LinkedList()
{}

void LinkedList::insertToFront(ResData * data){
    
}

void LinkedList::insertToBack(ResData * data){
    
}

ResData LinkedList::popFront(int key){
    
}

ResData LinkedList::popBack(int key){
    
}

ResData & LinkedList::lookup(int key){
    
}

bool LinkedList::exists(int key){
    return 1;
}