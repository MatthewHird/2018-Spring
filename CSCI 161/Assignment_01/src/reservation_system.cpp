//********************************************************************
// File: reservation_system.cpp
// Author: Matthew Hird
// Date: January 15, 2018
// Updated: January 19, 2018
//
// Purpose: a brief description of what's in the file
//
// Notes: optional - any additional notes on the use of the file
//
// References: optional - a list of related reference materials
//********************************************************************

#include "../include/reservation_system.h"
#include <iostream>
#include <sstream>
using namespace std;

ReservationSystem::ReservationSystem()
{}

ReservationSystem::~ReservationSystem()
{}

void ReservationSystem::menu(){
    char sel = '0';
    cout << "~~~~ Welcome to the Taxi Reservation System ~~~~" << endl << endl;
    
    while (term == false){
        cout << endl << "Please enter a key listed below:" << endl << endl
        << "     S to submit a new reservation request" << endl
        << "     P to pickup passengers with the earliest pickup time" << endl
        << "     L to list all unfulfilled reservations" << endl
        << "     T to terminate this program (if reservation list is empty)" << endl
        << endl << "---------------------------------------------------------------" << endl
        << ">>>  ";
        
        cin.get(sel);
        
        getline(cin, garbage);

        sel = toupper(sel);

        switch (sel){
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
                break;
        }

    };
}

void ReservationSystem::submit(){
    int bad_input = false;

    
    cout << "Please enter the hour of the pickup time in 24 hour time" << endl
    << ">>>  ";
    do{
        bad_input = false;
    
        getline(cin, pickup_hour);
    
        if (pickup_hour.empty()) {
            cout << ">>>  ";
            bad_input = true;
        } else { 
            for(unsigned i = 0; i < pickup_hour.size(); i++) 
            {
                if (pickup_hour.at(i) < '0' || pickup_hour.at(i) > '9') {
                    cout << pickup_hour.at(i) << endl << ">>>  ";
                    bad_input = true;
                }
                if (bad_input == true) {
                    break;
                }
            }
            
            if (bad_input == true) {
                continue;
            }
            
            if(pickup_hour.length() > 2) {
                cout << "too long" << endl << ">>>  ";
                bad_input = true;
            } else {
                bad_input = false;
            }
        }
    } while (bad_input == true);
    
    
 /*   cout << "Please enter the minute of the pickup time" << endl
    << ">>>  ";
minute_in:
    cin >> pickup_minute;
    getline(cin, garbage);
    cout << isdigit (pickup_minute[0]);
    
    cout << "Please enter the minute of the pickup time" << endl
    << ">>>  ";
    */
}

void ReservationSystem::pickup_next(){
    
}

void ReservationSystem::list(){
    
}

void ReservationSystem::terminate(){
    term = true;
}