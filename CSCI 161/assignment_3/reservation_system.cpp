//********************************************************************
// File: reservation_system.cpp
// Author: Matthew Hird
// Date: February 11, 2018
// Updated: February 12, 2018, February 13, 2018, February 15, 2018,
//        February 16, 2018, February 17, 2018
//
// Purpose: Using a menu and prompts, reservation data can be submitted 
//      and stored, and stored reservation data can be output to the user
//********************************************************************

#include "reservation_system.h"
#include <math.h>
#include <iostream>
#include <sstream>
#include <fstream>


ReservationSystem::ReservationSystem(){
    term = false;                       
    res_fulfill_count = 0;
    // res_file = "reservations.txt";
    res_file = "res-out-test.txt";
}              

ReservationSystem::~ReservationSystem()
{}

void ReservationSystem::menu(){
    char sel;

    std::cout << "~~~~ Welcome to the Taxi Reservation System ~~~~" << std::endl << std::endl; 
    
    int loaded_res_count = this->load_reservations();
    if (loaded_res_count == 0) {
        std::cout << "No reservations were saved for today" << std::endl << std::endl;
    } else {
        std::cout << "Number of reservations loaded from yesterday: " << loaded_res_count << std::endl 
                  << std::endl;
    }
    
    while (term == false){
        std::cout 
        << "Please enter a key listed below:" << std::endl 
        << std::endl
        << "     S to submit a new reservation request" << std::endl
        << "     P to pickup passengers with the earliest pickup time" << std::endl
        << "     L to list all unfulfilled reservations" << std::endl
        << "     T to terminate this program (if reservation list is empty)" << std::endl
        << std::endl 
        << "---------------------------------------------------------------" << std::endl;
        
        sel = this->get_char();          
            
        switch (sel){                   
            case 'S':
                std::cout << std::endl 
                          << "Is the reservation for today (D) or tomorrow (M)?" << std::endl;
                this->submit(this->get_list());
                break;
                
            case 'P':
                this->pickup_next();
                break;
                
            case 'L':
                std::cout << std::endl 
                          << "Would you like to list the reservations for today (D) or tomorrow (M)?" << std::endl;
                this->list_res(this->get_list());
                break;
                
            case 'T':
                this->terminate();
                break;
            
            default:
                std::cout << std::endl 
                          << "Invalid entry: Please try again" << std::endl 
                          << std::endl;
                break;
        }
    }
}

void ReservationSystem::submit(LinkedList* day_list){

    std::cout << "Please enter the hour of the pickup time in 24 hour time" <<std::endl;
    int pickup_hour = this->get_time(0, 23);
    
    std::cout << "Please enter the minute of the pickup time" << std::endl;
    int pickup_minute = this->get_time(0, 59);

    std::cout << "Please enter the pickup location" << std::endl;
    std::string pickup_location = this->get_string();

    std::cout << "Please enter the name of the contact" << std::endl;
    std::string pickup_name = this->get_string();
    std::cout << std::endl;

    ResData* data = new ResData(pickup_hour, pickup_minute, pickup_location, pickup_name);

    day_list->push_chron(data);
}

void ReservationSystem::pickup_next(){
    if (todayList.get_node_count() <= 0) {
        std::cout << std::endl 
                  << "No unfulfilled reservations left in list" << std::endl << std::endl;
    } 
    else {
        ResData * pickup = todayList.pop_front();
        std::cout << std::endl << pickup->display_data() << std::endl;
        res_fulfill_count++;
    }
}

void ReservationSystem::list_res(LinkedList* day_list){
    if (day_list->get_node_count() <= 0) {
        std::cout << std::endl 
                  << "No unfulfilled reservations left in list" << std::endl 
                  << std::endl;
    } 
    else {
        std::cout << std::endl 
                  << day_list->lookup_all() << std::endl;
    }
}

void ReservationSystem::terminate(){
    int count = todayList.get_node_count();
    if (count <= 0) {
        int saved_res_count = this->save_reservations();
        std::cout << std::endl 
                  << "Number of reservations fulfilled during this session: " << res_fulfill_count << std::endl
                  << "Number of reservations saved for tomorrow: " << saved_res_count << std::endl;
        term = true;
        return;
    } else if (count > 0) {
        std::cout << std::endl 
                  << "Program cannot terminate:" << std::endl 
                  << count << " unfulfilled reservations left in today's list" << std::endl 
                  << std::endl;
        return;
    }
}

int ReservationSystem::load_reservations(){
    std::ifstream fin;
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
    std::ofstream fout;
    fout.open(res_file.c_str());
        fout << entry_count << std::endl;
        for (int i = 0; i < entry_count; i++) {
            fout << tomorrowList.pop_front();
        }
    fout.close();
    return entry_count;

}

char ReservationSystem::get_char(){
    char sel;

    std::cout << ">>>  ";
    std::cin.get(sel);                   
    if (sel != '\n') {
        std::cin.ignore();
    }
    sel = toupper(sel);
    return sel;  
}

LinkedList* ReservationSystem::get_list(){
    int bad_input = true;
    char sel;
    LinkedList* day_list;

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
                std::cout << "Entry must be either D for today or M for tomorrow" << std::endl;
                break;
        }
    } while(bad_input == true);
}

int ReservationSystem::get_time(int low, int high){
    int bad_input;
    int in_time;
    do {
        bad_input = false;
        std::cout << ">>>  ";
        try {
            in_time = this->get_int();
            
            if (in_time > high || in_time < low) {
                std::cout << "Input must be between " << low << " and " << high << std::endl;
                bad_input = true;
            }
        }
        catch (std::string e) {
            bad_input = true;
            std::cout << e << std::endl;
        }
    } while (bad_input == true);
    
    return in_time;
}

int ReservationSystem::get_int()throw(std::string){
    std::string str_form;
    int int_form = 0;
    std::getline(std::cin, str_form);
    if (str_form.length() == 0) {
        std::string e = "Input must not be left blank";
        throw e;
    }
    for (int i = str_form.length(); i > 0; i--) {
        if (str_form[i-1] > '9' || str_form[i-1] < '0') {
            std::string e = "Input must be a positive integer";
            throw e;
        }
        int_form += ((str_form[i-1] - '0') * pow(10, str_form.length() - i));
    }
    return int_form;
}

std::string ReservationSystem::get_string(){
    int bad_input;
    std::string str_in;

    do {
    bad_input = false;
    std::cout << ">>>  ";
    std::getline(std::cin, str_in);
        if (str_in.length() == 0) {
            bad_input = true;
            std::cout << "Input must not be left blank" << std::endl;
        }
    } while (bad_input == true);
    
    return str_in;
}