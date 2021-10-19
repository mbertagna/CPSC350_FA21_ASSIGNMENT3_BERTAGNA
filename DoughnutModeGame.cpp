// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* DoughnutModeGame.cpp contains the implementation of the DoughnutModeGame derived class which inherits from the Game abstract class. 
It calls Game's constructors and destructor and implements three functions:
1) checkAboveNeighbors: checks number of neighbors above a cell in the grid
2) checkBelowNeighbors: checks number of neighbors below a cell in the grid
3) checkSideNeighbors: checks number of neighbors to the side of a cell in the grid
 */

#include "DoughnutModeGame.h"

// checks number of neighbors above a cell in the grid
int DoughnutModeGame::checkAboveNeighbors(int row, int col){//FIXME: Override causes error
    int numNeighbors = 0;

    //check if cell in a top corner
    if((col == m_currGrid->getWidth()) && (row == 1)){//top right corner
        if(m_currGrid->isSpecifiedCellOccupied(m_currGrid->getHeight(), 1))//bottom left cell
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(m_currGrid->getHeight(), col))//cell "above"
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(m_currGrid->getHeight(), col-1))//cell "above" and left
            ++numNeighbors;
    }
    else if((col == 1) && (row == 1)){//top left corner
        if(m_currGrid->isSpecifiedCellOccupied(m_currGrid->getHeight(), m_currGrid->getWidth()))//bottom right cell
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(m_currGrid->getHeight(), col))//cell "above"
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(m_currGrid->getHeight(), col+1))//cell "above" and right
            ++numNeighbors;
    }

    //check if cell in first row but not corner
    else if(row == 1){
        if(m_currGrid->isSpecifiedCellOccupied(m_currGrid->getHeight(), col-1))//cell "above" and left
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(m_currGrid->getHeight(), col))//cell "above"
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(m_currGrid->getHeight(), col+1))//cell "above" and right
            ++numNeighbors;
    }

    //check if cell in first column
    else if(col == 1){
        if(m_currGrid->isSpecifiedCellOccupied(row-1, m_currGrid->getWidth()))//cell "above" and left
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row-1, col))//cell "above"
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row-1, col+1))//cell "above" and right
            ++numNeighbors;
    }

    //check if cell in last column
    else if(col == m_currGrid->getWidth()){
        if(m_currGrid->isSpecifiedCellOccupied(row-1, col-1))//cell "above" and left
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row-1, col))//cell "above"
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row-1, 1))//cell "above" and right
            ++numNeighbors;
    }

    //if not in first row
    else{
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
int DoughnutModeGame::checkBelowNeighbors(int row, int col){
    int numNeighbors = 0;

    //check if cell in bottom corner
    if((col == 1) && (row == m_currGrid->getHeight())){//bottom left corner
        if(m_currGrid->isSpecifiedCellOccupied(1, m_currGrid->getWidth()))//top right cell
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(1, col))//cell "below"
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(1, col+1))//cell "above" and right
            ++numNeighbors;
    }
    else if((col == m_currGrid->getWidth()) && (row == m_currGrid->getHeight())){//bottom right corner
        if(m_currGrid->isSpecifiedCellOccupied(1, 1))//top right cell
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(1, col))//cell "below"
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(1, col-1))//cell "below" and left
            ++numNeighbors;
    }

    //check if cell in last row but not corner
    else if(row == m_currGrid->getHeight()){
        if(m_currGrid->isSpecifiedCellOccupied(1, col+1))//cell "below" and right
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(1, col))//cell "below"
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(1, col-1))//cell "below" and left
            ++numNeighbors;
    }

    //check if cell in first column
    else if(col == 1){
        if(m_currGrid->isSpecifiedCellOccupied(row+1, m_currGrid->getWidth()))//cell "below" and left
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row+1, col))//cell "below"
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row+1, col+1))//cell "below" and right
            ++numNeighbors;
    }

    //check if cell in last column
    else if(col == m_currGrid->getWidth()){
        if(m_currGrid->isSpecifiedCellOccupied(row+1, col-1))//cell "below" and left
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row+1, col))//cell "below"
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row+1, 1))//cell "below" and right
            ++numNeighbors;
    }

    //if cell not in last row
    else{
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
int DoughnutModeGame::checkSideNeighbors(int row, int col){
    int numNeighbors = 0;

    //check if cell in first column
    if(col == 1){
        if(m_currGrid->isSpecifiedCellOccupied(row, m_currGrid->getWidth()))
            ++numNeighbors;
        
        if(m_currGrid->isSpecifiedCellOccupied(row, col+1))
            ++numNeighbors;
    }

    //check if cell in last column
    else if(col == m_currGrid->getWidth()){
        if(m_currGrid->isSpecifiedCellOccupied(row, col-1))
            ++numNeighbors;
        
        if(m_currGrid->isSpecifiedCellOccupied(row, 1))
            ++numNeighbors;
    }

    //if cell not in first or last column
    else{
        if(m_currGrid->isSpecifiedCellOccupied(row, col-1))
            ++numNeighbors;
        
        if(m_currGrid->isSpecifiedCellOccupied(row, col+1))
            ++numNeighbors;
    }

    return numNeighbors;
}