//********************************************************************
//
// File: main.h
// Author: Matthew Hird
// Date: January 26, 2018
// Updated: January 26, 2018, January 27, 2018
//
// Purpose: Contains a main() function to test various methods of
//      Image class objects.
//
// Notes: optional - any additional notes on the use of the file
//
// References: optional - a list of related reference materials
//********************************************************************

#include "image.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    
    int * alf = new int [9];
    for (int i = 0; i < 9; i++){
        alf[i] = i + 1;
    }
    
        int * bard = new int [9];
    for (int i = 0; i < 9; i++){
        bard[i] = (i + 1) * 2;
    }

    string n_alf = "alf";
    string n_bard = "bard";
    
    Image img_1(n_alf, 3, 3, alf);
    Image img_2(n_bard, 3, 3, bard);
    try{
        Image img_3 = img_1 + img_2;
    }
    catch (...) {
        
    }
    
    Image img_4 = img_1;
    
    if (img_4 == img_1) {
        cout << "EQUAL" << endl;
    }
    if (img_1 == img_2) {
        
    }
    else {
        cout << "NOT EQUAL" << endl;
    }
    
    if (img_2 != img_1) {
        cout << "NOT EQUAL" << endl;
    }
    if (img_1 != img_4) {
        
    }
    else {
        cout << "EQUAL" << endl;
    }
    
    img_1.histogram(16);
    
    cout << endl << img_1;
    
    Image img_5;
    
    cin >> img_5;
    
    cout <<img_5;
    
    return 0;
}
