//********************************************************************
// File: res_data.h
// Author: Matthew Hird
// Date: January 19, 2018
// Updated: 
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
    int hour;
    int minute;
    string location;
    string name;
    
public:
    ResData();   // Constructor declaration
    ~ResData();  // Deconstructor declaration
    
    void in_time();
    void in_location();
    void in_name();
    
    void out_display();
};