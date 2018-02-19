//********************************************************************
// File: res_data.h
// Author: Matthew Hird
// Date: February 6, 2018
// Updated: February 12, 2018, February 16, 2018, February 17, 2018
//
// Purpose: Stores taxi reservation data. Methods can return the 
// pickup time stored as well as output the stored data to screen. 
//********************************************************************

#pragma once
#include <fstream>
#include <iostream>


class ResData
{
private:
    int hour;
    int minute;
    int time;
    std::string location;
    std::string name;

    
public:
    ResData();
    ResData(int hr, int min, const std::string& loc, const std::string& nam);
    ResData(const ResData& old);
    ~ResData();
    
    int get_time(); 
    std::string display_data();
    
    friend std::ostream& operator<<(std::ostream& ostr, const ResData* data);   
    friend std::istream& operator>>(std::istream& istr, ResData* data);  
};