//********************************************************************
// File: res_data.h
// Author: Matthew Hird
// Date: January 19, 2018
// Updated: January 22, 2018
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
    int time;

    
public:
    ResData(string hr, string min, string loc, string nam);   // Constructor declaration
    ~ResData();  // Deconstructor declaration
    
    int get_time();
    void out_display();
};