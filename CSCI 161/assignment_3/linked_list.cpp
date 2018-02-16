//********************************************************************
// File: linked_list.cpp
// Author: Matthew Hird
// Date: February 6, 2018
// Updated: February 15, 2018
//
// Purpose: Singly linked list that creates and controls nodes that
//      "store" data by pointing to ResData class objects.
//********************************************************************

#include "linked_list.h"
#include <iostream>
#include <sstream>
using namespace std;


LinkedList::LinkedList(){
	node_count = 0;
	head = 0;   
}

LinkedList::~LinkedList(){
    
}

void LinkedList::push_front(ResData * data){
    
}

ResData * LinkedList::pop_front(){
    
}

string LinkedList::lookup_all(){
    ostringstream oss;
    Node * ptr = head;
    do {
    	oss << ptr->data;
    } while(ptr->next != 0);
    return oss.str();
}

int LinkedList::get_node_count(){
    return node_count;
}