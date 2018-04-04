//------------------------------------------------------------------------------
// @file       wiki_country.cpp
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The main business logic for pex5. Allows user to interact with a 
//             dictionary that uses country names as keys that are paired with
//             various fields of information on each country. The user can 
//             display information on a country, add a new country to the 
//             system, update information on any country currently in the 
//             system, or remove an country and all associated information from
//             the system. All information in the system gets saved to a .txt
//             file when the program terminates, and all information in the .txt
//             file gets added to the system the next time the systems runs.
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <exception>
#include <cmath>
#include <sstream>
#include <algorithm>
#include "wiki_country.h"
#include "dictionary.h"
#include "country_data.h"
#include "my_exceptions.h"


/**
 * Adds key/value pairs, of types std::string and int respectively, to a 
 * Dictionary called command_keys. The keys are unique commands, and the values
 * are unique integers. command_keys is used to convert user input strings into
 * into integers that match the cases of the switch in menu(). 
 */
WikiCountry::WikiCountry()
    : term(false)
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
        << " update   Update any information about a country\n"
        << " help     Shows list of commands\n"
        << " exit     Terminates the program\n"
        << "\n" 
        << "------------------------------------------------------------------\n";
        
        try
        {
             std::string command = get_string(true);
             std::transform(command.begin(), command.end(), command.begin(), tolower);
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
                show();
                break;
                
            case 3: // remove
                remove();
                break;
                
            case 4: // add
                add();
                break;
                
            case 5: // update
                update();
                break;

            case 6: // help
                std::cout << "\n";
                break;

            case 7: // exit
                terminate();
                break;
            
            default:
                std::cout << "\nInvalid entry: Please try again\n\n";
                break;
        }
    }
}


void WikiCountry::list()
{
    std::stringstream sstr;
    sstr << countries.get_key_list();
    int count = countries.get_size();

    std::cout << "\nNames of countries in system:\n\n";

    for (int i = 0; i < count; i++)
    {
        std::string c_name;
        getline(sstr, c_name);
        std::cout << " " << c_name << "\n";
    }

    std::cout << "\n";
}


void WikiCountry::show()
{
    std::cout << "Please enter the name of the country whose information you would like to see\n";
    std::string c_name = get_string(true);
    
    if (countries.has_key(c_name))
    {
        const CountryData& data = countries.lookup(c_name);
        
        std::cout << "\nName: " << c_name << "\n"; 

        if (data.get_capital() != "")
        {
            std::cout << "Capital: " << data.get_capital() << "\n";
        }

        if (data.get_language() != "")
        {
            std::cout << "Languages: " << data.get_language() << "\n";
        }

        if (data.get_area() != -1)
        {
            std::cout << "Area: " << data.get_area() << " square kilometers\n";
        }
         if (data.get_population() != -1)
        {
            std::cout << "Population: " << data.get_population() << "\n";
        }

        if (data.get_description() != "")
        {
            std::cout << "Description: " << data.get_description() << "\n";
        }
    }
    else
    {
        std::cout << "\nCountry is not in system\n";
    }

    std::cout << "\n";
}


void WikiCountry::remove()
{
    std::cout << "Please enter the name of the country whose information you would like to remove\n";
    std::string c_name = get_string(true);

    if (countries.has_key(c_name) == false)
    {
        std::cout << "\nCountry was not in system\n\n";
        return;
    }

    const CountryData* data = &(countries.remove(c_name));
    delete data;
    std::cout << "\n" << c_name << " has been removed from the system\n\n";
}


