//TowerHanoi.h: TowerHanoi Header File
//***************************
//Author: Aaron Moss
//Student Number: c3282382
//Date Updated: 18/10/19
//Course: SENG1120- Data Structures
//Program Description: Contains methods / functions to be defined and implemented in the TowerHanoi.cpp file

#ifndef C3282382_TOWERHANOI_H
#define C3282382_TOWERHANOI_H

#include <string>
#include <cstdlib>
#include "LStack.h"
class TowerHanoi
{
public:
    //Constructor
    TowerHanoi(int numberOfDisks);

    //Destructor
    ~TowerHanoi();

    //Move one disc from one rod to another rod
    void move(int from, int to);
	//Pre Conditions: a disk exists and the from and to are valid to be passed between each other
    //Post Conditions: the disc will be moved to another rod or an error message will be passed to the user

    //boolean that returns true if all discs have reached the third rod
    bool checkWin();
	//Pre Conditions: None
    //Post Conditions: the game is ended if true is returned, continues if false

    void SetOriginalSize(int num);
	//Pre Conditions: num is passed in which represents the number of disks the user begins the game with
    //Post Conditions: the originalSize is set, which is then used throughout the program to get the amount of starting disks

    int GetOriginalSize();
	//Pre Conditions: None
    //Post Conditions: returns the set original Size value

    //function that prints the current state of the game
    void PrintGame();
	//Pre Conditions: None
    //Post Conditions: current state of the game is printed

private:
    LStack<string>* Stack1; //3 instances of stack, representing 1 rod for each stack
    LStack<string>* Stack2;
    LStack<string>* Stack3;
    int originalSize; //original size is used to store amount of starting disks
};
ostream& operator << (ostream& out, TowerHanoi& gamePrint);
#endif //C3282382_TOWERHANOI_H
