#include <iostream>


template<class Data>
Queue<Data>::Queue()
    :capacity(CAP)
{}


template<class Data>
Queue<Data>::Queue(int cap)
    :capacity(cap)
{}


template<class Data>
Queue<Data>::Queue(const Queue& other)
{
    capacity = other.capacity;
}


template<class Data>
Queue<Data>::~Queue()
{

}


template<class Data>
void Queue<Data>::enqueue(Data& data)throw(FullQueue);
{

}


template<class Data>
Data& Queue<Data>::dequeue()throw(EmptyQueue);
{

}


template<class Data>
int Queue<Data>::get_size();
{

}


template<class Data>
bool Queue<Data>::is_empty();
{

}


template<class Data>
bool Queue<Data>::is_full();
{

}


template<class Data>
int Queue<Data>::get_capacity();
{

}


template<class Data>
void Queue<Data>::clear();
{
    
}