//************************************************************************
// File: reservation_system.h
// Author: Matthew Hird
// Date: February 11, 2018
// Updated: February 12, 2018, February 13, 2018, February 16, 2018,
//      February 17, 2018, February 18, 2018, February 19, 2018
//
// Purpose: Using a menu and prompts, reservation data can be submitted 
//      and stored, and stored reservation data can be output to the 
//      user. Reservations can be taken for today or tomorrow. All 
//      reservations for tomorrow are stored in a .txt file when the
//      program terminates. When the program starts, all reservations
//      stored in the .txt file are saved into today's reservation list.
//************************************************************************

#pragma once
#include <fstream>
#include <sstream>
#include "linked_list.h"
#include "res_data.h"


class ReservationSystem
{
private:
    int term;
    int res_fulfill_count;
    std::string res_file;

    LinkedList todayList;
    LinkedList tomorrowList;

public:
    ReservationSystem();
    ~ReservationSystem();

    // Entrance point and controller of the reservation system class. When it is called,
    // yesterday's saved reservations are loaded into today's reservation list. Then, it 
    // displays the valid commands and prompts the user to input a command
    void menu();    

    // Prompts the user to input reservation information for today or tomorrow
    void submit(LinkedList* day_list);  

    // Displays the pickup information of the next reservation that needs to be fulfilled,
    // and removes the reservation from the reservation list
    void pickup_next();                 

    // Displays the pickup information of all unfulfilled reservations in the reservation 
    // list that was passed (either today's or tomorrow's reservation list)
    void list_res(LinkedList* day_list);

    // If today's list is empty, tomorrow's list gets saved into a .txt, and the program terminates
    void terminate();

    // Reads reservation data that has been stored into a .txt, and uses the data to populate
    // the reservation list for today
    int load_reservations();

    // Retrieves the data from tomorrow's reservation list, and writes it into a .txt file
    int save_reservations();

    // Prompts the user for an input character
    char get_char();
    
    // Prompts the user to select today's reservation list or tomorrow's reservation list
    LinkedList* get_list();
    
    // Prompts the user to input an integer that is within a range
    int get_time(int high, int low);
    
    // Prompts the user for an integer input
    int get_int()throw(std::string);
    
    // Prompts the user to input a non-empty string
    std::string get_string();
};