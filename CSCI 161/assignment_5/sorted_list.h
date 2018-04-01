//------------------------------------------------------------------------------
// @file       sorted_list.h
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The main function for the program pex5.
//------------------------------------------------------------------------------

#pragma once
#include <iostream>


class SortedList
{
public:
    /**
     * @brief      Default constructor.
     */
    SortedList();
    

    /**
     * @brief      Destructor.
     */
    ~SortedList();

    
    /**
     * @brief      Inserts string into list alphabetically.
     *
     * @param[in]  k     std::string to be stored in SortedList.
     */
    void insert(std::string k);
    

    /**
     * @brief      Removes string 'k' from list.
     *
     * @param[in]  k     std::string to be removed from SortedList.
     */
    void remove(std::string k);
    

    /**
     * @brief      Gets list of all strings stored in list.
     *
     * @return     The list of 'strings' stored in SortedList, concatenated
     *             into a single std::string. Each 'string' is seperated by a
     *             newline character '\n'.
     */
    std::string get_sorted_list();

private:
    struct Node
    {
        Node* next;
        std::string name;
    };

    Node* head;
};