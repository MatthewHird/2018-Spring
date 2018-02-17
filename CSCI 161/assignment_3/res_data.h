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
using namespace std;

class ResData
{
private:
    int hour;
    int minute;
    int time;
    string location;
    string name;

    
public:
    ResData();
    ResData(int hr, int min, string loc, string nam);
    ResData(const ResData& old);
    ~ResData();
    
    int get_time(); 
    string display_data();
    
    friend ostream& operator<<(ostream& ostr, const ResData * data);   
    friend istream& operator>>(istream& istr, ResData * data);  
};