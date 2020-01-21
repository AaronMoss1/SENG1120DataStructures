//TowerHanoi.cpp
//***************************
//Author: Aaron Moss
//Student Number: c3282382
//Date Updated: 18/10/19
//Course: SENG1120- Data Structures
//Program Description: Contains implementation from the towerHanoi .h file functions

#include "TowerHanoi.h"
#include "LStack.h"
#include <cstdlib>
#include <string>

TowerHanoi::TowerHanoi(int numberOfDisks)
{
    Stack1 = new LStack<string>; //3 instances of stack are created, each initialising values for the stack 
    Stack2 = new LStack<string>;
    Stack3 = new LStack<string>;
    SetOriginalSize(numberOfDisks); //original Size is set and can be used later in the application
    string Disk;
    switch (numberOfDisks) { //number of disks is passed in, each number returns a different string representing disks for the stack
        case 1:
            Disk = "x";
            break;
        case 2:
            Disk = "xxx";
            break;
        case 3:
            Disk = "xxxxx";
            break;
        case 4:
            Disk = "xxxxxxx";
            break;
        case 5:
            Disk = "xxxxxxxxx";
            break;
        case 6:
            Disk = "xxxxxxxxxxx";
            break;
    }
    for (int i = 0; i < numberOfDisks; i++) { //adding to the first stack to start the game
        Stack1->Push(Disk);
        Disk = Disk.erase(0, 2); //2 values are taken off the string each time the loop runs, as the stack above has 2 less disks, and a stack below has 2 more discs
    }
}

//sets the original size of the stack, which is user defined at the start of the game
void TowerHanoi::SetOriginalSize(int num)
{
    originalSize = num;
}
//returns the set original size
int TowerHanoi::GetOriginalSize()
{
    return originalSize;
}

//checks to see if the game is eligible to end
bool TowerHanoi::checkWin()
{
    if(Stack3->Size() == GetOriginalSize()) //if the size of stack3 is the same size as rod 1 at the start of the game
        return true;
    else
        return false;
}

//destructor for tower hanoi
TowerHanoi::~TowerHanoi()
{
    delete Stack1; //deletes all 3 stacks after the game is completed
    delete Stack2;
    delete Stack3;
}

//moves a disc from one rod to another if valid
void TowerHanoi::move(int from, int to)
{
    string rodSource, rodDestination; 
    int RodFromNo = from; //rod from and rod to are given int values
    int RodToNo = to;
    int rodMoveSource, rodMoveDest;
    if(from < 1 || from > 3 || to < 1 || to > 3) //checking to see if the input is valid
    {
        cout << "Invalid Entry, Must Input With The Rods Available, There Are Rods 1-3 Available!" << endl;
        return; //returns the user back to the program and prompts for another input
    }
    else if(from == to) { //if from and to are the same value
        cout << "Can Not Move Disks To The Same Rod!" << endl;
        return;
    }
    else //rod input is valid
    {
        if(RodFromNo == 1) { //checking the rod from number
            if(Stack1->isEmpty()) //if the stack is empty (no disc) provide an error message and return, this is done for all 3 stacks
            {
                cout << "Can Not Move Disk From Empty Rod!" << endl;
                return;
            }
            else {
                rodSource = Stack1->Peek();
                rodMoveSource = 1;
            }
        }
        else if(RodFromNo == 2) {
            if(Stack2->isEmpty())
            {
                cout << "Can Not Move Disk From Empty Rod!" << endl;
                return;
            }
            else {
                rodSource = Stack2->Peek();
                rodMoveSource = 2;
            }
        }
        else {
            if(Stack3->isEmpty())
            {
                cout << "Can Not Move Disk From Empty Rod!" << endl;
                return;
            }
            else {
                rodSource = Stack3->Peek();
                rodMoveSource = 3;
            }
        }
        //rodSource String Value is given the value of the from Rod
        if(RodToNo == 1) {
            if(Stack1->isEmpty())
            {
                rodDestination = "xxxxxxxxxxxx";
                //12 x's, this indicates a non-existant 7th disk which is not allowable in game, but returns false for size check and pushes the source to destination automatically
            }
            else {
                rodDestination = Stack1->Peek();
            }
            rodMoveDest = 1;
        }
        else if(RodToNo == 2) {
            if(Stack2->isEmpty())
            {
                rodDestination = "xxxxxxxxxxxx";
                //12 x's, this indicates a non-existant 7th disk which is not allowable in game, but returns false for size check and pushes the source to destination automatically
            }
            else {
                rodDestination = Stack2->Peek();
            }
            rodMoveDest = 2;
        }
        else {
            if(Stack3->isEmpty())
            {
                rodDestination = "xxxxxxxxxxxx";
                //12 x's, this indicates a non-existant 7th disk which is not allowable in game, but returns false for size check and pushes the source to destination automatically
            }
            else {
                rodDestination = Stack3->Peek();
            }
            rodMoveDest = 3;
        }
        //rodDestination String Value is given the value of the to Rod
        if(rodSource.size() > rodDestination.size()) //checking the size of the disk of destination
        {
            cout << "Unable To Move Disk! The Top Of The Rod You Are Moving To Is Larger Than The Disk You Are Moving!" << endl;
            return;
        }
        else{
            if(rodMoveSource == 1) { //the source rod is rod 1
                if(rodMoveDest == 2) //player wants to move from rod 1 to rod 2
                {
                    Stack2->Push(Stack1->Pop());
                    return;
                }
                else if(rodMoveDest == 3) //player wants to move from rod 1 to rod 3
                {
                    Stack3->Push(Stack1->Pop());
                    return;
                }
            }
            else if(rodMoveSource == 2) { //the source rod is rod 2
                if(rodMoveDest == 1) //player wants to move from rod 2 to rod 1
                {
                    Stack1->Push(Stack2->Pop());
                    return;
                }
                else if(rodMoveDest == 3) //player wants to move from rod 2 to rod 3
                {
                    Stack3->Push(Stack2->Pop());
                    return;
                }
            }
            else { //the source rod is rod 3
                if(rodMoveDest == 1) //player wants to move from rod 3 to rod 1
                {
                    Stack1->Push(Stack3->Pop());
                    return;
                }
                else if(rodMoveDest == 2) //the player wants to move from rod 3 to rod 2
                {
                    Stack2->Push(Stack3->Pop());
                    return;
                }
            }
        } //end string size else check / push and pop segment
    } //end valid rod input check
} //end function

