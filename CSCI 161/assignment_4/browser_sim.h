//------------------------------------------------------------------------------
// @file browser_sim.h
// @author     Matthew Hird
// @date       March 5, 2018
//
// @brief      
//------------------------------------------------------------------------------

#pragma once
#include <iostream>     
#include <vector>
#include <map>
#include "stack.h"


class BrowserSim
{
public:
    BrowserSim();
    ~BrowserSim();

    void run(char* start_url);
    void menu();

    std::vector<std::string> get_command();
    std::map<std::string, int> get_cmd_map();

private:
    Stack<std::string> last;
    Stack<std::string> next;
    std::string current_url;
};