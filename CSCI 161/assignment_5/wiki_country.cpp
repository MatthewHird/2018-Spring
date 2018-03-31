//------------------------------------------------------------------------------
// @file       wiki_country.cpp
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The main function for the program pex5.
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <exception>
#include <cmath>
#include "wiki_country.h"
#include "dictionary.h"
#include "country_data.h"
#include "my_exceptions.h"
#include "str_key.h"


int ZERO = 0;
int ONE = 1;
int TWO = 2;
int THREE = 3;
int FOUR = 4;
int FIVE = 5;
int SIX = 6;
int SEVEN = 7;


WikiCountry::WikiCountry()
    : term(false)
    , wiki_save("wikiCountry.txt")
{
    command_keys.insert("list", ONE);
    command_keys.insert("show", TWO);
    command_keys.insert("remove", THREE);
    command_keys.insert("add", FOUR);
    command_keys.insert("update", FIVE);
    command_keys.insert("help", SIX);
    command_keys.insert("exit", SEVEN);
}


WikiCountry::~WikiCountry()
{}


void WikiCountry::run()
{
    std::cout << "\n~~~~ Welcome to WikiCountry ~~~~\n\n"; 
    load_wiki();
    menu();
}


void WikiCountry::menu()
{
    int sel;

    while (term == false)
    {
        std::cout 
        << "Please enter a command listed below:\n" 
        << "\n"
        << " list     List the name of all countries currently in the system\n"
        << " show     Show the full information of a country\n"
        << " remove   Remove a country and its entry from the system\n"
        << " add      Add a new country and entry to the system\n"
        << " update   Update any information about a country (except its name)\n"
        << " help     Shows list of commands\n"
        << " exit     Terminates the program\n"
        << "\n" 
        << "------------------------------------------------------------------\n";
        
        try
        {
             std::string command = get_string();
             sel = command_keys.lookup(command); 
      
        }
        catch (std::exception& e)
        {
            sel = ZERO;
        }

        switch (sel)
        {                   
            case 1: // list
                list();
                break;
                
            case 2: // show
                std::cout << "sho\n";
                break;
                
            case 3: // remove
                std::cout << "rem\n";
                break;
                
            case 4: // add
                std::cout << "ad\n";
                break;
                
            case 5: // update
                std::cout << "up\n";
                break;

            case 6: // help
                std::cout << "hel\n";
                break;

            case 7: // exit
                terminate();
                break;
            
            default:
                std::cout << "Invalid entry: Please try again\n\n";
                break;
        }
    }
}


void WikiCountry::list()
{
    std::cout << "\n" << countries.get_key_list() << "\n";
}


void WikiCountry::remove()
{

}


void WikiCountry::add()
{

}


void WikiCountry::update()
{

}


void WikiCountry::terminate()
{
    save_wiki();
    term = true;
}


int WikiCountry::load_wiki()
{
    int entry_count;
    std::ifstream fin;

    fin.open(wiki_save.c_str());

    if (fin.fail()) 
    {
        return 0;
    }

    fin >> entry_count;
    fin.ignore();

    for (int i = 0; i < entry_count; i++) 
    {
        CountryData& data = *(new CountryData);
        fin >> data;
        std::string key = data.get_name();

        try
        {
            countries.insert(key, data);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << "\n";
        }
    }
    fin.close();

    return entry_count;
}


int WikiCountry::save_wiki()
{
    int entry_count = countries.get_size();
    std::ofstream fout;
    
    fout.open("test_save.txt");
    fout << entry_count << std::endl;
    
    fout << countries.lookup("China");
    
    fout.close();
    return entry_count;
}


char WikiCountry::get_char()
{
    char sel;

    std::cout << ">>>  ";
    std::cin.get(sel);                   
    
    if (sel != '\n') 
    {
        std::cin.ignore();
    }
    
    sel = toupper(sel);
    return sel;  
}


long int WikiCountry::get_long_int()
{
    std::string str_form;
    long int int_form = 0;
    
    std::getline(std::cin, str_form);
    
    if (str_form.length() == 0) 
    {
        return -1;
    }
    
    for (int i = 0; i < str_form.length(); i++)
    {
        if (str_form[i] > '9' || str_form[i] < '0')
        {
            return -2;
        }
        int_form = int_form * 10;
        int_form += (str_form[i] - '0');
    }

    return int_form;
}


double WikiCountry::get_double()
{
    std::string str_form;
    double dbl_form = 0;
    int dec_point = false;
    int start_count = false;
    int count = 0;
    
    std::getline(std::cin, str_form);
    
    if (str_form.length() == 0) 
    {
        return -1;
    }

    for (int i = 0; i < str_form.length(); i++)
    {
        if (str_form[i] == '.')
        {
            if (dec_point == false)
            {
                dec_point = true;
                start_count = true;
            }
            else
            {
                return -2;
            }
        }
        else
        {
            if (str_form[i] > '9' || str_form[i] < '0')
            {
                return -2;
            }
            dbl_form = dbl_form * 10;
            dbl_form += (str_form[i] - '0');
            if (start_count == true)
            {
                count++;
            }
        }
    }

    dbl_form = dbl_form / (pow(10, count));
    return dbl_form;
}


std::string WikiCountry::get_string()
{
    int bad_input;
    std::string str_in;

    do 
    {
        bad_input = false;
        
        std::cout << ">>>  ";
        std::getline(std::cin, str_in);
        
        if (str_in.length() == 0) 
        {
            bad_input = true;
            std::cout << "Input must not be left blank\n";
        }
        else if (str_in.length() > 255)
        {
            bad_input = true;
            std::cout << "Input must be 255 characters or less\n";
        }
    } while (bad_input == true);

    return str_in;
}


std::string WikiCountry::get_cmd()
{

}