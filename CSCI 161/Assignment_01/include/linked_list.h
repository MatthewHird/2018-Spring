#pragma once 
//  #include "../include/reservation_system.h"

class LinkedList
{
private:  
    struct Node{
        Data * data;
        Node * next;
    };
    Node * head;
    Node * tail;
    
public:
    LinkedList();  // Constructor declaration
    
    void insertToFront(Data * data);
    void insertToBack(Data * data);
    Data popFront(int key);
    Data popBack(int key);
    Data &lookup(int key);
    bool exists(int key);    
};