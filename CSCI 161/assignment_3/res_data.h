//********************************************************************
// File: res_data.h
// Author: Matthew Hird
// Date: February 6, 2018
// Updated: 
//
// Purpose: Stores taxi reservation data. Methods can return the 
// pickup time stored as well as output the stored data to screen. 
//********************************************************************

#pragma once
#include <fstream>
using namespace std;

class ResData
{
private:
    string clock_time;
    string location;
    string name;
    int time;

    
public:
    ResData(string hr, string min, string loc, string nam);   // Constructor declaration
    ~ResData();  // Destructor declaration
    
    int get_time();         // Returns pickup time as a 4 digit integer (e.g. 1:30 = 0130) 
    void out_display();     // Outputs stored data to the screen
    
    friend ostream& operator<<(ostream& ostr, const ResData& data);   
    
    friend istream& operator>>(istream& istr, ResData& data);  
};
};