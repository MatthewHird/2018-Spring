//------------------------------------------------------------------------------
// @file       wiki_country.cpp
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The main function for the program pex5.
//------------------------------------------------------------------------------

#include <iostream>
#include "wiki_country.h"
#include "dictionary.h"
#include "country_data.h"
#include "my_exceptions.h"


WikiCountry::WikiCountry()
{}


WikiCountry::~WikiCountry()
{}


void WikiCountry::run()
{

}


void WikiCountry::menu()
{

}


void WikiCountry::list()
{

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


void WikiCountry::exit()
{

}


void WikiCountry::load_wiki()
{

}


void WikiCountry::save_wiki()
{

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
        std::string e = "Input must not be left blank";
        throw e;
    }
    
    // for (int i = str_form.length(); i > 0; i--) 
    // {
    //     if (str_form[i-1] > '9' || str_form[i-1] < '0') 
    //     {
    //         std::string e = "Input must be a positive integer";
    //         throw e;
    //     }
    //     int_form = int_form * 10;
    //     int_form += ((str_form[i-1] - '0') * pow(10, str_form.length() - i));
    // }
    
    return int_form;
}


double WikiCountry::get_double()
{

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
    } while (bad_input == true);
    
    return str_in;
}