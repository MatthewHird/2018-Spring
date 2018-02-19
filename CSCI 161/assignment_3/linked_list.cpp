//********************************************************************
// File: linked_list.cpp
// Author: Matthew Hird
// Date: February 6, 2018
// Updated: February 15, 2018, February 16, 2018
//
// Purpose: Singly linked list that creates and controls nodes that
//      "store" data by pointing to ResData class objects.
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

LinkedList::~LinkedList(){
    delete head;
}

void LinkedList::push_chron(ResData* data){
    Node* ptr = head;
    Node* new_node = new Node;
    new_node->data = data; 
    for (int i = 0; i < node_count; i++) {
        if (ptr->next->data->get_time() > new_node->data->get_time()) {
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

ResData* LinkedList::pop_front(){
    Node* ptr;
    ptr = head->next;
    head->next = head->next->next;
    node_count--;
    ResData* temp = ptr->data;
    delete ptr;
    return temp;
}

std::string LinkedList::lookup_all(){
    std::ostringstream oss;
    Node* ptr = head->next;
    for (int i = 0; i < node_count; i++) {
        oss << ptr->data->display_data();
        ptr = ptr->next;
    }
    return oss.str();
}

int LinkedList::get_node_count(){
    return node_count;
}