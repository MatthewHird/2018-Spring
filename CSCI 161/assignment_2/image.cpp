//********************************************************************
//
// File: image.cpp
// Author: Matthew Hird
// Date: January 26, 2018
// Updated: January 26, 2018, January 27, 2018, January 29, 2018
//      February 4, 2018, February 5, 2018
//
// Purpose: a brief description of what's in the file
//********************************************************************

#include "image.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// Default constructor
Image::Image(){     
    name = "";
    rows = 0;
    cols = 0;
    size = 0;
}

// Parametered constructor
Image::Image(string in_title, int in_row, int in_col, int * in_array){  
    name = in_title;
    rows = in_row;
    cols = in_col;
    size = rows * cols;
    img_array = new int [size];

    for (int i = 0; i < (size); i++) {
        img_array[i] = in_array[i];
    }
}

// Copy constructor. Called when an Image object is being instantiated and assigned 
// values using the '=' operator. example: Image img_new = img_old;
Image::Image(const Image &old){     
    name = old.name;
    rows = old.rows;
    cols = old.cols;
    size = old.size;
    img_array = new int [size];
    
    for (int i = 0; i < (size); i++) {
        img_array[i] = old.img_array[i];
    }
}

// Destructor
Image::~Image(){        
    delete []img_array;
}

// Overload + operator. If the number of rows or columns are different between the two
// operand Images, a string will be thrown stating "Incompatible size". Otherwise, an 
// Image object is returned whose name is the names of each operand seperated by " + ".
// The new object's img_array values at each index are the average of the two operands'
// values at the corresponding index.
Image Image::operator+(const Image& other) throw(string &){
    if (rows != other.rows || cols != other.cols){
        string e = "Incompatible size";
        throw e;
    }
    string sum_name = name + " + " + other.name;
    int * sum_array = new int[(size)];
    for (int i = 0; i < (size); i++) {
        sum_array[i] = (img_array[i] + other.img_array[i]) / 2;
    }
        
    Image sum(sum_name, rows, cols, sum_array);
        
    return sum;
}

// Overload = operator. The Image object on the left side is assigned a deep copy of the 
// Image object on the right side.
void Image::operator=(const Image& other){
    if (size != 0) {
        delete []img_array;
    }
    name = other.name;
    rows = other.rows;
    cols = other.cols;
    size = other.size;
    
    img_array = new int [size];
    
    for (int i = 0; i < (size); i++) {
        img_array[i] = other.img_array[i];
    }
}

// Overload == operator. Checks whether the rows, cols, size, and img_array of the two Images 
// contain the same values. Returns true if all of those fields are the same. Otherwise false.
bool Image::operator==(const Image& other){
    if (rows != other.rows || cols != other.cols || size != other.size) {
        return 0;
    }
    for (int i = 0; i < size; i++) {
        if (img_array[i] != other.img_array[i]) {
            return 0;
        }
    }
    return 1;
}

// Overload != operator. Checks whether the rows, cols, size, and img_array of the two Images 
// contain the same values. Returns false if all of those fields are the same. Otherwise true.
bool Image::operator!=(const Image& other){
    if (rows != other.rows || cols != other.cols) {
        return 1;
    }
    for (int i = 0; i < size; i++) {
        if (img_array[i] != other.img_array[i]) {
            return 1;
        }
    }
    return 0;
}

// Overload << operator between an ostream and Image object. Returns an ostream object that 
// includes the Image's name, rows, cols, and img_array formatted as a table, all preceded
// by approriate headers.    
ostream &operator<<(ostream& ostr, const Image& img){
    ostr << "TITLE: " << img.name << endl;
    ostr << "SIZE: " << img.rows << " by " << img.cols << endl;
    ostr << "CONTENT: " << endl; 
    
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            ostr << setw(3) << img.img_array[img.cols * i + j] << " ";
        }
        ostr << endl;
    }
    ostr << endl;
    return ostr;
}

// Overload >> operator between an istream and Image object. Prompts using to input name, 
// rows, cols, and each value of img_array, then returns an istream object. 
istream &operator>>(istream& istr, Image& img){
    cout << "Title >>> ";
    getline(cin, img.name);
    cout << "Rows >>> ";
    istr >> img.rows;
    cout << "Cols >>> ";
    istr >> img.cols;

    img.img_array = new int[img.rows * img.cols];
    for (int i = 0; i < img.rows * img.cols; i++) {
        cout << "R" << i / img.cols + 1 << "C" << i % img.cols + 1 << " >>> ";
        istr >> img.img_array[i];
    }
    cout << endl;
    
    return istr;
}

// Runs a histogram on the Image and outputs the results    
void Image::histogram(int n){
    int hist_count;
    cout << endl << "HISTOGRAM: " << name << endl << endl;
    for (int i = 0; i < n; i++) {
        hist_count = 0;
        for (int j = 0; j < size; j++) {
            if (img_array[j] >= i  * (256 / n) && img_array[j] <= ((i + 1) * (256 / n)) - 1) {
                hist_count++;
            }
        }
        cout << setw(3) << i * (256 / n) << " to " << setw(3) << ((i + 1) * (256 / n)) - 1 
        << ": " << hist_count << endl;
    }
    cout << endl;
}

int Image::get_rows(){  // Returns the number of rows in Image
    return rows;
}

int Image::get_cols(){  // Returns the number of cols in Image
    return cols;
}

int Image::get_size(){  // Returns the size of Image
    return size;
}
