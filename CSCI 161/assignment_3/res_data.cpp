//------------------------------------------------------------------------------
// @file : res_data.cpp
// @author     Matthew Hird
// @date       February 20, 2018
//
// @brief      Stores taxi reservation data. Methods can return the pickup time
//             stored in a comparable form, as well as return the stored data in
//             a formatted form. Also, the i/o stream operators have been
//             overloaded to write stored data to a file or to accept and store
//             data in the same format.
//------------------------------------------------------------------------------

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

ResData::ResData(const ResData& old)
{
    hour = old.hour;
    minute = old.minute;
    time = old.time;
    location = old.location;
    name = old.name;
}

ResData::~ResData()
{}

int ResData::get_time()     
{        
    return time;
}

// Formats data in a human readable form with headers for context
std::string ResData::display_data()
{
    std::ostringstream oss;

    oss << "     Pickup time: " << std::setfill('0') << std::setw(2) << hour << ":" 
                                << std::setfill('0') << std::setw(2) << minute << std::endl
        << " Pickup location: " << location << std::endl
        << "    Contact name: " << name << std::endl
        << "---------------------------------------------------------------" << std::endl;
    
    return oss.str();
}

// Streams out the data in the form:      Example:
//
//  hour minute\n                           23 59
//  location\n                              123 Place Street
//  name\n                                  Mr Client
//                                 
std::ostream& operator<<(std::ostream& ostr, const ResData* data)
{
    ostr << data->hour << " " << data->minute << std::endl << data->location << std::endl 
         << data->name << std::endl;
    return ostr;
}

// Takes data in the form listed above, and streams the values into the appropriate
// member variables of the ResData object   
std::istream& operator>>(std::istream& istr, ResData* data)
{
    istr >> data->hour; 
    istr.ignore();
    istr >> data->minute;
    istr.ignore();
    getline(istr, data->location); 
    getline(istr, data->name);
    data->time = 100 * data->hour + data->minute;
    return istr;
}