//function that prints the current state of the game
void TowerHanoi::PrintGame()
{
    int space;
    int Stack1Size = Stack1->Size(); //stack 1-3 are given values based on the size of the rod
    int Stack2Size = Stack2->Size();
    int Stack3Size = Stack3->Size();
    LStack<string>* temp1 = new LStack<string>; //temp string stacks are created
    LStack<string>* temp2 = new LStack<string>;
    LStack<string>* temp3 = new LStack<string>;
    //Stack one printing
    cout << "Stack 1:" << endl;
    if(Stack1Size == 0)
        cout << "Stack Empty!" << endl << endl; //2 line space after print
    else {
        for (int i = 1; i <= Stack1Size; ++i) {
            temp1->Push(Stack1->Pop());
            for (space = 1; space <= Stack1Size - i; ++space) {
                cout << " ";
            }
            cout << temp1->Peek() + " " << endl;
        }
        cout << endl;
    }
	//end stack 1 printing
    //Stack two printing
    cout << "Stack 2:" << endl;
    if(Stack2Size == 0)
        cout << "Stack Empty!" << endl << endl; //2 line space after print
    else {
        for (int i = 1; i <= Stack2Size; ++i) {
            temp2->Push(Stack2->Pop());
            for (space = 1; space <= Stack2Size - i; ++space) {
                cout << " ";
            }
            cout << temp2->Peek() + " " << endl;
        }
        cout << endl;
    }
    //end stack 2 printing
    //Stack three printing
    cout << "Stack 3:" << endl;
    if(Stack3Size == 0)
        cout << "Stack Empty!" << endl << endl; //2 line space after print
    else {
        for (int i = 1; i <= Stack3Size; ++i) {
            temp3->Push(Stack3->Pop());
            for (space = 1; space <= Stack3Size - i; ++space) {
                cout << " ";
            }
            cout << temp3->Peek() + " " << endl;
        }
        cout << endl;
    }
    //end stack 3 printing
    //place contents back to stack 1
    for(int i = 0; i < Stack1Size; i++)
    {
        Stack1->Push(temp1->Pop());
    }
    //place contents back to stack 2
    for(int i = 0; i < Stack2Size; i++)
    {
        Stack2->Push(temp2->Pop());
    }
    //place contents back to stack 3
    for(int i = 0; i < Stack3Size; i++)
    {
        Stack3->Push(temp3->Pop());
    }
    delete temp1; //deletes the temps
    delete temp2;
    delete temp3;
}

//print current state of the game
ostream& operator <<(ostream& out, TowerHanoi& gamePrint)
{
    cout << endl;
    gamePrint.PrintGame();
    cout << endl;
    return out;
}
