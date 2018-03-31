#include "dictionary.h"
#include <iostream>


Dictionary::Dictionary()
{
    head = nullptr;
    node_count = 0;
}


Dictionary::~Dictionary()
{}


void Dictionary::insert(std::string k, std::string d)
{
    Node* ptr = new Node;
    ptr->key = k;
    ptr->data = d;

    ptr->next = head;
    head= ptr;
    node_count++;
}


std::string Dictionary::search(std::string k)
{
    Node* ptr = head;

    while (ptr != nullptr)
    {
        if (ptr->key == k)
        {
            return ptr->data;
        }
        ptr = ptr->next;
    }
    return " : Entry not in dictionary";
}


std::string Dictionary::dump_all()
{
    Node* ptr = head;
    std::string list_all;

    list_all += std::to_string(node_count) + "\n";

    while (ptr != nullptr)
    {
        list_all += ptr->key + ptr->data + "\n";
        ptr = ptr->next;
    }
    return list_all;
}


int Dictionary::get_node_count()
{
    return node_count;
}