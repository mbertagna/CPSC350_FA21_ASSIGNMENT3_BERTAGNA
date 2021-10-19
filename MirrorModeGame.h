// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* MirrorModeGame.h is a header file which lays out the elements of the MirrorModeGame derived class (base class: Game). */

#ifndef MIRRORMODEGAME_H
#define MIRRORMODEGAME_H

#include <iostream>
#include "Game.h"
using namespace std;

class MirrorModeGame : public Game{
    
    protected:

    public:
        //overloaded constructor: specify occupancy via map file
        MirrorModeGame(int height, int width, string gridString) : Game(height, width, gridString){}

        //overloaded constructor: random occupancy
        MirrorModeGame(int height, int width, double density) : Game(height, width, density){}

        // checks number of neighbors above a cell in the grid
        int checkAboveNeighbors (int row, int col) override;
        // checks number of neighbors below a cell in the grid
        int checkBelowNeighbors(int row, int col) override;
        // checks number of neighbors to the side of a cell in the grid
        int checkSideNeighbors(int row, int col) override;
};

#endif