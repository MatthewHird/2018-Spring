//********************************************************************
//
// File: image.cpp
// Author: Matthew Hird
// Date: January 26, 2018
// Updated: January 26, 2018, January 27, 2018, January 29, 2018
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
    name = old.name;
    rows = old.rows;
    cols = old.cols;
    img_array = new int [rows * cols];
    
    for (int i = 0; i < (rows * cols); i++) {
        img_array[i] = old.img_array[i];
    }
    this->display_data();
}

Image::~Image(){
    delete img_array;
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
    this->name = other.name;
    this->rows = other.rows;
    this->cols = other.cols;
    this->img_array = new int [rows * cols];
    
    for (int i = 0; i < (rows * cols); i++) {
        this->img_array[i] = other.img_array[i];
    }
    this->display_data();
}

bool Image::operator==(const Image& other){
    if (this->rows != other.rows || this->cols != other.cols) {
        return 0;
    }
    for (int i = 0; i < this->rows * this->cols; i++) {
        if (this->img_array[i] != other.img_array[i]) {
            return 0;
        }
    }
    return 1;
}

bool Image::operator!=(const Image& other){
    if (this->rows != other.rows || this->cols != other.cols) {
        return 1;
    }
    for (int i = 0; i < this->rows * this->cols; i++) {
        if (this->img_array[i] != other.img_array[i]) {
            return 1;
        }
    }
    return 0;
}
    
ostream &operator<<(ostream& ostr, const Image& img){
    ostr << "Name: " << img.name << endl;
    ostr << "Rows: " << img.rows << "  Cols: " << img.cols << endl << endl; 
    
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            ostr << img.img_array[img.cols * i + j] << " ";
        }
        ostr << endl;
    }
    ostr << endl;
    return ostr;
}

istream &operator>>(istream& istr, Image& img){
    cout << "Name >>> ";
    istr >> img.name;
    cout << "Rows >>> ";
    istr >> img.rows;
    cout << "Cols >>> ";
    istr>> img.cols;

    img.img_array = new int[img.rows * img.cols];
    for (int i = 0; i < img.rows * img.cols; i++) {
        cout << "R" << i / img.cols + 1 << "C" << i % img.cols + 1 << " >>> ";
        istr >> img.img_array[i];
    }
    cout << endl;
    
    return istr;
}
    
void Image::histogram(int n){
    int hist_count;
    cout << "HISTOGRAM: " << name << endl << endl;
    for (int i = 0; i < n; i++) {
        hist_count = 0;
        for (int j = 0; j < rows * cols; j++) {
            if (img_array[j] >= i  * (256 / n) && img_array[j] <= ((i + 1) * (256 / n)) - 1) {
                hist_count++;
            }
        }
        cout << i * (256 / n) << " to " << ((i + 1) * (256 / n)) - 1 << ": " << hist_count << endl;
    }
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
