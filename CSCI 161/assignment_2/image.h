//********************************************************************
//
// File: image.h
// Author: Matthew Hird
// Date: January 26, 2018
// Updated: January 26, 2018
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

class Image
{
private:
    string name;
    int rows;
    int cols;
    int * img_array;
    
public:
    Image();                        // Default constructor
    Image(string in_title, int in_row, int in_col, int * in_array); //Parametered constructor
    Image(const Image &old);        // Copy constructor
    ~Image();                       // Destructor
    
    Image operator+(const Image& other);      // Overload + operator
    void operator=(const Image& other);      // Overload = operator
    bool operator==(const Image& other);     // Overload == operator
    
    friend ostream& operator<<(ostream& ostr, const Image& img);   // Output Image objects
    friend istream& operator>>(istream& istr, Image& img);   // Input Image object
    
    void histogram(int n);
    int get_rows();
    int get_cols();
    void display_data();
};