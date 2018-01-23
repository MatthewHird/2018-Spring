//********************************************************************
// File: main.cpp
// Author: Matthew Hird
// Date: January 15, 2018
// Updated: January 22, 2018
//
// Purpose: Contains main function loop. Creates a ReservationSystem
//     class object called resSys. Calls resSys.menu() to access the
//     reservation system menu. When resSys.menu() returns, the 
//     program exits.
//********************************************************************

#include "../include/main.h"


int main()
{
    ReservationSystem resSys;  //  Class object that contains the control logic
    
    resSys.menu();      // Starts the program menu

	return 0;
}
