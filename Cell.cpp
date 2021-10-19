// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* Cell.cpp contains the implementation of the Cell class. It implements a default constructor, a destructor, and four functions:
1) setOccupied: sets cell occupied
2) setEmpty: sets cell empty
3) isOccupied: checks if cell occupied ('X')
4) getValue: returns value ('X' or '-')
 */

#include "Cell.h"

// default constructor
Cell::Cell(){
  m_value = '-';//set as empty initially
}

// destructor
Cell::~Cell(){}

// sets cell occupied
void Cell::setOccupied(){
  m_value = 'X';
}

// sets cell empty
void Cell::setEmpty(){
  m_value = '-';
}

// checks if cell occupied ('X')
bool Cell::isOccupied(){
  return (m_value == 'X');
}

// returns value ('X' or '-')
char Cell::getValue(){
  return m_value;
}
