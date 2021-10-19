// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* Game.h is a header file which lays out the elements of the Game abstract class. */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <unistd.h> // for usleep()
#include "Grid.h"
#include "FileProcessor.h"
using namespace std;

class Game{
  protected:
    Grid *m_currGrid;
    Grid *m_nextGrid;
    int m_generationNum;

  public:
    Game();//default constructor: map file grid occupancy
    Game(int height, int width, string gridString);//overloaded constructor: random grid occupancy
    Game(int height, int width, double density);//overloaded constructor: map file grid occupancy
    ~Game();//destructor

    // starts game of specified ouput type
    void startGame(char outputType);

    // starts game and writes game information to file
    void startGameFileOutput();
    
    // starts game and requires that user hit enter before the next generation is displayed
    void startGameEnter();

    // starts game and displays generations with a brief pause between each displayed generation
    void startGamePause();

    // sets the current generation as the next generation
    void setCurrGeneration();

    // calculates next generation and saves occupancy to m_nextGrid
    void calculateNextGeneration();

    // checks number of total neighbors for a cell in the grid
    int checkNumNeighbors(int row, int col);
    // checks number of neighbors above a cell in the grid
    virtual int checkAboveNeighbors (int row, int col) = 0;//pure virtual
    // checks number of neighbors below a cell in the grid
    virtual int checkBelowNeighbors(int row, int col) = 0;//pure virtual
    // checks number of neighbors to the side of a cell in the grid
    virtual int checkSideNeighbors(int row, int col) = 0;//pure virtual

    // checks if grid occupancy is the same in consecutive rounds
    bool isGridSame();

    // prints the generation number
    void printGenerationNum();

    // prints the current generation
    void printCurrGeneration();
};

#endif
