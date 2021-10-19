// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* MirrorModeGame.cpp contains the implementation of the MirrorModeGame derived class which inherits from the Game abstract class. 
It calls Game's constructors and destructor and implements three functions:
1) checkAboveNeighbors: checks number of neighbors above a cell in the grid
2) checkBelowNeighbors: checks number of neighbors below a cell in the grid
3) checkSideNeighbors: checks number of neighbors to the side of a cell in the grid
 */

#include "MirrorModeGame.h"

// checks number of neighbors above a cell in the grid
int MirrorModeGame::checkAboveNeighbors(int row, int col){//FIXME: Override causes error
    int numNeighbors = 0;

    //check if cell in a top corner
    if((col == m_currGrid->getWidth()) && (row == 1)){//top right corner
        if(m_currGrid->isSpecifiedCellOccupied(row, col))//itself
            numNeighbors += 2;

        if(m_currGrid->isSpecifiedCellOccupied(row, col-1))//cell left
            ++numNeighbors;
    }
    else if((col == 1) && (row == 1)){//top left corner
        if(m_currGrid->isSpecifiedCellOccupied(row, col))//itself
            numNeighbors += 2;

        if(m_currGrid->isSpecifiedCellOccupied(row, col+1))//cell right
            ++numNeighbors;
    }

    //check if cell in first row but not corner
    else if(row == 1){
        if(m_currGrid->isSpecifiedCellOccupied(row, col))//itself
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row, col+1))//cell right
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row, col-1))//cell left
            ++numNeighbors;
    }

    //check if cell in first column
    else if(col == 1){
        if(m_currGrid->isSpecifiedCellOccupied(row-1, col))//above
            numNeighbors += 2;

        if(m_currGrid->isSpecifiedCellOccupied(row-1, col+1))//cell above right
            ++numNeighbors;
    }

    //check if cell in last column
    else if(col == m_currGrid->getWidth()){
        if(m_currGrid->isSpecifiedCellOccupied(row-1, col))//above
            numNeighbors += 2;

        if(m_currGrid->isSpecifiedCellOccupied(row-1, col-1))//cell above left
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
int MirrorModeGame::checkBelowNeighbors(int row, int col){
    int numNeighbors = 0;

    //check if cell in bottom corner
    if((col == 1) && (row == m_currGrid->getHeight())){//bottom left corner
        if(m_currGrid->isSpecifiedCellOccupied(row, col))//itself
            numNeighbors += 2;

        if(m_currGrid->isSpecifiedCellOccupied(row, col+1))//cell right
            ++numNeighbors;
    }
    else if((col == m_currGrid->getWidth()) && (row == m_currGrid->getHeight())){//bottom right corner
        if(m_currGrid->isSpecifiedCellOccupied(row, col))//itself
            numNeighbors += 2;

        if(m_currGrid->isSpecifiedCellOccupied(row, col-1))//cell left
            ++numNeighbors;
    }

    //check if cell in last row but not corner
    else if(row == m_currGrid->getHeight()){
        if(m_currGrid->isSpecifiedCellOccupied(row, col))//itself
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row, col+1))//cell right
            ++numNeighbors;

        if(m_currGrid->isSpecifiedCellOccupied(row, col-1))//cell left
            ++numNeighbors;
    }

    //check if cell in first column
    else if(col == 1){
        if(m_currGrid->isSpecifiedCellOccupied(row+1, col))//below
            numNeighbors += 2;

        if(m_currGrid->isSpecifiedCellOccupied(row+1, col+1))//cell below right
            ++numNeighbors;
    }

    //check if cell in last column
    else if(col == m_currGrid->getWidth()){
        if(m_currGrid->isSpecifiedCellOccupied(row+1, col))//below
            numNeighbors += 2;

        if(m_currGrid->isSpecifiedCellOccupied(row+1, col-1))//cell below left
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
int MirrorModeGame::checkSideNeighbors(int row, int col){
    int numNeighbors = 0;

    //check if cell in first column
    if(col == 1){
        if(m_currGrid->isSpecifiedCellOccupied(row, col))//itself
            ++numNeighbors;
        
        if(m_currGrid->isSpecifiedCellOccupied(row, col+1))//right
            ++numNeighbors;
    }

    //check if cell in last column
    else if(col == m_currGrid->getWidth()){
        if(m_currGrid->isSpecifiedCellOccupied(row, col))//itself
            ++numNeighbors;
        
        if(m_currGrid->isSpecifiedCellOccupied(row, col-1))//left
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