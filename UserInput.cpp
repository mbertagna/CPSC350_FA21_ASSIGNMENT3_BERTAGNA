// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 3

/* UserInput.cpp contains the implementation of the UserInput class. It implements a constructor, a destructor, and five functions:
1) getHeightNum: gets height value from user and provides input protection
2) getWidthNum: gets width value from user and provides input protection
3) getDensityNum: gets density value from user and provides input protection
4) isPosInt: checks if string is an +integer
5) isPosDouble0to1: checks if string is a +double in range (0,1]
*/

#include "UserInput.h"

//default constructor
UserInput::UserInput(){}

//destructor
UserInput::~UserInput(){}

// gets height value from user and provides input protection
int UserInput::getHeightNum(){
    string num = "";
    cout << "Grid Height: ";
    cin >> num;
    while(!(isPosInt(num))){
        cout << "ERROR: Please input an integer value that is greater than zero." << endl;
        cout << "Grid Height: ";
        cin >> num;
    }
    int intNum = std::stoi(num);
    return intNum;
}

// gets width value from user and provides input protection
int UserInput::getWidthNum(){
    string num = "";
    cout << "Grid Width: ";
    cin >> num;
    while(!(isPosInt(num))){
        cout << "ERROR: Please input an integer value that is greater than zero." << endl;
        cout << "Grid Width: ";
        cin >> num;
    }
    int intNum = std::stoi(num);
    return intNum;
}

// gets density value from user and provides input protection
double UserInput::getDensityNum(){
    string num = "";
    cout << "Grid Density: ";
    cin >> num;
    while(!(isPosDouble0to1(num))){//checks if valid input
        cout << "ERROR: Please input an decimal value that is greater than zero and less than or equal to one." << endl;
        cout << "Grid Density: ";
        cin >> num;
    }
    double doubleNum = std::stod(num);
    return doubleNum;
}

// checks if string is an +integer
bool UserInput::isPosInt(string maybeInt){
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

// checks if string is a +double in range (0,1]
bool UserInput::isPosDouble0to1(string maybeDouble){
    int decimalPoint = false;//checks if decimal point found yet

    if(maybeDouble.length() == 0)//return false if string has length zero
        return false;

    for(int i = 0; i < maybeDouble.length(); ++i){//loop through chars in string
        if(!(isdigit(maybeDouble[i]))){//if char is not numeric run body
            if(maybeDouble[i] == '.' && decimalPoint == false){//if it is decimal point and decimal point not found yet, set decimalPoint = true
                decimalPoint = true;
            }
            else{//return false if char is not numeric and not decimal or if multiple decimal points
                return false;
            }
        }
    }
    if(maybeDouble == ".")
        return false;

    if(std::stod(maybeDouble) <= 0 || std::stod(maybeDouble) > 1)//if decimal value is not within (0,1]
        return false;
    
    return true;//if decimal value is within (0,1]
}