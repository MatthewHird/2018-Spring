//********************************************************************
//
// File: image.h
// Author: Matthew Hird
// Date: January 26, 2018
// Updated: January 26, 2018, January 27, 2018, February 4, 2018
//      February 5, 2018
//
// Purpose: a brief description of what's in the file
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
    int size;           // Equals rows * cols
    int * img_array;    // Pointer to an array that contains the pixel values of a greyscale image
    
public:
    Image();                        // Default constructor
    Image(string in_title, int in_row, int in_col, int * in_array); //Parametered constructor
    Image(const Image &old);        // Copy constructor
    ~Image();                       // Destructor
    
    // Overload + operator. Returns Image object whose img_array values are the average
    // of the corresponding index's value of the img_array for both operands.  
    Image operator+(const Image& other) throw(string &);    
    
    // Overload = operator. The Image object on the left side is assigned a deep copy of the 
    // Image object on the right side.
    void operator=(const Image& other);
    
    // Overload == operator. Checks whether the rows, cols, size, and img_array of the two Images 
    // contain the same values. Returns true if all of those fields are the same. Otherwise false.
    bool operator==(const Image& other);    
    
    // Overload != operator. Checks whether the rows, cols, size, and img_array of the two Images 
    // contain the same values. Returns false if all of those fields are the same. Otherwise true.
    bool operator!=(const Image& other);
    
    // Overload << operator. Outputs Image object.
    friend ostream& operator<<(ostream& ostr, const Image& img);   
    
    // Overload >> operator. Allows user to input Image object.
    friend istream& operator>>(istream& istr, Image& img);  
    
    void histogram(int n);  // Runs a histogram on the Image and outputs the results
    int get_rows();         // Returns the number of rows in Image
    int get_cols();         // Returns the number of cols in Image
    int get_size();         // Returns the size of Image (rows * cols)
};