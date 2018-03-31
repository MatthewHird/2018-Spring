#pragma once
#include <iostream>
#include "dictionary.h"

class TechDict
{
public:
    TechDict();
    ~TechDict();

    void run();

private:
    void menu();
    void load();
    void save();

    Dictionary dave;
};