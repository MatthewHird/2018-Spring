//------------------------------------------------------------------------------
// @file       main.cpp
// @author     Matthew Hird
// @date       March 17, 2018
//
// @brief      The main function for the program pex4. Run the program in the
//             terminal as "pex4 <start_url>". Invalid arguments will output an 
//             error message and terminate the program. Otherwise, the program 
//             is passed off to the BrowserSim controller class.
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