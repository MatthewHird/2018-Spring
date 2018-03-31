//------------------------------------------------------------------------------
// @file       wiki_country.h
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The main function for the program pex5.
//------------------------------------------------------------------------------

#pragma once
#include <iostream>
#include "dictionary.h"
#include "country_data.h"
#include "str_key.h"


class WikiCountry
{
public:
    WikiCountry();
    ~WikiCountry();

    void run();

private:
    void menu();
    void list();
    void remove();
    void add();
    void update();
    void terminate();

    int load_wiki();
    int save_wiki();

    char get_char();
    long int get_long_int();
    double get_double();
    std::string get_string();
    std::string get_cmd();

    int term;
    std::string wiki_save;
    Dictionary<CountryData> countries;
    Dictionary<int> command_keys;
};