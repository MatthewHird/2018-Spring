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
private:
    struct Data
    {
        std::string url;
    };
    
    Stack<Data> last;
    Stack<Data> next;
    std::string current_url;
    Data* cur_data;

public:
    BrowserSim();
    ~BrowserSim();

    void run(char* start_url);
    void menu();

    std::vector<std::string> get_command();
    std::map<std::string, int> get_cmd_map();
};