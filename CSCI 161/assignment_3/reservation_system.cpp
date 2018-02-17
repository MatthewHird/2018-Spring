//********************************************************************
// File: reservation_system.cpp
// Author: Matthew Hird
// Date: February 11, 2018
// Updated: February 12, 2018, February 13, 2018, February 15, 2018,
//		February 16, 2018, February 17, 2018
//
// Purpose: Using a menu and prompts, reservation data can be submitted 
//      and stored, and stored reservation data can be output to the user
//********************************************************************

#include "reservation_system.h"
#include <math.h>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;


ReservationSystem::ReservationSystem(){
    term = false;                       
    res_fulfill_count = 0;
    // res_file = "reservations.txt";
    res_file = "res-out-test.txt";
}              

ReservationSystem::~ReservationSystem() // Destructor
{}

// Menu method outputs a welcome message and menu options, and prompts the user to input 
// a command (upper or lower case are both valid).  A switch statement decides what method
// should be called. If the input is invalid, the user is informed and prompted to try again.
void ReservationSystem::menu(){
    char sel;

    cout << "~~~~ Welcome to the Taxi Reservation System ~~~~" << endl << endl; 
    
    int loaded_res_count = this->load_reservations();
    if (loaded_res_count == 0) {
       	cout << "No reservations were saved for today" << endl << endl;
    } else {
    	cout << "Number of reservations loaded from yesterday: " << loaded_res_count << endl << endl;
    }
    
    while (term == false){
        cout << "Please enter a key listed below:" << endl << endl
        << "     S to submit a new reservation request" << endl
        << "     P to pickup passengers with the earliest pickup time" << endl
        << "     L to list all unfulfilled reservations" << endl
        << "     T to terminate this program (if reservation list is empty)" << endl
        << endl << "---------------------------------------------------------------" << endl;
        
        sel = this->get_char();          
            
        switch (sel){                   
            case 'S':
            	cout << endl << "Is the reservation for today (D) or tomorrow (M)?" << endl ;
                this->submit(this->get_list());
                break;
                
            case 'P':
                this->pickup_next();
                break;
                
            case 'L':
                cout << endl << "Would you like to list the reservations for today (D) or tomorrow (M)?" << endl;
                this->list_res(this->get_list());
                break;
                
            case 'T':
                this->terminate();
                break;
            
            default:
                cout << endl << "Invalid entry: Please try again" << endl << endl;
                break;
        }
    }
}

void ReservationSystem::submit(LinkedList * day_list){

	cout << "Please enter the hour of the pickup time in 24 hour time" <<endl;
	int pickup_hour = this->get_time(0, 23);
	
	cout << "Please enter the minute of the pickup time" << endl;
	int pickup_minute = this->get_time(0, 59);

	cout << "Please enter the pickup location" << endl;
	string pickup_location = this->get_string();

	cout << "Please enter the name of the contact" << endl;
	string pickup_name = this->get_string();
	cout << endl;

	ResData * data = new ResData(pickup_hour, pickup_minute, pickup_location, pickup_name);

	day_list->push_chron(data);
}

void ReservationSystem::pickup_next(){
	if (todayList.get_node_count() <= 0) {
	    cout << endl << "No unfulfilled reservations left in list" << endl << endl;
	} 
	else {
		ResData * pickup = todayList.pop_front();
		cout << endl << pickup->display_data() << endl;
		res_fulfill_count++;
	}
}

void ReservationSystem::list_res(LinkedList * day_list){
	if (day_list->get_node_count() <= 0) {
	    cout << endl << "No unfulfilled reservations left in list" << endl << endl;
	} 
	else {
	    cout << endl << day_list->lookup_all() << endl;
	}
}

void ReservationSystem::terminate(){
	int count = todayList.get_node_count();
	if (count <= 0) {
		int saved_res_count = this->save_reservations();
		cout << endl 
			 << "Number of reservations fulfilled during this session: " << res_fulfill_count << endl
			 << "Number of reservations saved for tomorrow: " << saved_res_count << endl;
		term = true;
		return;
	} else if (count > 0) {
		cout << endl << "Program cannot terminate:" << endl 
			 << count << " unfulfilled reservations left in today's list" << endl << endl;
		return;
	}
}

int ReservationSystem::load_reservations(){
	ifstream fin;
	fin.open(res_file.c_str());
	if (fin.fail()) {
		return 0;
	}

	int entry_count;
	fin >> entry_count;

	for (int i = 0; i < entry_count; i++) {
		ResData * data = new ResData;
		fin >> data;
		todayList.push_chron(data);
	}
	fin.close();
	return entry_count;
}

int ReservationSystem::save_reservations(){
	int entry_count = tomorrowList.get_node_count();
	ofstream fout;
	fout.open(res_file.c_str());
		fout << entry_count << endl;
		for (int i = 0; i < entry_count; i++) {
			fout << tomorrowList.pop_front();
		}
	fout.close();
	return entry_count;

}

char ReservationSystem::get_char(){
	char sel;

    cout << ">>>  ";
    cin.get(sel);                   
    if (sel != '\n') {
    	cin.ignore();
    }
    sel = toupper(sel);
    return sel;  
}

LinkedList * ReservationSystem::get_list(){
	int bad_input = true;
	char sel;
	LinkedList * day_list;

	do {
		sel = this->get_char();

		switch (sel){
			case 'D':
				day_list = &todayList;
				return day_list;

			case 'M':
				day_list = &tomorrowList;
				return day_list;

			default:
				cout << "Entry must be either D for today or M for tomorrow" << endl;
				break;
		}
	} while(bad_input == true);
}

int ReservationSystem::get_time(int low, int high){
	int bad_input;
	int in_time;
	do {
		bad_input = false;
		cout << ">>>  ";
		try {
			in_time = this->get_int();
			
			if (in_time > high || in_time < low) {
				cout << "Input must be between " << low << " and " << high << endl;
				bad_input = true;
			}
		}
		catch (string e) {
			bad_input = true;
			cout << e << endl;
		}
	} while (bad_input == true);
	
	return in_time;
}

int ReservationSystem::get_int()throw(string){
	string str_form;
	int int_form = 0;
	getline(cin, str_form);
	if (str_form.length() == 0) {
		string e = "Input must not be left blank";
		throw e;
	}
	for (int i = str_form.length(); i > 0; i--) {
		if (str_form[i-1] > '9' || str_form[i-1] < '0') {
			string e = "Input must be a positive integer";
			throw e;
		}
		int_form += ((str_form[i-1] - '0') * pow(10, str_form.length() - i));
	}
	return int_form;
}

string ReservationSystem::get_string(){
	int bad_input;
	string str_in;

	do {
	bad_input = false;
	cout << ">>>  ";
	getline(cin, str_in);
		if (str_in.length() == 0) {
			bad_input = true;
			cout << "Input must not be left blank" << endl;
		}
	} while (bad_input == true);
	
	return str_in;
}