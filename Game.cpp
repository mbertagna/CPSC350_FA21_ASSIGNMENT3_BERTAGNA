// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* Game.cpp contains the implementation of the Game abstract class. It implements a default constructor, two overloaded constructors, a destructor, and four functions:
1) startGame: starts game of specified ouput type
2) startGameFileOutput: starts game and writes game information to file
3) startGameEnter: starts game and requires that user hit enter before the next generation is displayed
4) startGamePause: starts game and displays generations with a brief pause between each displayed generation
5) setCurrGeneration: sets the current generation as the next generation
6) calculateNextGeneration: calculates next generation and saves occupancy to m_nextGrid
7) checkNumNeighbors: checks number of total neighbors for a cell in the current grid
8) isGridSame: checks if grid occupancy is the same in consecutive rounds
9) printGenerationNum: prints the generation number
10) printCurrGeneration: prints the current generation
 */

#include "Game.h"

Game::Game(){}

//overloaded constructor: map file grid occupancy
Game::Game(int height, int width, string gridString){
    m_generationNum = 1;
    m_nextGrid = new Grid(height, width, 0.0);
    m_currGrid = new Grid(height, width, gridString);
}

//overloaded constructor: random grid occupancy
Game::Game(int height, int width, double density){
    m_generationNum = 1;
    m_nextGrid = new Grid(height, width, 0.0);
    m_currGrid = new Grid(height, width, density);
}

//destructor
Game::~Game(){
    // delete pointers to grids
    delete m_nextGrid;
    delete m_currGrid;
}

// starts game of specified ouput type
void Game::startGame(char outputType){
    switch (outputType)
    {
    case 'p':
        startGamePause();
        break;
    case 'e':
        startGameEnter();
        break;
    case 'f':
        startGameFileOutput();
        break;
    }
}

// starts game and writes game information to file
void Game::startGameFileOutput(){
    FileProcessor *fp = new FileProcessor();

    int inputGrid = true;

    while(!(isGridSame())){
        if(inputGrid){//prints this to show user the input grid
            while(fp->createOutputFile(0, m_currGrid->getGridString()) == -1){}
            inputGrid = false;
        }
        else{
            while(fp->createOutputFile(m_generationNum, m_currGrid->getGridString()) == -1){}
            calculateNextGeneration();//calculate next generation
            setCurrGeneration();//set next generation is current
            ++m_generationNum;
        }
    }

    delete fp;

    cout << endl;
    cout << "–––THE GAME OF LIFE HAS STABILIZED–––" << endl;
    cout << "*Press 'enter' to end the simulation.*" << endl;
    cin.get();
    cin.get();
}

// starts game and requires that user hit enter before the next generation is displayed
void Game::startGameEnter(){
bool caughtExtraEnter = false;

    cout << endl;

    cout << "0" << endl;
    printCurrGeneration();//print input grid
    cout << endl;

    while(!(isGridSame())){
        printGenerationNum();
        printCurrGeneration();//print curent generation
        if(!caughtExtraEnter){
            cin.get();//catch extra enter
            caughtExtraEnter = true;
        }
        cin.get();//wait for user to press enter
        calculateNextGeneration();//calculate next generation
        setCurrGeneration();//set next generation is current
        ++m_generationNum;
    }

    cout << "–––THE GAME OF LIFE HAS STABILIZED–––" << endl;
    cout << "*Press 'enter' to end the simulation.*" << endl;
    cin.get();
}

// starts game and displays generations with a brief pause between each displayed generation
void Game::startGamePause(){
    cout << endl;

    cout << "0" << endl;
    printCurrGeneration();//print input grid
    cout << endl;

    while(!(isGridSame())){
        printGenerationNum();
        printCurrGeneration();//print curent generation
        usleep(2000000);//wait for 2 seconds
        cout << endl;
        calculateNextGeneration();//calculate next generation
        setCurrGeneration();//set next generation is current
        ++m_generationNum;
    }

    cout << "–––THE GAME OF LIFE HAS STABILIZED–––" << endl;
    cout << "*Press 'enter' to end the simulation.*" << endl;
    cin.get();
    cin.get();
}

// sets the current generation as the next generation
void Game::setCurrGeneration(){
    //swaps grid pointers (shadow paging)
    Grid *temp = m_currGrid;
    m_currGrid = m_nextGrid;
    m_nextGrid = temp;
}

// calculates next generation and saves occupancy to m_nextGrid
void Game::calculateNextGeneration(){
    for(int row = 1 ; row <= m_currGrid->getHeight() ; ++row){//loop through all rows of currGrid
        for(int col = 1 ; col <= m_currGrid->getWidth() ; ++col){//loop through all columns of currGrid
            if(m_currGrid->isSpecifiedCellOccupied(row,col)){//if cell occupied
                switch(checkNumNeighbors(row,col)){//get num neighbors for occupied cell and perform operations accordingly (cases represent number of occupied cells around cell)
                    case 0:
                        m_nextGrid->setCellEmpty(row,col);//kill cell with 0 neighbors
                        break;

                    case 1:
                        m_nextGrid->setCellEmpty(row,col);//kill cell with 1 neighbor
                        break;

                    case 2:
                        m_nextGrid->setCellOccupied(row,col);//keep cell alive with 2 neighbors
                        break;

                    case 3:
                        m_nextGrid->setCellOccupied(row,col);//keep cell alive with 3 neighbors
                        break;

                    default:
                        m_nextGrid->setCellEmpty(row,col);//kill cell with 4+ neighbors
                }
            }
            else{//if cell empty
                switch(checkNumNeighbors(row,col)){//get num neighbors for empty cell and perform operations accordingly (cases represent number of occupied cells around cell)
                    case 0:
                        m_nextGrid->setCellEmpty(row,col);//keep cell empty with 0 neighbors
                        break;

                    case 1:
                        m_nextGrid->setCellEmpty(row,col);//keep cell empty with 1 neighbor
                        break;

                    case 2:
                        m_nextGrid->setCellEmpty(row,col);//keep cell empty with 2 neighbors
                        break;

                    case 3:
                        m_nextGrid->setCellOccupied(row,col);//birth cell with 3 neighbors
                        break;

                    default:
                        m_nextGrid->setCellEmpty(row,col);//keep cell empty with 4+ neighbors
                }
            }
        }
    }
}

// checks number of total neighbors for a cell in the current grid
int Game::checkNumNeighbors(int row, int col){
    return (checkAboveNeighbors(row,col) + checkBelowNeighbors(row,col) + checkSideNeighbors(row,col));
}

// checks if grid occupancy is the same in consecutive rounds
bool Game::isGridSame(){
    if(m_currGrid->getGridString() == m_nextGrid->getGridString()){
        return true;
    }
    return false;
}

// prints the generation number
void Game::printGenerationNum(){
    cout << "Generation: " << m_generationNum << endl;
}

// prints the current generation
void Game::printCurrGeneration(){
    m_currGrid->printGrid();
}
