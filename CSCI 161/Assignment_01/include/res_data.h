//********************************************************************
// File: res_data.h
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

#pragma once
#include <fstream>
using namespace std;

class ResData
{
private:
    string clock_time;
    string location;
    string name;
    
public:
    ResData();   // Constructor declaration
    ~ResData();  // Deconstructor declaration
    
    int time;
    void in_time(string hr, string min);
    void in_location(string loc);
    void in_name(string nam);
    
    void out_display();
};