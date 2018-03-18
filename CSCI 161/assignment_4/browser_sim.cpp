//------------------------------------------------------------------------------
// @file       browser_sim.cpp
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

#include "browser_sim.h"
#include "stack.h"
#include "my_exceptions.h"
#include <iostream>
#include <map>


BrowserSim::BrowserSim()
{}


BrowserSim::~BrowserSim()
{}


void BrowserSim::run(char* start_url)
{
    current_url = start_url;
    menu();
}



/**
 * Menu loops until the terminate command "exit" is given. Prompts user for
 * input command, then calls get_command() to retrieve and parse the command. A
 * switch decides what actions to take based on the command. Two stacks, "last"
 * and "next", are used to keep track of previously visited urls. If the command
 * arguments are invalid, an exception is thrown and caught, and an error
 * message is displayed.
 */
void BrowserSim::menu()
{
    std::map<std::string, int> cmd_map = get_cmd_map();
    int term = false;
    std::vector<std::string> command;
    
    while (term == false)
    {
        std::cout << "Current page: " << current_url << "\n"
                  << "command>>>  ";

        command = get_command();
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
            std::cout << e.what() << "\n";
        }
        
        command.clear();
    }
}


/**
 * Takes in input string from the user. If the string is empty, puts an error
 * message at index 0 of the std::vector command, and returns command. The error
 * message will be interpreted as an invalid command by the menu switch.
 * Otherwise, the input string gets parsed character by character, dividing the
 * string into words seperated by spaces. The words are stored as strings in
 * command in the same order they were in the input string.
 */
std::vector<std::string> BrowserSim::get_command()
{
    std::vector<std::string> command;
    std::string user_string;
    std::string argument;
    
    std::getline(std::cin, user_string);

    if (user_string.length() == 0)
    {
        command.push_back("No command entered");
        return command;
    }

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
    
    if (argument.empty() == false)
    {
        command.push_back(argument);   
    }

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


