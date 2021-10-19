// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* main.cpp contains the main method and creates an instance of the ClassicModeGame, DoughnutModeGame, MirrorModeGame, 
and UserInput classes in order to facilitate the game of life simulation. IT prompts the user for three main inupts:
1) configuration type: 'r' for random configuration or 'm' to import a configuration from a map file
2) boundary mode: 'c' for classic mode, 'd' for doughnut mode, or 'm' for mirror mode
3) output preference: 'p' for console output with a pause between generations, 'e' for console output with a pause 
   until the 'enter' key is pressed between generations, or 'f' for output to a specified file
*/

#include <iostream>
#include "ClassicModeGame.h"
#include "DoughnutModeGame.h"
#include "MirrorModeGame.h"
#include "UserInput.h"
using namespace std;

int main(int argc/*number of arguments*/, char** argv/*array*/){

  // welcome message
  cout << endl;
  cout << "–––WELCOME TO THE GAME OF LIFE–––" << endl;
  cout << endl;

  // get configuration
  cout << "Begin by specifying a configuration type." << endl;
  cout << "Input 'r' for random configuration or 'm' to import a configuration from a map file." << endl;
  cout << endl;
  cout << "Configuration type: ";
  
  string configuration = "";
  
  cin >> configuration;
  
  while(configuration != "r" && configuration != "m"){// input protection
    cout << "ERROR: Invalid configuration input." << endl;
    cout << "Input 'r' for random configuration or 'm' to import a configuration from a map file." << endl;
    cout << endl;
    cout << "Configuration type: ";
    cin >> configuration;
  }

  char configurationChar = configuration[0];//make char

  cout << endl;

  int height = 0;
  int width = 0;
  double density = 0.0;
  string gridString = "";

  // set height, width, density, and/or grid occupancy based on user input
  switch (configurationChar){
  case 'r'://random
    {
    UserInput *ui = new UserInput();

    height = ui->getHeightNum();
    width = ui->getWidthNum();
    density = ui->getDensityNum();

    delete ui;
    break;
    }
  case 'm'://map
    {
    FileProcessor *fp = new FileProcessor();
    while(fp->processMapFile() == -1){}

    height = fp->getMapHeight();
    width = fp->getMapWidth();
    gridString = fp->getGridString();
    cout << endl;

    delete fp;
    break;
    }
  }

  // get boundary mode
  cout << "Now, please choose a boundary mode." << endl;
  cout << "Input 'c' for classic mode, 'd' for doughnut mode, or 'm' for mirror mode." << endl;
  cout << endl;
  cout << "Boundary mode: ";

  string boundaryMode = "";
  
  cin >> boundaryMode;

  while(boundaryMode != "c" && boundaryMode != "d" && boundaryMode != "m"){//input protection
    cout << "ERROR: Invalid boundary mode input." << endl;
    cout << "Input 'c' for classic mode, 'd' for doughnut mode, or 'm' for mirror mode." << endl;
    cout << endl;
    cout << "Boundary mode: ";
    cin >> boundaryMode;
  }

  char boundaryModeChar = boundaryMode[0];//make char

  cout << endl;

  // get output preference
  cout << "Finally, please choose an output preference." << endl;
  cout << "Input 'p' for console output with a pause between generations, 'e' for console output with a pause until the 'enter' key \nis pressed between generations, or 'f' for output to a specified file." << endl;
  cout << endl;
  cout << "Output preference: ";

  string outputPref = "";
  
  cin >> outputPref;

  while(outputPref != "p" && outputPref != "e" && outputPref != "f"){//input protection
    cout << "ERROR: Invalid output preference input." << endl;
    cout << "Input 'p' for console output with a pause between generations, 'e' for console output with a pause until the 'enter' key \nis pressed between generations, or 'f' for output to a specified file." << endl;
    cout << endl;
    cout << "Output preference: ";
    cin >> outputPref;
  }

  char outputPrefChar = outputPref[0];//make char

  cout << endl;

  // start game based on the input by user: configuration, boundary mode, and output preference
  switch (boundaryModeChar){
  case 'c':
    {
    ClassicModeGame *cmg;
    if(configurationChar == 'r'){
      cmg = new ClassicModeGame(height, width, density);
    }
    else if(configurationChar == 'm'){
      cmg = new ClassicModeGame(height, width, gridString);
    }
    cmg->startGame(outputPrefChar);
    delete cmg;
    break;
    }
  case 'd':
    {
    DoughnutModeGame *dmg;
    if(configurationChar == 'r'){
      dmg = new DoughnutModeGame(height, width, density);
    }
    else if(configurationChar == 'm'){
      dmg = new DoughnutModeGame(height, width, gridString);
    }
    dmg->startGame(outputPrefChar);
    delete dmg;
    break;
    }
  case 'm':
    {
    MirrorModeGame *mmg;
    if(configurationChar == 'r'){
    mmg = new MirrorModeGame(height, width, density);
    }
    else if(configurationChar == 'm'){
      mmg = new MirrorModeGame(height, width, gridString);
    }
    mmg->startGame(outputPrefChar);
    delete mmg;
    break;
    }
  }

  return 0;
}
