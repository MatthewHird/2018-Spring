#pragma once

#include <iostream>
#include "my_exceptions.h"


template<class Data>
Queue<Data>::Queue()
    :capacity(CAP)
    , front(0)
    , back(0)
{
    q_ray = new Data[capacity];
}


template<class Data>
Queue<Data>::Queue(int cap)
    :capacity(cap)
    , front(0)
    , back(0)
{
    q_ray = new Data[capacity];
}


template<class Data>
Queue<Data>::Queue(const Queue& other)
{
    capacity = other.capacity;
}


template<class Data>
Queue<Data>::~Queue()
{
    delete []q_ray;
}


template<class Data>
void Queue<Data>::enqueue(Data& data)throw(FullQueue)
{
    if (is_full())
    {
        throw FullQueue();
    }

    q_ray[back] = data;
    back++;
}


template<class Data>
Data& Queue<Data>::dequeue()throw(EmptyQueue)
{
    if (is_empty())
    {
        throw EmptyQueue();
    }

    Data& data = q_ray[front];
    front ++;
    return data;
}


template<class Data>
int Queue<Data>::get_size()
{
    return ((capacity + back - front) % capacity);
}


template<class Data>
int Queue<Data>::get_capacity()
{
    return capacity;
}


template<class Data>
bool Queue<Data>::is_empty()
{
    return (back == front);
}


template<class Data>
bool Queue<Data>::is_full()
{
    return (front - back == 1 || back - front == capacity - 1);
}


template<class Data>
void Queue<Data>::clear()
{
    front = 0;
    back = 0;
}