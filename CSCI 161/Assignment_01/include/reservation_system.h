//********************************************************************
// File: reservation_system.h
// Author: Matthew Hird
// Date: January 15, 2018
// Updated: January 19, 2018, January 20, 2018, January 21, 2018
//
// Purpose: a brief description of what's in the file
//
// Notes: optional - any additional notes on the use of the file
//
// References: optional - a list of related reference materials
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
    LinkedList resList;
    
public:
    ReservationSystem();  // Constructor declaration
    ~ReservationSystem(); // Deconstructor declaration
    
    void menu();
    void submit();
    void pickup_next();
    void list();
    void terminate();
};