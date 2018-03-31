//------------------------------------------------------------------------------
// @file       country_data.h
// @author     Matthew Hird
// @date       April 1, 2018
//
// @brief      The main function for the program pex5.
//------------------------------------------------------------------------------

#pragma once
#include <iostream>


class CountryData
{
public:
    CountryData();
    CountryData(std::string c_name);
    CountryData(const CountryData& other);
    ~CountryData();

    friend std::istream& operator>>(std::istream& istr, CountryData& data);
    friend std::ostream& operator<<(std::ostream& ostr, const CountryData& data);

    void set_name(std::string c_name);
    void set_capital(std::string cap);
    void set_language(std::string lang);
    void set_area(double c_area);
    void set_population(long int pop);
    void set_description(std::string descript);

    std::string get_name() const;
    std::string get_capital() const;
    std::string get_language() const;
    double get_area() const;
    long int get_population() const;
    std::string get_description() const;

private:
    std::string name;
    std::string capital;
    std::string language;
    double area;
    long population;
    std::string description;
};