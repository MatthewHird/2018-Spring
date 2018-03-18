//------------------------------------------------------------------------------
// @file       browser_sim.h
// @author     Matthew Hird
// @date       March 17, 2018
//
// @brief      The main business logic for pex4. The BrowserSim class emulates
//             some functionality of a web browser app through the use of 
//             various command. "click <url>" will change the current web page
//             to <url>. "back" will change the current web page to a previous
//             web page visited, moving backwards one step. "forward" will 
//             change the current web page to a previous web page visited, 
//             moving forward one step. "exit" will terminate the program. 
//------------------------------------------------------------------------------

#pragma once
#include <iostream>     
#include <vector>
#include <map>
#include "stack.h"


class BrowserSim
{
public:
    /**
     * @brief      Default constructor.
     */
    BrowserSim();

    

    /**
     * @brief      Destructor.
     */
    ~BrowserSim();


    /**
     * @brief      Public access start point of the BrowserSim program. Sets the
     *             initial URL. Then calls the BrowserSim::menu() method.
     *
     * @param      start_url  Used as the initial URL to set current_url. 
     */
    void run(char* start_url);

    
private:
    /**
     * @brief      Main controller method. Prompts user for input commands and
     *             performs the appropriate actions.
     */
    void menu();


    /**
     * @brief      Gets an input string from the user and, using spaces as
     *             seperators, parses the string into individual words 
     *             (i.e. a command and arguments).
     *
     * @return     Each word parsed from the input string stored in order in an
     *             std::vector. Index 0 is the command; other indices are
     *             arguments.
     */
    std::vector<std::string> get_command();
    

    /**
     * @brief      Creates a map with the valid commands for BrowserSim as keys
     *             linked to specific integers. Used to turn input commands into
     *             integers to be compared to the cases of the switch in menu().
     *
     * @return     The command map.
     *             "click" = 1
     *             "back" = 2
     *             "forward" = 3
     *             "exit" = 4  
     */
    std::map<std::string, int> get_cmd_map();

    Stack<std::string> last;
    Stack<std::string> next;
    std::string current_url;
};