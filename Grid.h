// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* Grid.h is a header file which lays out the elements of the Grid class. */

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <cstdlib> //for srand/rand
#include <time.h> //for time
#include "Cell.h"
using namespace std;

class Grid{
  private:
    Cell **m_grid;

    int m_height;//number of Rows
    int m_width;//number of Columns

  public:
    Grid();//default constructor
    Grid(int height, int width, double density);//overloaded constructor for density input
    Grid(int height, int width, string gridStr);//overloaded constructor for map file string input
    ~Grid();//destructor

    // getters
    int getHeight();
    int getWidth();

    // checks if cell is occupied
    bool isSpecifiedCellOccupied(int height, int width);

    // setters
    void setCellOccupied(int height, int width);
    void setCellEmpty(int height, int width);

    // prints grid in user friendly format
    void printGrid();

    // returns string of grid elements
    string getGridString();

    //returns specified cell's data
    char getSpecifiedCellData(int height, int width);

    // checks if string is an +integer
    bool isPosInt(string maybeInt);
};

#endif
