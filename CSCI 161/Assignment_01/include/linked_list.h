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