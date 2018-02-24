//------------------------------------------------------------------------------
// @file reservation_system.cpp
// @author     Matthew Hird
// @date       February 20, 2018
//
// @brief      Using a menu and prompts, reservation data can be submitted and
//             stored, and stored reservation data can be output to the user.
//             Reservations can be taken for today or tomorrow. All reservations
//             for tomorrow are stored in a .txt file when the program
//             terminates. When the program starts, all reservations stored in
//             the .txt file are saved into today's reservation list.
//------------------------------------------------------------------------------

#include "reservation_system.h"
#include <math.h>
#include <iostream>
#include <sstream>
#include <fstream>


/** 
 * Default class constructor 
 */
ReservationSystem::ReservationSystem()
    : term(false)                       
    , res_fulfill_count(0)
    // , res_file("reservations.txt")
    , res_file("res-out-test.txt")
{}              


/** 
 * Class destructor 
 */
ReservationSystem::~ReservationSystem()
{}


/** 
 * The main controller method for the program. When first called, the saved reservations are
 * loaded into today's reservation list. Then a while loop is entered that will loop until 
 * the terminate command is successfully run. The menu displays the command options available
 * and prompts the user to enter a command.
 */
void ReservationSystem::menu()
{
    char sel;

    std::cout << "~~~~ Welcome to the Taxi Reservation System ~~~~" << std::endl << std::endl; 
    
    int loaded_res_count = this->load_reservations();
    
    if (loaded_res_count == 0) 
    {
        std::cout << "No reservations were saved for today" << std::endl << std::endl;
    } 
    else 
    {
        std::cout << "Number of reservations loaded from yesterday: " << loaded_res_count << std::endl 
                  << std::endl;
    }
    
    while (term == false)
    {
        std::cout 
        << "Please enter a key listed below:" << std::endl 
        << std::endl
        << "     S to submit a new reservation request" << std::endl
        << "     P to pickup passengers with the earliest pickup time" << std::endl
        << "     L to list all unfulfilled reservations" << std::endl
        << "     T to terminate this program (if reservation list is empty)" << std::endl
        << std::endl 
        << "---------------------------------------------------------------" << std::endl;
        
        sel = this->get_char();          
            
        switch (sel)
        {                   
            case 'S':
                std::cout << std::endl 
                          << "Is the reservation for today (D) or tomorrow (M)?" << std::endl;
                this->submit(this->get_list());
                break;
                
            case 'P':
                this->pickup_next();
                break;
                
            case 'L':
                std::cout << std::endl 
                          << "Would you like to list the reservations for today (D) or tomorrow (M)?" << std::endl;
                this->list_res(this->get_list());
                break;
                
            case 'T':
                this->terminate();
                break;
            
            default:
                std::cout << std::endl 
                          << "Invalid entry: Please try again" << std::endl 
                          << std::endl;
                break;
        }
    }

    return;
}


/**
 * Prompts the user to input reservation information, then stores the data in
 * the correct list.
 */
void ReservationSystem::submit(LinkedList* day_list)
{
    std::cout << "Please enter the hour of the pickup time in 24 hour time" <<std::endl;
    int pickup_hour = this->get_time(0, 23);
    
    std::cout << "Please enter the minute of the pickup time" << std::endl;
    int pickup_minute = this->get_time(0, 59);

    std::cout << "Please enter the pickup location" << std::endl;
    std::string pickup_location = this->get_string();

    std::cout << "Please enter the name of the contact" << std::endl;
    std::string pickup_name = this->get_string();
    std::cout << std::endl;

    ResData* data = new ResData(pickup_hour, pickup_minute, pickup_location, pickup_name);

    day_list->push_chron(data);
    return;
}


/**
 * If the todayList is empty, a message is displayed stating the list is empty.
 * Otherwise, it calls the pop_front() method of todayList, removing the pickup
 * information for the next reservation to be fulfilled from today's reservation
 * list. Then the pickup data and number of remaining reservations for today is
 * displayed to the user.
 */
