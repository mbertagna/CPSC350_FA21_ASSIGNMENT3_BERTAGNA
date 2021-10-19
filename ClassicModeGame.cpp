// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* ClassicModeGame.cpp contains the implementation of the ClassicModeGame derived class which inherits from the Game abstract class. 
It calls Game's constructors and destructor and implements three functions:
1) checkAboveNeighbors: checks number of neighbors above a cell in the grid
2) checkBelowNeighbors: checks number of neighbors below a cell in the grid
3) checkSideNeighbors: checks number of neighbors to the side of a cell in the grid
 */

#include "ClassicModeGame.h"

// checks number of neighbors above a cell in the grid
int ClassicModeGame::checkAboveNeighbors(int row, int col){
    int numNeighbors = 0;

    if(!(row == 1)){//if not in first row count occupied cells above target cell
        if(m_currGrid->isSpecifiedCellOccupied(row-1, col))//check cell directly above target cell
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row-1, col+1))//check cell above and right of target cell
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row-1, col-1))//check cell above and left of target cell
            ++numNeighbors;
    }

    return numNeighbors;
}
// checks number of neighbors below a cell in the grid
int ClassicModeGame::checkBelowNeighbors(int row, int col){
    int numNeighbors = 0;

    if(!(row == m_currGrid->getHeight())){//if not in last row count occupied cells below target cell
        if(m_currGrid->isSpecifiedCellOccupied(row+1, col))//check cell directly below target cell
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row+1, col+1))//check cell below and right of target cell
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row+1, col-1))//check cell below and left of target cell
            ++numNeighbors;
    }

    return numNeighbors;
}
// checks number of neighbors to the side of a cell in the grid
int ClassicModeGame::checkSideNeighbors(int row, int col){
    int numNeighbors = 0;

    if(!(col == 1)){//if not in first column check cell to left of target cell
        if(m_currGrid->isSpecifiedCellOccupied(row, col-1))
            ++numNeighbors;
    }
        

    if(!(col == m_currGrid->getWidth())){//if not in last column check cell to right of target cell
        if(m_currGrid->isSpecifiedCellOccupied(row, col+1))
            ++numNeighbors;
    }

    return numNeighbors;
}