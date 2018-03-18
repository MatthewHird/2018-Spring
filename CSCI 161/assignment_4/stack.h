//------------------------------------------------------------------------------
// @file       stack.h
// @author     Matthew Hird
// @date       March 17, 2018
//
// @brief      Declaration of the templated class Stack. Contains basic public 
//             methods typical of a stack (push, pop, peek, is_empty, and 
//             clear). The implementation is in the "inline" file, stack.inl,
//             that is included after the class declaration. 
//------------------------------------------------------------------------------

#pragma once
#include "my_exceptions.h"

/**
 * @brief      A basic stack class that manages Data objects.
 *
 * @tparam     Data  The type of objects that can be stored in and retrieved
 *                   from the stack. 
 */
template <class Data>
class Stack
{
public:
    /**
     * @brief      Default constructor.
     */
    Stack();


    /**
     * @brief      Destructor.
     */
    ~Stack();


    /**
     * @brief      Pushes a copy of Data object to the stack.
     *
     * @param[in]  data  The Data object to be stored in the stack.
     */
    void push(const Data& data);

    
    /**
     * @brief      Removes the front Data object from the stack and returns it.
     *
     * @return     Data object that was stored at the front of the stack.
     * 
     * @throw      EmptyStack   Thrown if stack is empty when method is called. 
     */
    Data pop()throw(EmptyStack);

    
    /**
     * @brief      Returns a constant reference to the Data object at the front 
     *             of the stack.
     *
     * @return     Reference to Data object currently at the front of the stack.
     * 
     * @throw      EmptyStack   Thrown if stack is empty when method is called.
     */
    const Data& peek()throw(EmptyStack);


    /**
     * @brief      Determines if stack is empty.
     *
     * @return     True if empty; False otherwise.
     */
    bool is_empty();

    
    /**
     * @brief      Empties the stack.
     */
    void clear();


private:
    struct Node
    {
        Data data;
        Node* next;
    };
    
    Node* head;
};

#include "stack.inl"