void WikiCountry::add()
{
    std::cout << "Please enter the name of the country you would like to add to the system\n";
    std::string c_name = get_string(false);
    
    if (countries.has_key(c_name))
    {
        std::cout << "\nCountry already in system\n\n";
        return;
    }

    CountryData& data = *(new CountryData(c_name));
    
    std::cout << "Please enter the capital city of this country\n";
    data.set_capital(get_string(true));
    
    std::cout << "Please enter the official language or languages of this country\n";
    data.set_language(get_string(true));
    
    std::cout << "Please enter the area of this country in square kilometers\n";
    double area = get_double();
    while (area == -2)
    {
        std::cout << "Entry must be a double float value\n";
        area = get_double();
    }
    data.set_area(area);

    std::cout << "Please enter the population of this country\n";
    long int pop = get_long_int();
    while (pop == -2)
    {
        std::cout << "Entry must be a positive integer\n";
        pop = get_long_int();
    }
    data.set_population(pop);

    std::cout << "Please enter a description or any other details about this country\n";
    data.set_description(get_string(true));

    try
    {
        countries.insert(c_name, data);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n" << c_name << " has been added to the system\n\n";
}


/**
 * Prompts user for the name of the country whose information they want to
 * update. If the country isn't in the system, a message is displayed and return
 * is called. Otherwise, creates a reference to a copy of the CountryData object
 * with the entered name. Each of the information fields can be updated,
 * including name. Then the old entry is removed from the dictionary and its
 * CountryData is deleted, and the new CountryData object is inserted into the
 * dictionary. The original entry isn't updated because the dictionary stores
 * CountryData as constant references, meaning none of its member variables may
 * be modified.
 */
void WikiCountry::update()
{
    std::cout << "Please enter the name of the country whose information you would like to update\n";
    std::string c_name = get_string(true);

    if (countries.has_key(c_name) == false)
    {
        std::cout << "\nCountry was not in system\n\n";
        return;
    }

    CountryData& new_data = *(new CountryData(countries.lookup(c_name)));
    
    std::cout << "Would you like to update the country's name field?\n";
    if (get_confirmation())
    {
        new_data.set_name(get_string(false));
    }

    std::cout << "Would you like to update the country's capital field?\n";
    if (get_confirmation())
    {
        new_data.set_capital(get_string(true));
    }

    std::cout << "Would you like to update the country's language field?\n";
    if (get_confirmation())
    {
        new_data.set_language(get_string(true));
    }

    std::cout << "Would you like to update the country's area field?\n";
    if (get_confirmation())
    {
        double area = get_double();
        while (area == -2)
        {
            std::cout << "Entry must be a double float value\n";
            area = get_double();
        }
        
        new_data.set_area(area);
    }

    std::cout << "Would you like to update the country's population field?\n";
    if (get_confirmation())
    {
        long int pop = get_long_int();
        while (pop == -2)
        {
            std::cout << "Entry must be a positive integer\n";
            pop = get_long_int();
        }

        new_data.set_population(pop);
    }

    std::cout << "Would you like to update the country's description field?\n";
    if (get_confirmation())
    {
        new_data.set_description(get_string(true));
    }

    try{
        const CountryData* old_data = &(countries.remove(c_name));
        delete old_data;
        countries.insert(new_data.get_name(), new_data);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    if (c_name == new_data.get_name())
    {
        std::cout << "\n" << c_name << " has successfully been updated\n\n";
    }
    else
    {
        std::cout << "\n" << new_data.get_name() << " (formerly " << c_name 
                  << ") has successfully been updated\n\n";
    }
}


void WikiCountry::terminate()
{
    save_wiki();
    term = true;
}


void WikiCountry::load_wiki()
{
    int entry_count;
    std::ifstream fin;

    fin.open(wiki_save.c_str());

    if (fin.fail()) 
    {
        return;
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
}


void WikiCountry::save_wiki()
{
    int entry_count = countries.get_size();
    std::ofstream fout;
    std::stringstream sstr;
    sstr << countries.get_key_list();
    
    fout.open(wiki_save.c_str());
    fout << entry_count << "\n";

    for (int i = 0; i < entry_count; i++ )
    {
        std::string c_name;
        getline(sstr, c_name);
        fout << countries.lookup(c_name);
    }

    fout.close();
}


bool WikiCountry::get_confirmation()
{
    char sel;
    
    do
    {
        std::cout << "Yes (Y) or No (N)\n"
                  << ">>>  ";
        std::cin.get(sel);                   
    
        if (sel != '\n') 
        {
            std::cin.ignore();
        }
        
        sel = toupper(sel);
    } while (sel != 'Y' && sel != 'N');
    
    if (sel == 'Y')
    {
        return true;
    }
    else if (sel == 'N')
    {
        return false;
    }
}


long int WikiCountry::get_long_int()
{
    std::string str_form;
    long int int_form = 0;
    
    std::cout << ">>>  ";
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
    
    std::cout << ">>>  ";
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


std::string WikiCountry::get_string(bool blank_ok)
{
    int bad_input;
    std::string str_in;

    do 
    {
        bad_input = false;
        
        std::cout << ">>>  ";
        std::getline(std::cin, str_in);
        
        if (blank_ok == false && str_in.length() == 0) 
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