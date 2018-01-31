//********************************************************************
// File: reservation_system.cpp
// Author: Matthew Hird
// Date: January 15, 2018
// Updated: January 22, 2018
//
// Purpose: Using a menu and prompts, reservation data can be submitted 
//      and stored, and stored reservation data can be output to the user
//********************************************************************

#include "../include/reservation_system.h"
#include <iostream>
#include <sstream>
using namespace std;

ReservationSystem::ReservationSystem(){
    term = false;                       // Constructor sets term (terminate) to false
    res_fulfill_count = 0;              // and starts a counter of reservations processed
}

ReservationSystem::~ReservationSystem() // Destructor
{}

// Menu method outputs a welcome message and menu options, and prompts the user to input 
// a command (upper or lower case are both valid).  A switch statement decides what method
// should be called. If the input is invalid, the user is informed and prompted to try again.
void ReservationSystem::menu(){
    char sel;
    
    cout << "~~~~ Welcome to the Taxi Reservation System ~~~~" << endl << endl;
    
    while (term == false){
        cout << endl << "Please enter a key listed below:" << endl << endl
        << "     S to submit a new reservation request" << endl
        << "     P to pickup passengers with the earliest pickup time" << endl
        << "     L to list all unfulfilled reservations" << endl
        << "     T to terminate this program (if reservation list is empty)" << endl
        << endl << "---------------------------------------------------------------" << endl
        << ">>>  ";
        
        cin.get(sel);                   // Takes in user input
        getline(cin, garbage);          // Takes in garbage input generated by cin.get()

        sel = toupper(sel);             // Turns selected input into uppercase

        switch (sel){                   // Calls method based on input value
            case 'S':
                this->submit();
                break;
                
            case 'P':
                this->pickup_next();
                break;
                
            case 'L':
                this->list();
                break;
                
            case 'T':
                this->terminate();
                break;
            
            default:
                cout << endl << "Invalid entry: Please try again" << endl;
                break;
        }

    }
}

