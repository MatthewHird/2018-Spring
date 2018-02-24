README  

Program Name: pex3
Author: Matthew Hird
Date: February 24, 2018


	1: Overview

This program allows a user to submit reservation information for a taxi cab, and 
recall reservation information that has been stored. The reservation must be for
the current session (today) or for the next session (tomorrow). The data is 
inserted chronologically into one of two linked lists, either today or tomorrow.
The user can remove the first item from today's list and have the pickup 
information displayed on the screen. The user can also display the contents of 
either list on the screen, without remove the items from the list. When the user
commands the program to terminate, it will only do so if no unfulfilled 
reservations remain in today's list. If today's list is empty when terminate is
called, the contents of tomorrow's list are saved into a .txt file, and the
number of reservations fulfilled in the session are displayed, followed by the
program terminating. When the program is starts, if a .txt save file exists, the
saved reservations are loaded into today's list, in chronological order.


	2: Design

This program is broken up into three classes: ReservationSystem, LinkedList,
and ResData. ResData stores the contact and pickup information for a single
reservation. LinkedList is a container that stores ResData objects 
chronologically, based on their time value. ReservationSystem is the main 
controller that reads user inputs, creates the LinkedList objects, generates 
ResData objects, and calls LinkedLists to store and recall ResData objects.


	3: Implementation

The ResData class uses integers and strings to store the pickup information 
values. The display_data() method returns this data in a human readable,
printable format as a string. ResData also overloads I/O stream operators 
>> and <<, which allows the stored information to be written in a format and
be recalled later. 

LinkedList defines a struct called Node that points to a ResData object, as well
as the next Node in the list. It also contains a method to insert a ResData 
object chronologically, a method to pop the front Node from the list (returning 
the ResData pointer), and a method that calls the display_data() method of every
ResData object stored in the list, and returns that data as a single string.

The ReservationSystem class contains many methods. There is a menu method is the 
central controller of the program. It allows the user to input commands, and 
calls other methods based on those commands. 

These command methods are the link between the user inputs and the linked lists, 
doing operations such as turning user data into a ResData object and sending the
object to be stored in a linked list, or getting a list to pop its front node, 
then displaying the popped information to the user display.

Reservation system also contains  a set of methods that handle user inputs.
There are seperate methods for handling single characters, full line strings,
and positive integers. They contain their own exception handling, meaning they
will always deliver valid data to the calling function.

There is also a pair of methods that handle the saving and loading of data to
and from a .txt file. They handle the logic of where to load and save the data
to, as the actual format of the data is handled by the ResData object.

There are a few different ways this program could have been implemented. The 
input handling methods could have been put in their own class. This would have
cut down on the length of reservation.cpp and created better encapsulation, as
none of the input logic needs to be know by the rest of ReservationSystem. 

Another way RedData could have been implemented is to have "get" methods 
(ie get_hour(), get_name(), etc) to access each individual data field. Then,
ReservationSystem could could have a method to format and display the data,
instead of the data being formatted by the ResData object itself.  

The logic for inserting items into the linked list could have been changed. The
Node struct in LinkedList could have contained a general "id" field, and the 
push method could have had an "id" argument. When ReservationSystem.submit() 
generates the ResData object, it could also generate a "time". This would be 
sent as the "id" value for the push method. This would allow LinkedList to 
insert data into a sorted list without having to poke around inside the data
object it is storing.


	4: Accomplishment

I have completed all parts of the assignment that were listed under the Problem
Description and Implementation Requirements sections of the Assignment 1 and 
Assignment 3 webpages, as well as all documentation specified by those pages.


	5: Testing

The output of my testing is in test_output.txt. For an example of each thing
tested in that document, I will list out the line number of the example followed
by a description of what is being tested:

  3    No reservations document to load from.
 13    Pickup command with an empty list.
 25    List command with an empty list.
 45    Pickup hour out of range.
 47    Pickup hour invalid character.
 52    Pickup minute out of range.
 55    Pickup minute invalid character.
 59    Blank location field.
 61    Location entry with space in the string.
 63    Black name field.
 75    Terminate command with non-empty todayList.
 93    Submitted reservations in non-chronological order (3 total reservations
       added to todayList).
133    Submitted reservations in non-chronological order (2 total reservations
       added to tomorrow list).
172    Listed out todayList in chronological order.
200    Listed out tomorrowList in chronological order.
224    Pickup command. Pops first reservation off of todayList.
290    Terminate command with empty todayList.
292    Confirmation that 2 reservations from tomorrowList were saved.

297    Start program again.
299    Confirmation that 2 reservations were loaded into todayList.
309    List command for todayList, showing data can been correctly loaded.
333    List command for tomorrowList, showing nothing was loaded into it.


	6: Know Bugs

There are no known bugs in this program.