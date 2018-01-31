//********************************************************************
// File: linked_list.cpp
// Author: Matthew Hird
// Date: January 15, 2018
// Updated: January 23, 2018
//
// Purpose: Singly linked list that creates and controls nodes that
//      "store" data by pointing to ResData class objects.
//********************************************************************

#include "../include/linked_list.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){       // Constructor creates a dummy node at the start of the list.
    head = new Node;            // Also sets the node counter to 0.
    tail = head;
    head->next = 0;
    node_count = 0;
}

LinkedList::~LinkedList(){       // Destructor
    Node * victim = head->next;
    Node * ptr;
    
    while (victim != 0) {
        ptr = victim->next;
        delete victim->data;
        delete victim;
        victim = ptr;
    }
    delete head;
}

// Method to insert data, taken as a parameter, in chronological order. 
void LinkedList::insert_chronologically(ResData * data){
    if (node_count == 0) {          // If the list is empty, the data will placed behind the 
        insert_to_back(data);       // dummy node by passing data to insert_to_back method
    } else if (head->next->data->get_time() > data->get_time()) { 
        insert_to_front(data);      // If the time in data is earlier than that of the first node in 
                                    // the list, data will be put at the front of the list
    } else if (tail->data->get_time() < data->get_time()) {
        insert_to_back(data);       // If the time in data is later than that of the last node in 
                                    // the list, data will be put at the back of the list
    
    } else {    // Otherwise a pointer walks through the list until it finds the appropriate 
                // position for data to be kept
        
        Node * ptr = head;          // ptr will be the pointer that walks through the list
        
        Node * newN = new Node;     // A new node is created to point to data, 
        newN->data = data;          // and will be placed in the list

        while (ptr->next->data->get_time() < newN->data->get_time()) {
            ptr = ptr->next;        // ptr walks through the list until the time in 
        }                           // the next node is later than the time in data
        newN->next = ptr->next;     
        ptr->next = newN;           // The new node that points to data is placed in the list
        
        node_count++;               // The node counter increases by 1
    }
}

// Takes a ResData pointer as a parameter and stores it in a new node. Then places the
// node at the front of the list 
void LinkedList::insert_to_front(ResData * data){
    Node * ptr = new Node;
    ptr->data = data;
    
    ptr->next = head->next;
    head->next = ptr;
    
    node_count++;
}

// Takes a ResData pointer as a parameter and stores it in a new node. Then places the
// node at the back of the list
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

// Takes the node at the front of the list, outputs its data, deletes the node, and reduces
// the node counter by 1
void LinkedList::pop_front(){
    Node * victim = head->next;
    head->next = head->next->next;
    
    node_count--;
    if (node_count == 0) {
       tail = head;
    }
    
    victim->data->out_display();    // Calls the put_display method of ResData, 
                                    //which outputs the data to the screen
    delete victim->data;
    delete victim;
    
}

// Outputs the data from node to the screen
void LinkedList::lookup_all(){
    Node * ptr = head;
    while (ptr->next != 0) {
        ptr = ptr->next;            //ptr walks through each node
        ptr->data->out_display();   //Then out_display outputs the data of that node to screen
    }
}

// Checks the node count of the linked list. If there are any nodes, it returns true; if not, false
bool LinkedList::does_exist(){
    if (node_count == 0) {
        return 0;
    } else {
        return 1;
    }
}

// Returns the current value of the node counter
int LinkedList::get_node_count(){
    return node_count;
}