#pragma once
#include <fstream>
#include "../include/linked_list.h"
using namespace std;

class ReservationSystem
{
private:
    int pickup_hour;
    int pickup_minute;
    string pickup_location;
    string pickup_name;
    
public:
    ReservationSystem();  // Constructor declaration
    ~ReservationSystem(); // Deconstructor declaration
    
    void menu();
    void submit();
    void pickup_next();
    void list();
    void terminate();
};