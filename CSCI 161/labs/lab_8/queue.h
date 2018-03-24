#pragma once

#include <iostream>

template<class Data>
class Queue
{
public:
    Queue();
    Queue(int cap);
    Queue(const Queue& other);
    ~Queue();

    void enqueue(Data& data)throw(FullQueue);
    Data& dequeue()throw(EmptyQueue);
    int get_size();
    bool is_empty();
    bool is_full();
    int get_capacity();
    void clear();

private:
    static const int CAP = 100;
    int capacity;
    int front;
    int back;
};

#include "queue.inl.h"