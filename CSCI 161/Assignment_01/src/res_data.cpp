//********************************************************************
// File: res_data.cpp
// Author: Matthew Hird
// Date: January 19, 2018
// Updated: January 22, 2018
//
// Purpose: a brief description of what's in the file
//
// Notes: optional - any additional notes on the use of the file
//
// References: optional - a list of related reference materials
//********************************************************************

#include "../include/res_data.h"
#include <iostream>
using namespace std;

ResData::ResData(string hr, string min, string loc, string nam){
    time = (hr[0] - '0') * 1000 + (hr[1] - '0') * 100 + (min[0] - '0') * 10 + min[1] - '0';
    clock_time = hr + ":" + min;
    location = loc;
    name = nam;
    }

ResData::~ResData()
{}

int ResData::get_time(){
    return time;
}

void ResData::out_display(){
    cout << "     Pickup time: " << clock_time << endl
         << " Pickup location: " << location << endl
         << "    Contact name: " << name << endl
         << "-------------------------------------------------------" << endl;
}