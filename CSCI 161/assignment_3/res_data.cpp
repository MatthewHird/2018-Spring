//********************************************************************
// File: res_data.cpp
// Author: Matthew Hird
// Date: February 6, 2018
// Updated: February 12, 2018
//
// Purpose: Stores taxi reservation data. Methods can return the 
// pickup time stored as well as output the stored data to screen. 
//********************************************************************

#include "res_data.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Constructor takes in taxi reservation data as parameters and stores the valus in private member variables.
ResData::ResData(int hr, int min, string loc, string nam){
    hour = hr;
    minute = min;
    time = 100 * hour + minute;
    location = loc;
    name = nam;
}

ResData::~ResData()             // Destructor
{}

int ResData::get_time(){        // Returns pickup time as a 4 digit integer (e.g. 1:30 = 0130)
    return time;
}

string ResData::display_time(){
    ostringstream oss;
    oss << hour << ":" << minute;
    return oss.str();
}

/*void ResData::out_display(){    // Outputs stored data to the screen
    cout << "     Pickup time: " << clock_time << endl
         << " Pickup location: " << location << endl
         << "    Contact name: " << name << endl
         << "-------------------------------------------------------" << endl;
}*/

ostream& operator<<(ostream& ostr, const ResData& data){
    
}
    
istream& operator>>(istream& istr, ResData& data){
        
}
