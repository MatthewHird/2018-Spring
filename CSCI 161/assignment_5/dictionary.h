//------------------------------------------------------------------------------
// @file       dictionary.h
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The main function for the program pex5.
//------------------------------------------------------------------------------

#pragma once
#include "my_exceptions.h"
#include "my_list.h"


template<class Data>
class Dictionary
{
public:
    Dictionary();
    Dictionary(int cap);
    Dictionary(const Dictionary& other);
    ~Dictionary();

    void insert(std::string k, const Data& d) throw(FullContainer, DuplicateKey);
    const Data& remove(std::string k) throw(EmptyContainer, MissingKey);
    const Data& lookup(std::string k) throw(EmptyContainer, MissingKey);

    int get_size();
    std::string get_key_list();
    bool has_key(std::string k);

private:
    int bin_search(std::string k);
    
    struct Entry
    {
        std::string key;
        const Data* data;
    };
   
    static const int CAP = 200;
    int capacity;
    int size;
    Entry * entries;
    MyList key_list;
};

#include "dictionary.inl.h"