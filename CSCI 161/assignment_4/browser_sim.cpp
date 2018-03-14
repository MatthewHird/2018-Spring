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
        try
        {
            std::cout << "last: " << last.peek() << "\n";
        }
        catch (EmptyStack& e)
        {
            std::cout << "last: EMPTY" << "\n";
        }
        
        try
        {
            std::cout << "next: " << next.peek() << "\n";
        }
        catch (EmptyStack& e)
        {
            std::cout << "next: EMPTY" << "\n";
        }

        std::cout << "Current page: " << current_url << "\n"
                  << "command>>>  ";

        command = this->get_command();
        std::cout << "\n";

        try
        {
            switch (cmd_map[command[0]])
            {
                case 1: // "click"
                    if (command.size() != 2)
                    {
                        throw InvalidArguments();
                    }
                    last.push(current_url);
                    next.clear();
                    current_url = command[1];
                    break;

                case 2: // "back"
                    if (command.size() != 1)
                    {
                        throw InvalidArguments();
                    }

                    if (last.is_empty())
                    {
                        std::cout << "Cannot move back:\n"
                                  << "No previous page to load\n"
                                  << "\n";
                    }
                    else
                    {
                        next.push(current_url);
                        current_url = last.pop();
                    }
                    break;

                case 3: // "forward"
                    if (command.size() != 1)
                    {
                        throw InvalidArguments();
                    }

                    if (next.is_empty())
                    {
                        std::cout << "Cannot move forward:\n"
                                  << "No forward page to load\n"
                                  << "\n";
                    }
                    else
                    {
                        last.push(current_url);
                        current_url = next.pop();
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
                    throw InvalidArguments();
            }
        }
        catch (InvalidArguments& e)
        {
            std::cout << "error invalid arguments\n";
        }
        command.clear();
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


