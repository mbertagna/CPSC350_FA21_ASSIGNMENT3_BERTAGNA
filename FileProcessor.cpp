// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* FileProcessor.cpp contains the implementation of the FileProcessor class. It implements a constructor, a destructor, and six functions:
1) processMapFile: processes a map file that is inputted by user and returns an int: 0 for successful and -1 for unsuccessful
2) createOutputFile: creates an output file that is inputted by user and returns an int: 0 for successful and -1 for unsuccessful
3) isPosInt: checks if string is an +integer
4) getMapHeight: returns map file grid height
5) getMapWidth: returns map file grid width
6) getGridString: returns map file grid string
*/

#include "FileProcessor.h"

FileProcessor::FileProcessor(){
  m_mapWidth = 0;
  m_mapHeight = 0;
  m_gridString = "";
  m_outputFile = "";
}

FileProcessor::~FileProcessor(){
}

// processes a map file that is inputted by user and returns an int: 0 for successful and -1 for unsuccessful
int FileProcessor::processMapFile(){
  ifstream inFS;// input file stream

  string mapFilePath;

  cout << "Path to input file: ";

  cin >> mapFilePath;

  inFS.open(mapFilePath);// open input file

  // if input file cannot be opened print error to user and return -1(file error)
  if (!inFS.is_open()) {
     cout << "ERROR: Could not open the input file in path: " << mapFilePath << "." << endl << "Please provide a valid path to the input file." << endl;
     return -1;
  }
  // if file successfully opened, read generation 0
  else{
    string heightStr = "";
    string widthStr = "";

    getline(inFS, heightStr);// store first line in file data: height
    getline(inFS, widthStr);// store second line in file data: width

    if(!(isPosInt(heightStr) && isPosInt(widthStr))){//return false if first two lines not +integers
      cout << "ERROR: The inputted file has incorrect formatting. Please choose an input file with correct format." << endl;
      return -1;
    }
    
    m_mapHeight = std::stoi(heightStr);
    m_mapWidth = std::stoi(widthStr);

    string rowStr;

    // loop until all rows parsed or the filestream is empty
    for(int i = 0 ; i < m_mapHeight ; ++i){
      if(inFS.fail()){//return -1 if grid does not have proper amount of rows
        cout << "ERROR: The inputted file has incorrect formatting. Please choose an input file with correct format." << endl;
        return -1;
      }
      getline(inFS, rowStr);// store next line in file data
      if(rowStr.length() != m_mapWidth){//return -1 if grid does not have proper amount of columns
        cout << "ERROR: The inputted file has incorrect formatting. Please choose an input file with correct format." << endl;
        return -1;
      }
      m_gridString += rowStr;
    }

    for(int i = 0 ; i < m_gridString.length() ; ++i){
      if(m_gridString[i] != 'X' && m_gridString[i] != '-'){//if chars in string not 'X' or '-', return -1
        cout << "ERROR: The inputted file has incorrect formatting. Please choose an input file with correct format." << endl;
        return -1;
      }
    }

    return 0;//return 0 if successful
  }
  inFS.close();// close input file stream
}

// creates an output file that is inputted by user and returns an int: 0 for successful and -1 for unsuccessful
int FileProcessor::createOutputFile(int generationNum, string generationStr){
  ofstream outFS;// output file stream

  if(m_outputFile == ""){
    cout << "Path to output file: ";

    cin >> m_outputFile;

    outFS.open(m_outputFile);// open output file and overwrite
  }
  else{
    outFS.open(m_outputFile, std::ios_base::app);// open output file for appending
  }

  // if output file cannot be opened print error to user and do nothing else
  if (!outFS.is_open()) {
     cout << "ERROR: Could not open the input file in path: " << m_outputFile << "." << endl << "Please provide a valid output file." << endl;
     return -1;
     m_outputFile == "";
  }
  // if file successfully opened begin writing to file
  else{
      if(generationNum == 0){
        outFS << generationNum << endl;
      }
      else{
        outFS << "Generation: " << generationNum << endl;
      }
      outFS << generationStr << endl;
  }

  outFS.close();// close output file stream
}

// checks if string is an +integer
bool FileProcessor::isPosInt(string maybeInt){
    if(maybeInt.length() == 0)//return false if string has length zero
        return false;
    
    for(int i = 0; i < maybeInt.length(); ++i){//loop through chars in string
        if(!(isdigit(maybeInt[i])))//if char is not numeric return false
            return false;
    }

    if(std::stoi(maybeInt) <= 0)//if decimal value is not > 0
        return false;

    return true;//if all numeric and > 0
}

// returns map file grid height
int FileProcessor::getMapHeight(){
  return m_mapHeight;
}

// returns map file grid width
int FileProcessor::getMapWidth(){
  return m_mapWidth;
}

// returns map file grid string
string FileProcessor::getGridString(){
  return m_gridString;
}
