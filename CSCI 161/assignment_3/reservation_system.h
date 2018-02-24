//------------------------------------------------------------------------------
// @file reservation_system.h
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

#pragma once
#include <fstream>
#include <sstream>
#include "linked_list.h"
#include "res_data.h"


class ReservationSystem
{
private:
    int term;
    int res_fulfill_count;
    std::string res_file;

    LinkedList todayList;
    LinkedList tomorrowList;


public:
    /**
     * Default constructor 
     */
    ReservationSystem();

    
    /** 
     * Destructor 
     */
    ~ReservationSystem();


    /**
     * @brief      Entrance point and controller of the reservation system
     *             class. When it is called, yesterday's saved reservations are
     *             loaded into today's reservation list. Then, it displays the
     *             valid commands and prompts the user to input a command.
     */
    void menu();    


    /**
     * @brief      Prompts the user to input reservation information for today
     *             or tomorrow.
     *
     * @param      day_list  Pointer to the list the reservation information is
     *                       being stored in.
     */
    void submit(LinkedList* day_list);  


    /**
     * @brief      Displays the pickup information of the next reservation that
     *             needs to be fulfilled in today's reservation list, and
     *             removes the reservation from the list.
     */
    void pickup_next();                 


    /**
     * @brief      Displays the pickup information of all unfulfilled
     *             reservations in the reservation list that was passed.
     *
     * @param      day_list  Pointer to the list whose information is being
     *                       displayed.
     */
    void list_res(LinkedList* day_list);


    /**
     * @brief      If today's list is empty, tomorrow's list gets saved into a
     *             .txt, and the program terminates.
     */
    void terminate();


    /**
     * @brief      Reads reservation data that has been stored into a .txt, and
     *             uses the data to populate the reservation list for today.
     *
     * @return     Number of reservations loaded into todayList.
     */
    int load_reservations();


    /**
     * @brief      Retrieves the data from tomorrow's reservation list, and
     *             writes it into a .txt file.
     *
     * @return     Number of reservations saved into the .txt from tomorrowList.
     */
    int save_reservations();


    /**
     * @brief      Prompts the user for an input character.
     *
     * @return     Character input by the user, converted to uppercase.
     */
    char get_char();

    
    /**
     * @brief      Prompts the user to select today's reservation list or
     *             tomorrow's reservation list.
     *
     * @return     Pointer to the ReservationList selected by the user.
     */
    LinkedList* get_list();

    
    /**
     * @brief      Prompts the user to input an integer that is within a
     *             specified range.
     *
     * @param[in]  low   The lowest value in the range (inclusive).
     * @param[in]  high  The highest value in the range (inclusive).
     *
     * @return     Valid integer input that is within the specified range.
     */
    int get_time(int low, int high);

    
    /**
     * @brief      Prompts the user for an integer input.
     *
     * @throws     std::string  If the input is empty. Contains error message.
     * @throws     std::string  If the input is not a positive integer. 
     *                          Contains error message.
     *
     * @return     Positive integer input by the user.
     */
    int get_int()throw(std::string);

    
    /**
     * @brief      Prompts the user to input a non-empty string
     *
     * @return     Non-empty string input by the user
     */
    std::string get_string();
};