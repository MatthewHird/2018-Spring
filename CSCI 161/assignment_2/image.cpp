//********************************************************************
//
// File: image.cpp
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

#include "image.h"
#include <fstream>
#include <iostream>
#include <exception>
using namespace std;

struct WrongSize : public exception {
   const char * what () const throw () {
      return "Incompatible size";
   }
};

Image::Image(){
    name = "";
    rows = 0;
    cols = 0;

}

Image::Image(string in_title, int in_row, int in_col, int * in_array){
    name = in_title;
    rows = in_row;
    cols = in_col;
    img_array = new int [rows * cols];

    for (int i = 0; i < (rows * cols); i++) {
        img_array[i] = in_array[i];
    }
    this->display_data();
}

Image::Image(const Image &old){
    
}

Image::~Image(){
    
}

Image Image::operator+(const Image& other){
    try {
        if (this->rows != other.rows || this->cols != other.cols){
            throw WrongSize();
        }
        string sum_name = this->name + " + " + other.name;
        int * sum_array = new int[(this->rows * this->cols)];
        for (int i = 0; i < (this->rows * this->cols); i++) {
            sum_array[i] = (this->img_array[i] + other.img_array[i]) / 2;
        }
        
        Image sum(sum_name, this->rows, this->cols, sum_array);
        
        return sum;
    }
    catch(WrongSize& e) {
        cout << "Exception raised: " << e.what() << endl;
        throw WrongSize();
    }
}
    
void Image::operator=(const Image& other){
    
}

bool Image::operator==(const Image& other){
    
}
    
ostream &operator<<(ostream& ostr, const Image& img){
    
}

istream &operator>>(istream& istr, Image& img){
    
}
    
void Image::histogram(int n){
    
}

int Image::get_rows(){
    return rows;
}

int Image::get_cols(){
    return cols;
}

void Image::display_data(){
    cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << img_array[cols * i + j] << " ";
        }
        cout << endl;
    }
}
