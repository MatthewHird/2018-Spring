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


class BrowserSim
{
private:
    std::string current_url;

public:
    BrowserSim();
    ~BrowserSim();

    void run(char* start_url);
    void menu();

    std::vector<std::string> get_command();
    std::map<std::string, int> get_cmd_map();
};