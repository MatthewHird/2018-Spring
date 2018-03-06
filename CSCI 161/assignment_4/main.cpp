//------------------------------------------------------------------------------
// @file main.cpp
// @author     Matthew Hird
// @date       March 5, 2018
//
// @brief      
//------------------------------------------------------------------------------

#include <iostream>
#include "browser_sim.h"


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "\n"
                  << "Invlaid arguments:\n"
                  << "pex4 takes a single URL as its only argument\n"
                  << "\n";
    }
    else
    {
        BrowserSim browser;
        browser.run(argv[1]);
    }

    return 0;
}