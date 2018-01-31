//********************************************************************
// File: reservation_system.h
// Author: Matthew Hird
// Date: January 15, 2018
// Updated: January 22, 2018
//
// Purpose: Using a menu and prompts, reservation data can be submitted 
//      and stored, and stored reservation data can be output to the user 
//********************************************************************

#pragma once
#include <fstream>
#include <sstream>
#include "../include/linked_list.h"
#include "../include/res_data.h"
using namespace std;

class ReservationSystem
{
private:
    int term;
    int res_fulfill_count;
    string pickup_hour;
    string pickup_minute;
    string garbage;
    string pickup_location;
    string pickup_name;
    LinkedList resList;     // Declares a linked list in class scope
                            
public:
    ReservationSystem();    // Constructor declaration
    ~ReservationSystem();   // Destructor declaration
    
    void menu();            // Starts the control menu
    void submit();          // Propts user for data and sends the data to linked list
    void pickup_next();     // Outputs data from the earliest reservation in the list
    void list();            // Outputs data from each reservation in chronological order
    void terminate();       // Outputs the number of fulfilled reservations and terminates the program
};