//********************************************************************
// File: res_data.cpp
// Author: Matthew Hird
// Date: February 6, 2018
// Updated: 
//
// Purpose: Stores taxi reservation data. Methods can return the 
// pickup time stored as well as output the stored data to screen. 
//********************************************************************

#include "res_data.h"
#include <iostream>
#include <fstream>
using namespace std;

// Constructor takes in taxi reservation data as parameters and stores the valus in private member variables.
ResData::ResData(string hr, string min, string loc, string nam){
    time = (hr[0] - '0') * 1000 + (hr[1] - '0') * 100 + (min[0] - '0') * 10 + min[1] - '0';
    clock_time = hr + ":" + min;
    location = loc;
    name = nam;
    }

ResData::~ResData()             // Destructor
{}

int ResData::get_time(){        // Returns pickup time as a 4 digit integer (e.g. 1:30 = 0130)
    return time;
}

void ResData::out_display(){    // Outputs stored data to the screen
    cout << "     Pickup time: " << clock_time << endl
         << " Pickup location: " << location << endl
         << "    Contact name: " << name << endl
         << "-------------------------------------------------------" << endl;
}

ostream& operator<<(ostream& ostr, const ResData& data){
    
}
    
istream& operator>>(istream& istr, ResData& data){
        
}