void ReservationSystem::pickup_next()
{
    if (todayList.get_node_count() <= 0) 
    {
        std::cout << std::endl 
                  << "No unfulfilled reservations left in list" << std::endl 
                  << std::endl;
    } 
    else 
    {
        ResData * pickup = todayList.pop_front();
        std::cout << std::endl 
                  << pickup->display_data()
                  << "This pickup information has been passed to an available driver" << std::endl
                  << std::endl
                  << todayList.get_node_count() << " unfulfilled reservation(s) left in today's list" << std::endl
                  << std::endl;
        
        res_fulfill_count++;
        delete pickup;
    }

    return;
}


/**
 * If the list if empty, a message is desplayed stating the list is empty.
 * Otherwise, it displays the pickup information for each unfulfilled
 * reservation in the list, as well as the number of reservations left in the
 * list.
 */
void ReservationSystem::list_res(LinkedList* day_list)
{   
    int list_count = day_list->get_node_count();

    if (list_count <= 0) 
    {
        std::cout << std::endl 
                  << "No unfulfilled reservations left in list" << std::endl 
                  << std::endl;
    } 
    else 
    {
        std::cout << std::endl 
                  << day_list->lookup_all() 
                  << std::endl
                  << list_count << " unfulfilled reservation(s) left in list" << std::endl
                  << std::endl;
    }

    return;
}


/**
 * If todayList still contains unfulfilled reservations, a message is displayed
 * stating the program connot terminate and the number of unfulfilled
 * reservations left in today's list. Otherwise, the reservations stored in
 * tomorrowList are saved in a .txt file, the number of reservations fulfilled
 * today are displayed, the number of reservations saved for tomorrow are
 * displayed, and the program terminates.
 */
void ReservationSystem::terminate()
{
    int count = todayList.get_node_count();

    if (count > 0) 
    {
        std::cout << std::endl 
                  << "Program cannot terminate:" << std::endl 
                  << count << " unfulfilled reservation(s) left in today's list" << std::endl 
                  << std::endl;
        return;
    } 
    else if (count <= 0) 
    {
        int saved_res_count = this->save_reservations();
        std::cout << std::endl 
                  << "Number of reservations fulfilled during this session: " << res_fulfill_count << std::endl
                  << "Number of reservations saved for tomorrow: " << saved_res_count << std::endl;
        term = true;
        return;
    }  
}


/**
 * Opens a .txt file containing saved data. The first entry read is a count of
 * the number of ResData objects whose data has been stored in the file. If the
 * file fails to open, it is assumed that no contents were saved, and a count of
 * 0 is returned. Otherwise, a for loop is cycled through an entry_count number
 * of times. Each cycle, it generates a pointer to a new ResData object on the
 * heap, then streams the next section of data into the ResData object, and
 * passes the pointer to today's reservation list to be stored in chronological
 * order.
 */
int ReservationSystem::load_reservations()
{
    int entry_count;
    std::ifstream fin;

    fin.open(res_file.c_str());

    if (fin.fail()) 
    {
        return 0;
    }

    fin >> entry_count;

    for (int i = 0; i < entry_count; i++) 
    {
        ResData * data = new ResData;
        fin >> data;
        todayList.push_chron(data);
    }
    
    fin.close();
    return entry_count;
}


/**
 * Opens a .txt file and saves the contents of each ResData object in tomorrow's
 * reservation list. The node count in tomorrowList is written to the first line
 * to state how many sets of ResData contents are saved in the file. Then, a for
 * loop is cycled through an entry_count number of times. Each cycle, the
 * ResData at the front of tomorrow's list is popped, and its contents are
 * written to the .txt file.
 */
int ReservationSystem::save_reservations()
{
    int entry_count = tomorrowList.get_node_count();
    std::ofstream fout;
    
    fout.open(res_file.c_str());
    fout << entry_count << std::endl;
    
    for (int i = 0; i < entry_count; i++) 
    {
        fout << tomorrowList.pop_front();
    }
    
    fout.close();
    return entry_count;
}


