//------------------------------------------------------------------------------
// @file browser_sim.cpp
// @author     Matthew Hird
// @date       March 5, 2018
//
// @brief      
//------------------------------------------------------------------------------

#include "browser_sim.h"
#include "stack.h"
#include "my_exceptions.h"
#include <iostream>
#include <map>


BrowserSim::BrowserSim()
{

}


BrowserSim::~BrowserSim()
{

}


void BrowserSim::run(char* start_url)
{
    Stack last;
    Stack next;
    current_url = start_url;

    this->menu();
}


void BrowserSim::menu()
{
    std::map<std::string, int> cmd_map = this->get_cmd_map();
    int term = false;
    std::vector<std::string> command;
    
    while (term == false)
    {
        std::cout << current_url << "\n"
                  << "command>>>  ";

        command = this->get_command();
        std::cout << command[0] << "\n";

        try
        {
            switch (cmd_map[command[0]])
            {
                case 1: // "click"
                    if (command.size() != 2)
                    {
                        throw InvalidArguments();
                    }

                    std::cout << command[1] << "\n";

                    break;

                case 2: // "back"
                    if (command.size() != 1)
                    {
                        throw InvalidArguments();
                    }

                    break;

                case 3: // "forward"
                    if (command.size() != 1)
                    {
                        throw InvalidArguments();
                    }

                    break;

                case 4: // "exit"
                    if (command.size() != 1)
                    {
                        throw InvalidArguments();
                    }
                    
                    term = true;  
                    break;

                default:
                    std::cout << "dancing puppies\n";
                    break;
            }
        }
        catch (InvalidArguments& e)
        {
            std::cout << "error invalid arguments\n";
        }
    }
}


std::vector<std::string> BrowserSim::get_command()
{
    std::vector<std::string> command;
    std::string user_string;
    std::string argument;
    std::getline(std::cin, user_string);

    for (int i = 0; i < user_string.length(); i++)
    {
        char c = user_string[i];
        if (c == ' ')
        {
            if (argument.empty() == false)
            {
                command.push_back(argument);
                argument.clear();
            }
        }
        else 
        {
            argument += tolower(c);
        }
    }
    
    command.push_back(argument);   

    return command;
}


std::map<std::string, int> BrowserSim::get_cmd_map()
{
    std::map<std::string, int> cmd_map;
    
    cmd_map["click"] = 1;
    cmd_map["back"] = 2;
    cmd_map["forward"] = 3;
    cmd_map["exit"] = 4;

    return cmd_map;
}


