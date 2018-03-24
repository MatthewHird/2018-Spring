//------------------------------------------------------------------------------
// @file       country_data.cpp
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The main function for the program pex5.
//------------------------------------------------------------------------------

#include <iostream>
#include "country_data.h"


CountryData::CountryData()
    : area(0)
    , population(0)
{}


CountryData::CountryData(std::string c_name)
    : area(0)
    , population(0)
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


std::string CountryData::get_name()
{
    return name;
}


std::string CountryData::get_capital()
{
    return capital;
}


std::string CountryData::get_language()
{
    return language;
}


double CountryData::get_area()
{
    return area;
}


long int CountryData::get_population()
{
    return population;
}


std::string CountryData::get_description()
{
    return description;
}