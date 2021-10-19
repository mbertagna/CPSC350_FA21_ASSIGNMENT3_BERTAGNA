// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* UserInput.h is a header file which lays out the elements of the UserInput class. */

#ifndef USERINPUT_H
#define USERINPUT_H

#include <iostream>
#include <ctype.h> //for isDigit()
#include <string> //for stod() and stoi()
using namespace std;

class UserInput{
  public:
    UserInput();//default constructor
    ~UserInput();//destructor

    // gets height value from user and provides input protection
    int getHeightNum();

    // gets width value from user and provides input protection
    int getWidthNum();

    // gets density value from user and provides input protection
    double getDensityNum();

    // checks if string is an +integer
    bool isPosInt(string maybeInt);

    // checks if string is a +double in range (0,1]
    bool isPosDouble0to1(string maybeDouble);
};

#endif
