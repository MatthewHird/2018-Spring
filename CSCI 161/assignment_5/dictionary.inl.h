//------------------------------------------------------------------------------
// @file       dictionary.inl.h
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The main function for the program pex5.
//------------------------------------------------------------------------------

#pragma once
#include "my_exceptions.h"
#include "my_list.h"


template<class Data>
Dictionary<Data>::Dictionary()
    : capacity(CAP)
    , size(0)
{
    entries = new Entry[capacity];
}


template<class Data>
Dictionary<Data>::Dictionary(int cap)
    : capacity(cap)
    , size(0)
{
    entries = new Entry[capacity];
}


template<class Data>
Dictionary<Data>::Dictionary(const Dictionary& other)
{
    capacity = other.capacity;
    size = other.size;
    entries = other.entries;
    for (int i = 0; i < size; i++)
    {
        entries[i] = other.entries[i];
    }
}


template<class Data>
Dictionary<Data>::~Dictionary()
{
//    for (int i =0; i < size; i++)
//    {
//        delete entries[i].data;
//    }
//
//    delete []entries;
}


template<class Data>
void Dictionary<Data>::insert(std::string k, const Data& d) throw(FullContainer, DuplicateKey)
{
    int index = bin_search(k);

    if (index < size && entries[index].key == k)
    {
        throw DuplicateKey();
    }
    if (size == capacity)
    {
        throw FullContainer();
    }

    for (int i = size; i > index; i--)
    {
        entries[i].key = entries[i - 1].key;
        entries[i].data = entries[i - 1].data;
    }

    entries[index].key = k;
    entries[index].data = &d;
    size++;
    key_list.insert(k);
}


template<class Data>
const Data& Dictionary<Data>::remove(std::string k) throw(EmptyContainer, MissingKey)
{
    int index = bin_search(k);

    if (size == 0)
    {
        throw EmptyContainer();
    }
    if (index >= size || entries[index].key != k)
    {
        throw MissingKey();
    }

    const Data* d = entries[index].data;

    for (int i = index; i < size-1; i++)
    {
        entries[i].key = entries[i + 1].key;
        entries[i].data = entries[i + 1].data;
    }

    size--;
    key_list.remove(k);

    return *d;
}


template<class Data>
const Data& Dictionary<Data>::lookup(std::string k) throw(EmptyContainer, MissingKey)
{
    int index = bin_search(k);
    
    if (size == 0)
    {
        throw EmptyContainer();
    }
    if (index >= size || k != entries[index].key)
    {
        throw MissingKey();
    }

    return *(entries[index].data);
}


template<class Data>
int Dictionary<Data>::get_size()
{
    return size;
}


template<class Data>
std::string Dictionary<Data>::get_key_list()
{
    return key_list.get_my_list();
}


template<class Data>
bool Dictionary<Data>::has_key(std::string k)
{
    int index = bin_search(k);

    if (index >= size || entries[index].key != k)
    {
        return false;
    }
    else
    {
        return true;
    }
}


template<class Data>
int Dictionary<Data>::bin_search(std::string k)
{
    int low = 0;
    int mid;
    int high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (k == entries[mid].key)
        {
            return mid;
        }
        if (k < entries[mid].key)
        {
            high = mid -1;
        }
        else 
        {
            low = mid + 1;
        }
    }

    return low;
}