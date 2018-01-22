//********************************************************************
// File: linked_list.cpp
// Author: Matthew Hird
// Date: January 15, 2018
// Updated: January 19, 2018, January 20, 2018, January 21, 2018
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

void LinkedList::insert_chronologically(ResData * data){ ////////broken
    if (node_count == 0) {
        insert_to_front(data);
        tail = head;
    } else if (head->data->time > data->time) {
        insert_to_front(data);
    } else if (tail->data->time < data->time) {
        insert_to_back(data);
    } else {
        Node * ptr = head;
        Node * newN = new Node;
        newN->data = data;

        while (ptr->next->data->time < newN->data->time) {
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
    head = ptr;
    
    node_count++;
}

void LinkedList::insert_to_back(ResData * data){
    Node * ptr = tail;
    tail = new Node; 
    tail->data = data;
    tail->next = 0;
    
    node_count++;
}

ResData & LinkedList::lookup_front(){
    
    Node * victim = head;//->next;
    
    ResData * * out_data = &(victim->data);  //////
    
    return * * out_data;
}

void LinkedList::delete_front(){
    Node * victim = head;//->next;
    head = head->next;//->next;
    
    delete victim->data;
    delete victim;
    node_count--;
}

void LinkedList::lookup_all(){
    Node * ptr = head;
    while (ptr->next != 0) {
        ptr = ptr->next;
        ResData * temp_dat = ptr->data;
        ResData & temp_ref = * temp_dat;
        temp_ref.out_display();
    }
}

bool LinkedList::does_exist(){
    if (node_count == 0) {
        return 0;
    } else if (node_count > 0) {
        return 1;
    }
}