// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* FileProcessor.h is a header file which lays out the elements of the FileProcessor class. */

#include <iostream> //pre-processor directive
#include <fstream>
#include "Grid.h"
using namespace std;

class FileProcessor{
  private:
    int m_mapHeight;
    int m_mapWidth;
    string m_gridString;
    
    string m_outputFile;

  public:
    FileProcessor();//default constructor
    ~FileProcessor();//destructor

    // processes a map file that is inputted by user and returns an int: 0 for successful and -1 for unsuccessful
    int processMapFile();
    // creates an output file that is inputted by user and returns an int: 0 for successful and -1 for unsuccessful
    int createOutputFile(int generationNum, string generationStr);
    // checks if string is an +integer
    bool isPosInt(string maybeInt);

    // getters
    // returns map file grid height
    int getMapHeight();
    // returns map file grid width
    int getMapWidth();
    // returns map file grid string
    string getGridString();
};