/**
 * Takes a character input in from the user. If the user enters 1 or more
 * characters and hits enter, cin puts the first character in the input string
 * into sel, and a '\n' character is left hanging, so cin.ignore() is called to
 * throw it away. If the user hits enter without inputting any characters, cin
 * puts '\n' into sel, and cin.ignore() is not called as no '\n' character is
 * left hanging. The input character is then converted to uppercase and
 * returned.
 */
char ReservationSystem::get_char()
{
    char sel;

    std::cout << ">>>  ";
    std::cin.get(sel);                   
    
    if (sel != '\n') 
    {
        std::cin.ignore();
    }
    
    sel = toupper(sel);
    return sel;  
}


/**
 * A character input is taken in from the user. If the character is not a valid
 * command, a message is displayed stating what the valid commands are, and the
 * do/while loop loops back and the user is prompted to input a character again.
 * If the input character is valid, a reference to the corrosponding list is
 * returned.
 */
LinkedList* ReservationSystem::get_list()
{
    int bad_input = true;
    char sel;
    LinkedList* day_list;

    do 
    {
        sel = this->get_char();

        switch (sel)
        {
            case 'D':
                day_list = &todayList;
                bad_input = false;
                break;

            case 'M':
                day_list = &tomorrowList;
                bad_input = false;
                break;

            default:
                std::cout << "Entry must be either D for today or M for tomorrow" << std::endl;
                break;
        }
    } while(bad_input == true);

    return day_list;
}


/**
 * The user is prompted to input an integer value that is with in the range of
 * the arguments 'low' and 'high'. When the get_int() method is called, if the
 * user entered a non-integer input, get_int() will throw an std::string
 * containing an error message, which get_time() catches and displays. When an
 * integer is returned, if it is outside the valid range, a message is displayed
 * stating the valid range. The input cycle loops until a valid value is
 * entered, at which point the value is returned.
 */
int ReservationSystem::get_time(int low, int high)
{
    int bad_input;
    int in_time;
    
    do 
    {
        bad_input = false;
        std::cout << ">>>  ";
        
        try 
        {
            in_time = this->get_int();
            
            if (in_time > high || in_time < low) 
            {
                std::cout << "Input must be between " << low << " and " << high << std::endl;
                bad_input = true;
            }
        }
        catch (std::string e) 
        {
            bad_input = true;
            std::cout << e << std::endl;
        }
    } while (bad_input == true);
    
    return in_time;
}


/**
 * std::getline() is used to read the user's input. If the input string is
 * empty, a string is thrown stating the input may not be left blank. If the
 * string is 1 or more characters long, each character is checked to see if it a
 * digit (ie between '0' and '9'). If a digit is not, a string is thrown stating
 * the input must be an integer. If the characters are valid digits, each
 * character is converted into the appropriate integer value, and multipled by
 * the correct power of 10 so it will end up in the correct place value. All of
 * these values are then added together, and the resulting integer value is
 * returned.
 */
int ReservationSystem::get_int()throw(std::string)
{
    std::string str_form;
    int int_form = 0;
    
    std::getline(std::cin, str_form);
    
    if (str_form.length() == 0) 
    {
        std::string e = "Input must not be left blank";
        throw e;
    }
    
    for (int i = str_form.length(); i > 0; i--) 
    {
        if (str_form[i-1] > '9' || str_form[i-1] < '0') 
        {
            std::string e = "Input must be a positive integer";
            throw e;
        }
        int_form += ((str_form[i-1] - '0') * pow(10, str_form.length() - i));
    }
    
    return int_form;
}


/**
 * std::getline() takes in a string from the user. If the input string is empty,
 * a message stating the input must not be left blank is displayed, and the
 * input loop cycles through again. If the string contains any characters, the
 * entire string is returned.
 */
std::string ReservationSystem::get_string()
{
    int bad_input;
    std::string str_in;

    do 
    {
        bad_input = false;
        
        std::cout << ">>>  ";
        std::getline(std::cin, str_in);
        
        if (str_in.length() == 0) 
        {
            bad_input = true;
            std::cout << "Input must not be left blank" << std::endl;
        }
    } while (bad_input == true);
    
    return str_in;
}