//********************************************************************
// File: reservation_system.cpp
// Author: Matthew Hird
// Date: January 15, 2018
// Updated: January 22, 2018
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

ReservationSystem::ReservationSystem(){
    term = false;
    res_fulfill_count = 0;
}

ReservationSystem::~ReservationSystem()
{}

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

    }
}

void ReservationSystem::submit(){
    int bad_input = false;

    
    cout << "Please enter the hour of the pickup time in 24 hour time" <<endl;
    do{
        bad_input = false;
        cout << ">>>  ";
    
        getline(cin, pickup_hour);

        switch (pickup_hour.length()) {
            case 0:
                bad_input = true;
                break;
                
            case 1:
                pickup_hour.insert(0, "0");
            
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
            
            default:
                bad_input = true;
                break;
        }
        if (bad_input == true){
            cout << "Pickup hour must be in the range 0 and 23" << endl;
        }
    } while (bad_input == true);
    
    
    cout << "Please enter the minute of the pickup time" << endl;
    
    do{
        bad_input = false;
        cout << ">>>  ";
        
        getline(cin, pickup_minute);

        switch (pickup_minute.length()) {
            case 0:
                bad_input = true;
                break;
                
            case 1:
                pickup_minute.insert(0, "0");
            
            case 2:
                if (pickup_minute.at(0) < '0' || pickup_minute.at(0) > '5') {
                    bad_input = true;
                } else if (pickup_minute.at(1) < '0' || pickup_minute.at(1) > '9') {
                    bad_input = true;
                }
                
                break;
            
            default:
                bad_input = true;
                break;
        }
        if (bad_input == true){
            cout << "Pickup minute must be in the range 0 and 59" << endl;
        }
    } while (bad_input == true);
    
    cout << "Please enter the pickup location" << endl;
    
    do{
        bad_input = false;
        cout << ">>>  ";
        
        getline(cin, pickup_location);

        switch (pickup_location.length()) {
            case 0:
                bad_input = true;
                cout << "Location field may not be left blank" << endl;
                break;
                
            default:
                break;
        }
    } while (bad_input == true);
    
    cout << "Please enter the name of the contact" << endl;
    
    do{
        bad_input = false;
        cout << ">>>  ";
        
        getline(cin, pickup_name);

        switch (pickup_name.length()) {
            case 0:
                bad_input = true;
                cout << "Contact name may not be left blank" << endl;
                break;
                
            default:
                break;
        }
    } while (bad_input == true);
    
    ResData * data = new ResData(pickup_hour, pickup_minute, pickup_location, pickup_name);
    
    resList.insert_chronologically(data);
    res_fulfill_count++;    
}

void ReservationSystem::pickup_next(){
    if (resList.does_exist() == true) {
        cout << "-------------------------------------------------------" << endl;
        resList.pop_front();
        cout << "The reservation information has been passed to a driver" << endl;
    } else if (resList.does_exist() == false) {
        cout << endl<< "No more reservations left in reservation list" << endl;
    }
}

void ReservationSystem::list(){
    if (resList.does_exist() == true) {
        cout << "-------------------------------------------------------" << endl;
        resList.lookup_all() ;
        cout << resList.get_node_count() << " unfulfilled reservation(s) left in reservation list" << endl;
    } else if (resList.does_exist() == false) {
        cout << endl<< "No more reservations left in reservation list" << endl;
    }
}

void ReservationSystem::terminate(){
    if (resList.does_exist() == true) {
        cout << endl<< resList.get_node_count() << " unfulfilled reservation(s) left in reservation list" << endl;
    } else if (resList.does_exist() == false) {
        term = true;
        cout << endl << "Total number of reservations received and processed: " << res_fulfill_count << endl 
        << endl << "~~~~ Thank-you for using the Taxi Reservation System ~~~~" << endl;
    }
}