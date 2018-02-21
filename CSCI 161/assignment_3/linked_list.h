//------------------------------------------------------------------------------
// @file linked_list.h
// @author     Matthew Hird
// @date       February 20, 2018
//
// @brief      A sorted, singly linked list. Nodes are inserted into the list in
//             chronological order based on the time value of the ResData object
//             pointed at by each node.
//------------------------------------------------------------------------------

#pragma once
#include "res_data.h"
#include <sstream>


class LinkedList
{
private:
    struct Node
    {
        ResData* data;
        Node* next;
    };
    
    Node* head;
    int node_count;
    
public:
    /* Default constructo */
    LinkedList();


    /* Destructor */
    ~LinkedList();
    

    /**
     * @brief      Inserts a node, that points to the data parameter, into the
     *             list in chronological order based on the time value of data.
     *
     * @param      data  Pointer to the ResData object to be stored in the list.
     */
    void push_chron(ResData* data);

    
    /**
     * @brief      Removes the first item from the list, deletes the node, and
     *             returns a pointer to the ResData that was stored.
     *
     * @return     Pointer to the ResData object that was removed from the list.
     */
    ResData* pop_front();
    

    /**
     * @brief      Retrieves the formatted data from each node, combines all of
     *             the data into a single string.
     *
     * @return     All of the formatted data contained in the list, concatenated
     *             into a string.
     */
    std::string lookup_all();

    
    /**
     * @brief      Gets the number of real nodes in the list.
     *
     * @return     node_count
     */
    int get_node_count();
};