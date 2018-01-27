#pragma once
#include "i_data.h"

class DoubleLinkedList
{
private:
    struct Node {
        Node * next;
        Node * prev;
        IData * data;
    }
    
    int node_count;
    Node head;
    Node tail;
    
public:
    LinkedList();
    ~LinkedList();
    
    IData pop_front();
    IData pop_back();
    IData pop_id();
    void insert_front;
    void insert_back;
    void insert_id;
    
    int get_length();
};