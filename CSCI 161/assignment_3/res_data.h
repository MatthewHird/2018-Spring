//********************************************************************
// File: res_data.h
// Author: Matthew Hird
// Date: February 6, 2018
// Updated: February 12, 2018, February 16, 2018, February 17, 2018,
//      February 19, 2018
//
// Purpose: Stores taxi reservation data. Methods can return the 
//      pickup time stored in a comparable form, as well as return the 
//      stored data in a formatted form. Also, the i/o stream
//      operators have been overloaded to write stored data to a file
//      or to accept and store data in the same format. 
//********************************************************************

#pragma once
#include <fstream>
#include <iostream>


class ResData
{
private:
    int hour;
    int minute;
    int time;               // Pickup time stored as a 4 digit integer (e.g. 1:30 = 0130)
    std::string location;
    std::string name;

    
public:
    ResData();
    ResData(int hr, int min, const std::string& loc, const std::string& nam);
    ResData(const ResData& old);
    ~ResData();
    
    // Returns the time value
    int get_time(); 

    // Puts the data in a formatted form with headers and returns the information as a single string
    std::string display_data();
    
    // The ostream << operator is overloaded to write the ResData's constructor parameters
    // in a simple format.
    friend std::ostream& operator<<(std::ostream& ostr, const ResData* data);   
    
    // The istream >> operator is overloaded to stream in parameters in the same format that
    // ostream << outputs, and replaces the ResData's values with those values.
    friend std::istream& operator>>(std::istream& istr, ResData* data);  
};