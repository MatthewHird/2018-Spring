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
    /**
     * @brief      Default constructor.
     */
    WikiCountry();

    
    /**
     * @brief      Destructor.
     */
    ~WikiCountry();


    /**
     * @brief      Public start method of WikiCountry. Loads .txt save file,
     *             adding all saved information to the dictionary system, and
     *             calls the menu method.
     */
    void run();


private:
    /**
     * @brief      Central control method of WikiCountry. Displays command menu,
     *             prompts user for commands, interprets the commands, and calls
     *             other methods as necessary.
     */
    void menu();
    

    /**
     * @brief      Lists of the names of all countries currently in the system.
     */
    void list();
    

    /**
     * @brief      Prompts user for the name of a country in the system and
     *             displays all data stored with that country.
     */
    void show();
    

    /**
     * @brief      Prompts user for the name of a country in the system and
     *             removes the country and all associated data from the system.
     */
    void remove();
    

    /**
     * @brief      Prompts the user to enter the name of a new country to add to
     *             the system. Then prompts the user to enter information about
     *             the country in various set fields.
     */
    void add();
    

    /**
     * @brief      Prompts the user for the name of a country in the system.
     *             Then allows the user to update any data fields associated
     *             with that country (including country name).
     */
    void update();
    

    /**
     * @brief      Saves each country name in the system, and all data fields
     *             associated with each country, in a .txt file to be loaded
     *             into the system on next startup. Then terminates the program.
     */
    void terminate();

    
    /**
     * @brief      Reads the .txt save file, extracts the stored data entries,
     *             and adds them to the dictionary system.
     */
    void load_wiki();
    
    
    /**
     * @brief      Retrieves all of the countries and associated data from the
     *             system, and writes the data into a .txt save file.
     */
    void save_wiki();

    
    /**
     * @brief      Prompts the user to enter 'Y' for yes or 'N' for no. Will
     *             prompt user again if input is invalid.
     *
     * @return     True if 'Y' was entered, False if 'N' was entered.
     */
    bool get_confirmation();
    

    /**
     * @brief      Prompts user for a positive integer value.
     *
     * @return     User integer input. -1 if input is blank. -2 if input is
     *             invalid.
     */
    long int get_long_int();
    

    /**
     * @brief      Prompts user for a positive double value.
     *
     * @return     User double input. -1 if input is blank. -2 if input is
     *             invalid.
     */
    double get_double();
    

    /**
     * @brief      Prompts user for std::string input. Reprompts user if entry
     *             is more then 255 characters long.
     *
     * @param[in]  blank_ok  If true, the user may input an empty string. If
     *                       false, entering an empty string will result in the
     *                       user being reprompted for a non-empty string input.
     *
     * @return     User input string.
     */
    std::string get_string(bool blank_ok=true);

    
    int term;
    std::string wiki_save = "wikiCountry.txt";
    Dictionary<CountryData> countries;
    Dictionary<int> command_keys;
    
    const int ZERO = 0;
    const int ONE = 1;
    const int TWO = 2;
    const int THREE = 3;
    const int FOUR = 4;
    const int FIVE = 5;
    const int SIX = 6;
    const int SEVEN = 7;
};