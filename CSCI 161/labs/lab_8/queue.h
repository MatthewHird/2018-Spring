#pragma once

#include <iostream>
#include "my_exceptions.h"

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
    int get_capacity();
    bool is_empty();
    bool is_full();
    void clear();

private:
    static const int CAP = 100;
    int capacity;
    int front;
    int back;
    Data* q_ray;
};

#include "queue.inl.h"