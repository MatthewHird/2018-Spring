//------------------------------------------------------------------------------
// @file       dictionary.h
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The main function for the program pex5.
//------------------------------------------------------------------------------

#pragma once
#include "my_exceptions.h"


template<class Key, class Data>
class Dictionary
{
public:
    Dictionary();
    Dictionary(const Dictionary& other);
    ~Dictionary();

    void insert(Key k, Data& d) throw(FullContainer);
    void remove(Key k) throw(EmptyContainer);
    Data& lookup(Key k) throw(EmptyContainer);

private:
    int search(Key k);
    
    struct Entry
    {
        Key key;
        Data* data;
    };
   
    static const int CAP = 200;
    int size;
    Entry entries[CAP];

};

#include "dictionary.inl.h"