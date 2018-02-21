//------------------------------------------------------------------------------
// @file main.cpp
// @author     Matthew Hird
// @date       February 18, 2018
//
// @brief      Contains main function loop. Creates a ReservationSystem class
//             object called resSys. Calls resSys.menu() to access the
//             reservation system menu. When resSys.menu() returns, the program
//             exits.
//------------------------------------------------------------------------------

#include "reservation_system.h"


int main()
{
    ReservationSystem resSys;
    
    resSys.menu();
    return 0;
}