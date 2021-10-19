// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* Cell.h is a header file which lays out the elements of the Cell class. */

#ifndef CELL_H
#define CELL_H

#include <iostream>
using namespace std;

class Cell{
  private:
    char m_value;//'X' = occupied; "-" = empty
  public:
    Cell();//default constructor
    ~Cell();//destructor

    // setters
    void setOccupied();

    void setEmpty();

    // checks if cell occupied ('X')
    bool isOccupied();

    // returns value ('X' or '-')
    char getValue();
};

#endif
