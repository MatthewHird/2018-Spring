//********************************************************************
//
// File: main.h
// Author: Matthew Hird
// Date: January 26, 2018
// Updated: January 26, 2018, January 27, 2018, February 4, 2018
//      February 5, 2018
//
// Purpose: Contains a main() function to test various methods of
//      Image class objects.
//********************************************************************

#include "image.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    Image * img_0 = new Image;          // Tests default Image constructor
    cout << (*img_0) << endl;           
    
    delete img_0;                       // Tests Image destructor
    
    string n_alf = "alf";               
    int * alf = new int [9];
    for (int i = 0; i < 9; i++) {
        alf[i] = i + 1;
    }
    
    string n_bard = "bard";
    int * bard; 
    int b_array[9] = {221, 34, 166, 7, 89, 45, 33, 244, 15};
    bard = b_array;
    
    string n_cat = "cat";
    int * cat = new int [16];
    for (int i = 0; i < 16; i++) {
        cat[i] = (i * i);
    }

    Image img_alf(n_alf, 3, 3, alf);        // Tests parametrized Image constructor
    Image img_bard(n_bard, 3, 3, bard);     // Same size as img_alf with different contents
    Image img_cat(n_cat, 4, 4, cat);        // Different size and content than other to Images
    
    Image img_1 = img_alf;                  // Tests Image copy constructor
    cout << endl << img_1;
    
    img_1 = img_cat;                        // Tests Image overloaded operator =
    cout << endl << img_1;
    
    try{
        Image img_2 = img_alf + img_bard;   // Tests Image overloaded operator +. Both operands
        cout << endl << img_2;              // have the same rows and cols values, so no exception
    }                                       // is thrown.
    catch (string & e) {
        cout << "Could not + images due to exception: " << e << endl;
    }
    
    try{
        Image img_2 = img_alf + img_cat;    // Tests Image overloaded operator +. The operands
        cout << endl << img_2;              // have different rows and cols values, so an
    }                                       // exception is thrown and caught.
    catch (string & e) {
        cout << "Could not + images due to exception: " << e << endl;
    }
    
    string n_dave = "Dave";                 // Creates an Image with the name "Dave", whose
    Image img_dave(n_dave, 3, 3, alf);      // contents are identical to alf
    
    // Tests Image overloaded operator == Returns true because content is the same, 
    // even though the name field is different.
    if (img_dave == img_alf) {
        cout << endl << "Dave equals alf" << endl << endl;
    } else {
        cout << endl << "Dave does not equal alf" << endl << endl;
    }
    
    // Tests == operator, returning false
    if (img_alf == img_bard) {
        cout << "alf equals bard" << endl << endl;
    } else {
        cout << "alf does not equal bard" << endl << endl;
    }
    
    // Tests Image overloaded operator != Returns false.
    if (img_cat != img_1) {
        cout << "cat does not equal img_1" << endl << endl;
    } else {
        cout << "cat equals img_1" << endl << endl;
    }
    
    // Tests != operator, returning true
    if (img_bard != img_cat) {
        cout << "bard does not equal cat" << endl << endl;
    }
    else {
        cout << "bard equals cat" << endl << endl;
    }
    
    cout << img_bard;
    img_bard.histogram(4);      // Tests histogram method
    
    Image img_3;    // Tests the overloaded operator >> that is a friend to Image
    cin >> img_3;   // Prompts user to input data and sets the Image's values to the inputs
    cout << img_3;  // Tests the overloaded operator << that is a friend to Image
    
    cout << "Please hit enter to exit program..." << endl;
    cin.get(); 
    cin.get();
    
    return 0;
}
