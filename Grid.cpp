// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* Grid.cpp contains the implementation of the Grid class. It implements a default constructor, two overloaded constructors, a destructor, and four functions:
1) printGrid: prints grid in user friendly format
2) getHeight: gets grid height
3) getWidth: gets grid width
4) isSpecifiedCellOccupied: checks if cell is occupied
5) setCellOccupied: sets grid cell occupied
6) setCellEmpty: sets grid cell empty
7) getGridString: returns string of grid elements
8) getSpecifiedCellData: returns specified cell's data
 */

#include "Grid.h"

//default constructor
Grid::Grid(){}

// overloaded constructor for map file string input: creates grid with specified occupancy
Grid::Grid(int height, int width, string gridStr){
  m_height = height;
  m_width = width;

  //create 2D pointer array of Cells
  m_grid = new Cell*[m_height];

  for(int i = 0; i < m_height; ++i)
      m_grid[i] = new Cell[m_width];

  int charCount = 0;

  // set specified cells occupied based on map file string
  for(int i = 0; i < m_height; ++i){
    for(int j = 0; j < m_width; ++j){
      if(gridStr[charCount] == 'X')
      (m_grid[i][j]).setOccupied();
      ++charCount;
    }
  }
}

//overloaded constructor for density input: creates grid with random occupancy based on density
Grid::Grid(int height, int width, double density){
  m_height = height;
  m_width = width;

  //create 2D pointer array of Cells
  m_grid = new Cell*[m_height];

  for(int i = 0; i < m_height; ++i)
      m_grid[i] = new Cell[m_width];

  srand(time(0));//use current time as random seed

  int numOccupiedCells = density * (m_height * m_width);//calculate  number of cells to occupy
  int currNumOccupiedCells = 0;

  while(currNumOccupiedCells < numOccupiedCells){
    int randomHeight = rand() % m_height;//pick random height index
    int randomWidth = rand() % m_width;//pick random width index
    if(!((m_grid[randomHeight][randomWidth]).isOccupied())){//if cell not occupied, set occupied and increment number of occupied cells
      (m_grid[randomHeight][randomWidth]).setOccupied();
      ++currNumOccupiedCells;
    }
  }
}

// destructor
Grid::~Grid(){
  // delete 2D pointer array of cells
  for (int i = 0; i < m_height; ++i){
    delete [] m_grid[i];
  }
  delete [] m_grid;
}

// prints grid in user friendly format
void Grid::printGrid(){
  for(int i = 0; i < m_height; ++i){
    if(i != 0)
      cout << endl;
    for(int j = 0; j < m_width; ++j){
      cout << (m_grid[i][j]).getValue();
    }
  }
  cout << endl;
}

// gets grid height
int Grid::getHeight(){
  return m_height;
}

// gets grid width
int Grid::getWidth(){
  return m_width;
}

// checks if cell is occupied
bool Grid::isSpecifiedCellOccupied(int height, int width){
  return ((m_grid[height-1][width-1]).isOccupied());
}

// sets grid cell occupied
void Grid::setCellOccupied(int height, int width){
  m_grid[height-1][width-1].setOccupied();
}

// sets grid cell empty
void Grid::setCellEmpty(int height, int width){
  m_grid[height-1][width-1].setEmpty();
}

// returns string of grid elements
string Grid::getGridString(){
  string gridString = "";

  for(int i = 0; i < m_height; ++i){
    if(i != 0)
      gridString += "\n";
    for(int j = 0; j < m_width; ++j){
      gridString += (m_grid[i][j]).getValue();
    }
  }
  gridString += "\n";
  return gridString;
}

// returns specified cell's data
char Grid::getSpecifiedCellData(int height, int width){
  return m_grid[height][width].getValue();
}