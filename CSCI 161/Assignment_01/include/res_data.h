#pragma once
#include <fstream>
using namespace std;

class ResData
{
private:
    int hour;
    int minute;
    string location;
    string name;
    
public:
    ResData();   // Constructor declaration
    ~ResData();  // Deconstructor declaration
    
    void in_time();
    void in_location();
    void in_name();
    
    void out_display();
};