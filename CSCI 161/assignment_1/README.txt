README  

Program Name: taxi_reservation_system
Author: Matthew Hird
Date: January 23, 2018


	1: Files 

	README
	Makefile		
	main.cpp
	reservation_list.cpp
	linked_list.cpp
	res_data.cpp	
	reservation_list.h
	linked_list.h
	res_data.h


	2: Compiling and Running the Program

To compile from the terminal, change directory to the location of the files. 
Then enter the command "make". 
To run the program, enter "./taxi_reservation_system".


	3: Operating the Program

At the main menu, you will be prompted to enter a command.

"S" will submit a new reservation request. This will prompt you to enter
reservation information to be stored in the program. This will include
the pickup hour (a 1 or 2 digit integer), the pickup minute (a 1 or 2 
digit integer), the pickup location (a non-empty string that can include 
spaces) and the contact name (a non-empty string that can include 
spaces). Invalid entries will prompt you to try again.

"P" will output the pickup information for the reservation with the 
earliest pickup time, and remove the entry from the list. If there are no
unfulfilled reservations left in the list, a message saying the list is
empty will be output and you will be returned to the main menu.

"L" will output the data from each unfulfilled reservation in the system.
Reservations will be listed in chronological order. At the end, the number
of unfulfilled reservations still in the system will be output. If there 
are no unfulfilled reservations left in the list, a message saying the 
list is empty will be output and you will be returned to the main menu.

"T" will terminate the program (if the reservation list is empty) and will
output the number of reservations processed and fulfilled. If the list is
not empty, the number of unfulfilled reservations still in the system will 
be output, and the program will return to the menu.


	4: Aspects of Assignment 1 Completed

This program fulfills all of the tasks listed on the assignment 1 page. When
commands are input or data is submitted, all invalid inputs result in an 
appropriate message being output prompting the user to try reentering the 
command or the data. In the menus, upper or lower case characters are accepted.

The program also properly implements a singly linked list. This lists correctly 
places the node in chronological order based on the pickup time contained in
the data being pointed at. New nodes and data objects are generated in the heap,
and are manually deleted when "P" is entered in the menu. The linked_list 
destructor also deletes any remaining data objects or nodes when it is called.

Each of the source and header files submitted contain a header comment with some
file information. Also, all of the files include descriptions and comments on 
every function, method, switch, and while loop.

Other miscellaneous aspects of his program are the use of classes seperated into
seperate .cpp and .h files, and the use of constructors and destructors when
creating class objects.

