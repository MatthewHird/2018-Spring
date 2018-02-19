//********************************************************************
// File: res_data.cpp
// Author: Matthew Hird
// Date: February 6, 2018
// Updated: February 12, 2018, February 16, 2018, February 17, 2018
//
// Purpose: Stores taxi reservation data. Methods can return the 
// pickup time stored as well as output the stored data to screen. 
//********************************************************************

#include "res_data.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>


ResData::ResData()
    : hour(0)
    , minute(0)
    , time(0)
{}

ResData::ResData(int hr, int min, const std::string& loc, const std::string& nam)
    : hour(hr)
    , minute(min)
{
    time = 100 * hour + minute;
    location = loc;
    name = nam;
}

ResData::ResData(const ResData& old){
    hour = old.hour;
    minute = old.minute;
    time = old.time;
    location = old.location;
    name = old.name;
}

ResData::~ResData()
{}

int ResData::get_time(){        // Returns pickup time as a 4 digit integer (e.g. 1:30 = 0130)
    return time;
}

std::string ResData::display_data(){
    std::ostringstream oss;
    oss << "     Pickup time: " << std::setfill('0') << std::setw(2) << hour << ":" 
                                << std::setfill('0') << std::setw(2) << minute << std::endl
        << " Pickup location: " << location << std::endl
        << "    Contact name: " << name << std::endl
        << "---------------------------------------------------------------" << std::endl;
    
    return oss.str();
}

std::ostream& operator<<(std::ostream& ostr, const ResData* data){
    ostr << data->hour << " " << data->minute << std::endl << data->location << std::endl 
         << data->name << std::endl;
    return ostr;
}
    
std::istream& operator>>(std::istream& istr, ResData* data){
    istr >> data->hour; 
    istr.ignore();
    istr >> data->minute;
    istr.ignore();
    getline(istr, data->location); 
    getline(istr, data->name);
    data->time = 100 * data->hour + data->minute;
    return istr;
}