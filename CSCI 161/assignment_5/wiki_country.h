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


class WikiCountry
{
public:
    WikiCountry();
    ~WikiCountry();

    void run();

private:
    void menu();
    void show();
    void list();
    void remove();
    void add();
    void update();
    void terminate();

    int load_wiki();
    int save_wiki();

    bool get_confirmation();
    long int get_long_int();
    double get_double();
    std::string get_string(bool blank_ok=true);

    int term;
    std::string wiki_save;
    Dictionary<CountryData> countries;
    Dictionary<int> command_keys;

    int ZERO = 0;
    int ONE = 1;
    int TWO = 2;
    int THREE = 3;
    int FOUR = 4;
    int FIVE = 5;
    int SIX = 6;
    int SEVEN = 7;
};