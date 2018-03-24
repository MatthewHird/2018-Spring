//------------------------------------------------------------------------------
// @file       dictionary.inl.h
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The main function for the program pex5.
//------------------------------------------------------------------------------

#pragma once
#include "my_exceptions.h"


template<class Key, class Data>
Dictionary<Key,Data>::Dictionary()
{}


template<class Key, class Data>
Dictionary<Key,Data>::Dictionary(const Dictionary& other)
{

}


template<class Key, class Data>
Dictionary<Key,Data>::~Dictionary()
{}


template<class Key, class Data>
void Dictionary<Key,Data>::insert(Key k, Data& d) throw(FullContainer)
{

}


template<class Key, class Data>
void Dictionary<Key,Data>::remove(Key k) throw(EmptyContainer)
{

}


template<class Key, class Data>
Data& Dictionary<Key,Data>::lookup(Key k) throw(EmptyContainer)
{

}


template<class Key, class Data>
int Dictionary<Key,Data>::search(Key k)
{

}