//********************************************************************
// File: linked_list.cpp
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

#include "../include/linked_list.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
    head = new Node;
    tail = head;
    head->next = 0;
    node_count = 0;
}

LinkedList::~LinkedList()
{}

void LinkedList::insert_chronologically(ResData * data){
    if (node_count == 0) {
        insert_to_back(data);
    } else if (head->next->data->get_time() > data->get_time()) {
        insert_to_front(data);
    } else if (tail->data->get_time() < data->get_time()) {
        insert_to_back(data);
    } else {
        Node * ptr = head;
        Node * newN = new Node;
        newN->data = data;

        while (ptr->next->data->get_time() < newN->data->get_time()) {
            ptr = ptr->next;
        }
        newN->next = ptr->next;
        ptr->next = newN;
        
        node_count++;
    }
}

void LinkedList::insert_to_front(ResData * data){
    Node * ptr = new Node;
    ptr->data = data;
    
    ptr->next = head->next;
    head->next = ptr;
    
    node_count++;
}

void LinkedList::insert_to_back(ResData * data){
    Node * ptr = head->next;
    
    while (ptr != 0) {
        ptr = ptr->next;
    }
    
    tail->next = new Node;
    tail = tail->next; 
    tail->data = data;
    tail->next = 0;
    
    node_count++;
}

void LinkedList::pop_front(){
    Node * victim = head->next;
    head->next = head->next->next;
    
    node_count--;
    if (node_count == 0) {
       tail = head;
    }
    
    victim->data->out_display();
    
    delete victim->data;
    delete victim;
    
}

void LinkedList::lookup_all(){
    Node * ptr = head;
    while (ptr->next != 0) {
        ptr = ptr->next;
        ptr->data->out_display();
    }
}

bool LinkedList::does_exist(){
    if (node_count == 0) {
        return 0;
    } else {
        return 1;
    }
}

int LinkedList::get_node_count(){
    return node_count;
}