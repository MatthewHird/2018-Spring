#pragma once
#include <iostream>


class Dictionary
{
public:
    Dictionary();
    ~Dictionary();

    void insert(std::string k, std::string d);
    std::string search(std::string k);
    std::string dump_all();
    int get_node_count();


private:
    struct Node
    {
        Node* next;
        std::string key;
        std::string data;
    };
    Node* head;
    int node_count;
};