//********************************************************************
// File: res_data.h
// Author: Matthew Hird
// Date: January 19, 2018
// Updated: January 22, 2018
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
};