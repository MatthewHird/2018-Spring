//------------------------------------------------------------------------------
// @file       country_data.cpp
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      A data object that contains various pieces of information on a 
//             specific country. The information fields are country name, 
//             capital city, languages, area, population, and description. 
//             Each field can be set or retrieved through various public 
//             methods. Additionally, the istream >> operator and ostream << 
//             operator are overloaded to save and load CountryData information
//             fields from a .txt file or std::string object.
//------------------------------------------------------------------------------

#include <iostream>
#include "country_data.h"


CountryData::CountryData()
    : area(-1)
    , population(-1)
{}


CountryData::CountryData(std::string c_name)
    : area(-1)
    , population(-1)
{
    name = c_name;
}


CountryData::CountryData(const CountryData& other)
{
    name = other.name;
    capital = other.capital;
    language = other.language;
    area = other.area;
    population = other.population;
    description = other.description;
}


CountryData::~CountryData()
{}


/**
 * Each line read is streamed into a member variable. Each entry must be on it's
 * own line. std::string variables can contain spaces or can be left entirely 
 * blank (but still needs its own line). Double and long int fields can not 
 * contain any spaces and may not be left blank. A value of "-1" denotes that
 * no information exists and the field should be treated as blank.
 */
std::istream& operator>>(std::istream& istr, CountryData& data)
{
    getline(istr, data.name);
    getline(istr, data.capital);
    getline(istr, data.language);
    istr >> data.area;
    istr.ignore();
    istr >> data.population;
    istr.ignore();
    getline(istr, data.description);
    return istr;
}


/**
 * Each member variable is printed onto a new line. Empty std::string variables
 * are stored as "". Blank double and long integer variables are stored as "-1".
 */
std::ostream& operator<<(std::ostream& ostr, const CountryData& data)
{
    ostr << data.name << "\n"
         << data.capital << "\n"
         << data.language << "\n"
         << data.area << "\n"
         << data.population << "\n"
         << data.description << "\n";
    return ostr;
}


void CountryData::set_name(std::string c_name)
{
    name = c_name;
}


void CountryData::set_capital(std::string cap)
{
    capital = cap;
}


void CountryData::set_language(std::string lang)
{
    language = lang;
}


void CountryData::set_area(double c_area)
{
    area = c_area;
}


void CountryData::set_population(long int pop)
{
    population = pop;
}


void CountryData::set_description(std::string descript)
{
    description = descript;
}


std::string CountryData::get_name() const
{
    return name;
}


std::string CountryData::get_capital() const
{
    return capital;
}


std::string CountryData::get_language() const
{
    return language;
}


double CountryData::get_area() const
{
    return area;
}


long int CountryData::get_population() const
{
    return population;
}


std::string CountryData::get_description() const
{
    return description;
}