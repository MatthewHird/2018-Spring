README  

Program Name: pex5
Author: Matthew Hird
Date: April 1, 2018


    1: Overview

This program is a sort of light encyclopedia for countries. The name of a
country can be entered into the system along with various other fields of
information, such its capital city, languages, area, population, and
description. The system can hold up to 200 entries.

The program can be compiled from the directory saved directory using the command
"make". To start the program from the terminal enter the command
"<directory_path>/pex4".

Various commands allow the user to interact with these data entries. "list" will
list the names of all countries currently with an entry in the system. "show"
will prompt the user for the name of a country currently in the system, then
display any data stored on the country. Blank fields will not be included.
"remove" will prompt the user for the name of a country in the system, then
remove the name and any other information on that country from the system. "add"
will prompt the user for the name of a country not in the system. It will then
allow the user to enter information into each of the data fields on that
country. "update" will prompt the user for the name of a country in the system
and allow each of the data fields to be changed. "help" will display the
commands the program recognizes. "exit" will terminated the program and save all
entries currently in the system into "wikiCountry.txt". This file is read when
the program starts, and its information is loaded into the system.


    2: Design

This program contains one main controller class, WikiCountry; a templated
container class, Dictionary; a sorted list container class, SortedList; a data
class, CountryData; and six exception classes that are subclasses of
std::exception, InvalidInput, EmptyInput, FullContainer, EmptyContainer,
DuplicateKey, and MissingKey.

WikiCountry takes in user input commands and executes actions based on those
commands. Dictionary contains the basic functionality of a dictionary ADT. It is
templated to store and retrieve objects of a specified datatype. SortedList is a
list that stores std::string objects alphabetically. CountryData stores
encyclopedia information about a specific country.


    3: Implementation

CountryData contains member variables for each of the information fields for a
country, as well as a set and get public member function for each. It overloads
istream and ostream operators to write and read the CountryData object's
information to and from a string or .txt file.

SortedList is a singly linked list with a dummy node that stores std::strings.
Each string is inserted into the list alphabetically. SortedList can also remove
entries by name, or return a string listing all contents of the list.

Dictionary uses a fixed length array (200 indexes by default) to store structs
of type Entry. Entries represent key/value pairs, where the key is a unique
identifier of the entry. Dictionary has one template parameter, Data, which is
the datatype of the value object kept in each entry. This means each entry
contains a key/value pair of type std::string and Data respectively. Each
Dictionary object contains a SortedList, called key_list, that contains all keys
currently used by entries in Dictionary.

WikiCountry creates two Dictionary objects when it is instantiated. One called
"countries" stores the unique names of countries as keys paired with CountryData
objects containing information on those countries. The other, called
"command_keys", pairs command strings accepted by the WikiCountry's menu method
with unique integers that represent the cases of a switch in the menu method.
This switch cases (which must be identified by primitive values) to be selected
using string commands.

When WikiCountry is run, it calls a load method that reads data from a .txt save
file, and uses that information to populate the Dictionary "countries". When
WikiCountry is terminated through the "exit" command, it calls a save method
that writes the contents of every CountyData object stored in the "countries"
dictionary to a .txt save file.

WikiCountry's menu method prompts the user for commands, uses a method to take
in the input string, uses "command_keys" to convert the input string into a
unique integer value, and uses a switch to take a specific action based on that
integer value.

Seven commands exist, and are not case sensitive. "list" lists the names of all
countries currently in the system. "show" prompts user for the name of a country
in the system and displays all data stored with that country. "remove" prompts
user for the name of a country in the system and removes the country and all
associated data from the system. "add" prompts the user to enter the name of a
new country to add to the system, along with an information about the country.
"update" prompts the user for the name of a country in the system, then allows
the user to update any data fields associated with that country (including
country name). "help" lists the commands the program recognizes. "exit" saves
the contents of the "countries" Dictionary to a .txt save file, then terminates
the program.


    4: Accomplishment

I have completed all parts of the assignment that were listed under the Problem
Description and Implementation Requirements sections of the Assignment 1,
Assignment 3, and Assignment 5 webpages, as well as all documentation specified
by those pages.


    5: Testing

The output of my testing is in test_output.txt. For an example of each thing
tested in that document, I will list out the line number of the example followed
by a description of what is being tested:

 15 Empty string as input command.
 30 Invalid input command.
 45 "list" command.
 66 Upper and lower case command accepted.
 68 "show" command with name of country not in system.
 83 "show" command with valid country name in system.
104 "remove" command with name of country not in system.
121 "remove" command with valid country name in system.
158 "add" command.
160 Leaving name of country entry blank.
162 Valid country name input for "add".
168 Blank input for information field.
170 Input string instead of integer value in data field.
172 Input negative integer instead of positive integer in data field.
191 Showing output of added country. Empty fields don't get displayed.
211 "update" command with name of country not in system.
228 Update command with valid country name in system.
271 Shows updated fields display correctly.
284 "help" command.
297 "exit" command.
 

    6: Know Bugs

There are no known bugs in this program.


    7: Note

Blank entries for the area and population fields of CountryData are stored as
-1, including when written to the save file. When the save is loaded, those
fields can read -1, but cannot read an empty string.

As an additional feature, WikiCountry allows the name of a country to be updated
using the "update" command.