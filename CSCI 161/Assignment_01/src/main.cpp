//********************************************************************
// File: main.cpp
// Author: Matthew Hird
// Date: January 15, 2018
// Updated: January 21, 2018
//
// Purpose: Contains main function loop. Creates a ReservationSystem
//     class object called resSys. Calls resSys.menu() to access the
//     reservation system menu. When resSys.menu() returns, the 
//     program exits.
//
// Notes: optional - any additional notes on the use of the file
//
// References: optional - a list of related reference materials
//********************************************************************

#include "../include/main.h"


int main()
{
    ReservationSystem resSys;
    
    resSys.menu();
    
	return 0;
}
