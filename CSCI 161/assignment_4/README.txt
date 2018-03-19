README  

Program Name: pex4
Author: Matthew Hird
Date: March 18, 2018


    1: Overview

This program simulates some of the features of a web browser, specifically the
ability to keep track of previously visited URLs, and commands for the user to
move backwards and forwards through these URLs. 

The program can be compiled from the directory saved directory using the command
"make". To start the program from the terminal enter the command
"<directory_path>/pex4 <start_url>" where <start_url> is the URL the user wants
to start from.

In the program, the user has various commands that control the browser
simulation. "click <url>" will change the current web page to <url>. "back" will
change the current web page to a previous web page visited, moving backwards one
step. "forward" will  change the current web page to a previous web page
visited,  moving forward one step. "exit" will terminate the program.


    2: Design

This program contains one main controller class, BrowserSim; a templated
container class, Stack; and two exception classes that are subclasses of
std::exception, EmptyStack and InvalidArguments. BrowserSim takes in user input
commands and executes actions based on those commands. Stack contains the basic
functionality of a stack ADT. It is templated to store and retrieve objects of
a specified datatype. 


    3: Implementation

The main.cpp file contains the main() function of the program. It interprets the
commandline arguments and determines if they are valid. If they are valid, a
BrowserSim object is created and its run() method is executed. If the arguments
are invalid, and error message is displayed and the program terminates.

BrowserSim contains a menu() method that loops until the terminate command
"exit" is given. It prompts user for input command, then calls get_command() to
retrieve and parse the command. A switch decides what actions to take based on
the command. Two stacks, "last" and "next", are used to keep track of previously
visited urls. If the command arguments are invalid, an exception is thrown and
caught, and an error message is displayed.

When "back" is entered, the current URL is pushed to the "next" stack, and a
previous URL is popped from the "last" stack. When "forward" is entered, the
current URL is pushed to the "last" stack, and a previous URL is popped from the
"next" stack. When "click <url>" is entered, the current URL is pushed to  the
"last" stack, the "next" stack is cleared, and <url> becomes the new current
URL.

Stack has been implemented as a null-terminated singly linked list. As it only
has basic stack functionality, it only needs to insert and remove to and from
the front of the list, meaning a singly linked list will take up less memory
than alternatives without losing time efficiency.

Stack is templated with Data as a parameter. Data is the data type of the
objects one wants to store in the stack. By making stack a template, it could be
used in a variety of programs that need to store objects of a particular type in
a stack. In pex4, Stack objects are used to store URLs in the form of
std::strings. If I decided to store the URLs in a struct that contained other
information to be kept with the URL (such as time stamps), no modifications
would need to be made to the Stack class because of the templating.

EmptyStack and InvlaidArguments are subclasses of std::exception. This allows
them to be caught by any block that catches std::exception&. This also gives
them the ability to overwrite the virtual method what(), that returns an error
message. As the class declarations and implementations are small, and need to be
accessed by multiple other modules, I put both exceptions in the same header
file (my_exceptions.h) and implemented the methods inline in the header file.


    4: Accomplishment

I have completed all parts of the assignment that were listed under the Problem
Description and Implementation Requirements sections of the Assignment 1,
Assignment 3, and Assignment 4 webpages, as well as all documentation specified
by those pages.


    5: Testing

The output of my testing is in test_output.txt. For an example of each thing
tested in that document, I will list out the line number of the example followed
by a description of what is being tested:

 1  Run pex4 with no arguments.
 6  Run pex4 with too many arguments.
11  Run pex4 with one argument.
16  "back" command from initial URL.
22  "forward" command from initial URL.
28  Empty string as command input.
33  Too many arguments for "back" command.
38  "click" command with no arguments.
43  "click <url>" command.
49  "back" command.
61  "forward" command.
76  "click <url>" command after moving back.
79  "forward" command after line 76 case.
88  "back" command with spaces before and after command 
    (i.e. "      back      ").
91  "click <url>" command with spaces before and after click and <url>
    (i.e. "    click      yahoo.ca   ").
94  "exit" command.


    6: Know Bugs

There are no known bugs in this program.