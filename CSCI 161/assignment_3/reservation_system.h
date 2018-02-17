//********************************************************************
// File: reservation_system.h
// Author: Matthew Hird
// Date: February 11, 2018
// Updated: February 12, 2018, February 13, 2018, February 16, 2018,
//      February 17, 2018
//
// Purpose: Using a menu and prompts, reservation data can be submitted 
//      and stored, and stored reservation data can be output to the user 
//********************************************************************

#pragma once
#include <fstream>
#include <sstream>
#include "linked_list.h"
#include "res_data.h"
using namespace std;


class ReservationSystem
{
private:
	int term;
	int res_fulfill_count;
    string res_file;

	LinkedList todayList;
	LinkedList tomorrowList;

public:
    ReservationSystem();
    ~ReservationSystem();

    void menu();
    void submit(LinkedList * day_list);
    void pickup_next();
    void list_res(LinkedList * day_list);
    void terminate();

    int load_reservations();
    int save_reservations();

    char get_char();
    LinkedList * get_list();
    int get_time(int high, int low);
    int get_int()throw(string);
    string get_string();
};