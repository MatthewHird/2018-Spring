#pragma once

class ReservationSystem
{
private:
    int pickup_hour;
    int pickup_minute;
    char pickup_location;
    char pickup_name;
    
public:
    ReservationSystem();  // Constructor declaration
    
    void menu();
    void submit();
    void pickup_next();
    void list();
    void terminate();
}