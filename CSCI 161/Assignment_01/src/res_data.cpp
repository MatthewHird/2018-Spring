//********************************************************************
// File: res_data.cpp
// Author: Matthew Hird
// Date: January 19, 2018
// Updated: January 20, 2018, January 21, 2018
//
// Purpose: a brief description of what's in the file
//
// Notes: optional - any additional notes on the use of the file
//
// References: optional - a list of related reference materials
//********************************************************************

#include "../include/res_data.h"

ResData::ResData()
{}

ResData::~ResData()
{}

void ResData::in_time(string hr, string min){
    time = (hr[0] - '0') * 1000 + (hr[1] - '0') * 100 + (min[0] - '0') * 10 + min[1] - '0';
    clock_time = hr + ":" + min;
}

void ResData::in_location(string loc){
    location = loc;
}

void ResData::in_name(string nam){
    name = nam;
}
    
void ResData::out_display(){
    
}