// Submit method prompts user to input reservation pickup time (hour and minute) as integers,
// the pickup location as a string, and the contact name as a string. Invalid inputs will 
// prompt the user to try again until a valid input is returned. Once all fields are entered,
// a ResData class constructor is called with the user data given as parameters. The ResData
// object is then sent to the linked list to be stored. Then the reservation counter tick up
// by one.
void ReservationSystem::submit(){
    int bad_input;

    // Prompts the user for a valid pickup hour. If an invalid input is entered, a message
    // is returned, bad_input is set to true, setting off the do/while loop until a valid
    // input is entered.
    cout << "Please enter the hour of the pickup time in 24 hour time" <<endl;
    do{
        bad_input = false;              // bad_input is reset to false
        cout << ">>>  ";
    
        getline(cin, pickup_hour);      // User input is taken

        switch (pickup_hour.length()) { // Switch checks the length of the input string
            case 0:                     
                bad_input = true;       // If string is empty, bad_input is set to true  
                break;
                
            case 1:
                pickup_hour.insert(0, "0"); // If the string is length one, a "0" is inserted
                                            // at the front, so the (valid) hour will always 
                                            // be two digits. Doesn't break so case 2 will happen.
            
            // Checks if char 0 is between ascii '0' and '2'. Then checks char 1. If char 0 was '0'
            // or '1', then char 1 must be between '0' and '9'. If char 0 was '2', char 1 must be 
            // between '0' and '3'.
            case 2:
                if (pickup_hour.at(0) < '0' || pickup_hour.at(0) > '2') {
                        bad_input = true;
                } else if (pickup_hour.at(0) >= '0' && pickup_hour.at(0) <= '1'){
                    if (pickup_hour.at(1) < '0' || pickup_hour.at(1) > '9') {
                        bad_input = true;
                    }
                } else if (pickup_hour.at(0) == '2'){
                    if (pickup_hour.at(1) < '0' || pickup_hour.at(1) > '3') {
                        bad_input = true;
                    }
                }
                break;
            
            default:        // If the hour input is more than two digits, it is always invalid
                bad_input = true;
                break;
        }
        if (bad_input == true){
            cout << "Pickup hour must be in the range 0 and 23" << endl;
        }
    } while (bad_input == true);    // An invalid input sets bad_input to true, returning to the 
                                    // top of the do/while loop.
    
    
    // Prompts the user for a valid pickup minute. If an invalid input is entered, a message
    // is returned, bad_input is set to true, setting off the do/while loop until a valid
    // input is entered.
    cout << "Please enter the minute of the pickup time" << endl;
    
    do{
        bad_input = false;                  // bad_input is reset to false
        cout << ">>>  ";
        
        getline(cin, pickup_minute);        // User input is taken

        switch (pickup_minute.length()) {   // Switch checks the length of the input string
            case 0:
                bad_input = true;           // If string is empty, bad_input is set to true 
                break;
                
            case 1:
                pickup_minute.insert(0, "0");   // If the string is length one, a "0" is inserted
                                                // at the front, so the (valid) hour will always 
                                                // be two digits. Doesn't break so case 2 will happen.
            
            // Checks if char 0 is between ascii '0' and '5'. Then checks if char 1 is between '0' and '9'.
            case 2:
                if (pickup_minute.at(0) < '0' || pickup_minute.at(0) > '5') {
                    bad_input = true;
                } else if (pickup_minute.at(1) < '0' || pickup_minute.at(1) > '9') {
                    bad_input = true;
                }
                
                break;
            
            default:        // If the minute input is more than two digits, it is always invalid
                bad_input = true;
                break;
        }
        if (bad_input == true){
            cout << "Pickup minute must be in the range 0 and 59" << endl;
        }
    } while (bad_input == true);    // An invalid input sets bad_input to true, returning to the 
                                    // top of the do/while loop.
    
    
    cout << "Please enter the pickup location" << endl;
    // Prompts user for a valid pickup location. An empty input string will prompt the user to try again.
    do{
        bad_input = false;                  // bad_input reset to false
        cout << ">>>  ";
        
        getline(cin, pickup_location);      // User input is taken

        switch (pickup_location.length()) {
            case 0:                         // An empty string set bad_input to true
                bad_input = true;
                cout << "Location field may not be left blank" << endl;
                break;
                
            default:
                break;
        }
    } while (bad_input == true);    // An invalid input returns to the top of the do/while loop
    
    cout << "Please enter the name of the contact" << endl;
    // Prompts user for a valid contact name. An empty input string will prompt the user to try again.
    do{
        bad_input = false;                  // bad_input reset to false
        cout << ">>>  ";
        
        getline(cin, pickup_name);          // User input is taken

        switch (pickup_name.length()) {
            case 0:                         // An empty string set bad_input to true
                bad_input = true;
                cout << "Contact name may not be left blank" << endl;
                break;
                
            default:
                break;
        }
    } while (bad_input == true);    // An invalid input returns to the top of the do/while loop
    
    // Declares a new ResData pointer and points it at a newly instantiated ResData object generated 
    // in the heap. The ResData constructor takes the four inputs that were entered by the user as
    // parameters and stores that data.
    ResData * data = new ResData(pickup_hour, pickup_minute, pickup_location, pickup_name);
    
    resList.insert_chronologically(data);   // Sends the data to the linked list to be stored 
    res_fulfill_count++;                    // Reservation fulfillment counter tick up by one
}

// If any unfulfilled reservations are left in the linked list, the reservation data of the earliest
// reservation is output to the user. Then removed from the list. Otherwise, a message is returned 
// stating the list is empty.
void ReservationSystem::pickup_next(){
    if (resList.does_exist() == true) {
        cout << "-------------------------------------------------------" << endl;
        
        resList.pop_front();    // Calls the pop_front method of the linked list
        
        cout << "The reservation information has been passed to a driver" << endl;
    } else if (resList.does_exist() == false) {
        cout << endl<< "No more reservations left in reservation list" << endl;
    }
}

// If any unfilfilled reservations are left in the linked list, then, in chronological order, the 
// reservation data of each is displayed. The the number of remaining unfulfilled reservations is
// output. Otherwise, a message is returned stating the list is empty.
void ReservationSystem::list(){
    if (resList.does_exist() == true) {
        cout << "-------------------------------------------------------" << endl;
        
        resList.lookup_all() ;  // Cals the lookup_all method of the linked list
        
        cout << resList.get_node_count() << " unfulfilled reservation(s) left in reservation list" << endl;
    } else if (resList.does_exist() == false) {
        cout << endl<< "No more reservations left in reservation list" << endl;
    }
}

// If any unfilfilled reservations are left in the linked list, the number of unfulfilled reservations is
// output and the program continues. If the list is empty, the number of reservations processed during the
// program operation is output, and the prgram terminates.
void ReservationSystem::terminate(){
    if (resList.does_exist() == true) {
        cout << endl<< resList.get_node_count() << " unfulfilled reservation(s) left in reservation list" << endl;
    } else if (resList.does_exist() == false) {
        term = true;
        cout << endl << "Total number of reservations received and processed: " << res_fulfill_count << endl 
        << endl << "~~~~ Thank-you for using the Taxi Reservation System ~~~~" << endl;
    }
}