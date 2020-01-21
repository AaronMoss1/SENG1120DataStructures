//Node.h: Node Header File
//***************************
//Author: Aaron Moss
//Student Number: c3282382
//Date Updated: 6/09/19
//Course: SENG1120- Data Structures
//Program Description: Contains methods / functions to be defined and implemented in the Node.cpp file

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

#include "Student.h"
class Node
{
public:
    //Student Typedef
    typedef Student StuData;

    //Constructors
    Node();

    //Destructor
    ~Node();

    //Setters
    void SetNext(Node* next);
    //Pre Conditions: Node is passed in
    //Post Conditions: Whatever is passed in is created to be the next element of the current node
    void SetPrev(Node* prev);
    //Pre Conditions: Node is passed in
    //Post Conditions: Whatever is passed in is created to be the previous element of the current node
    void SetData(StuData data);
    //Pre Conditions: Node is passed in
    //Post Conditions: Whatever is passed in is setting data of student type for the current node

    //Getters
    Node* GetNext() const;
    //Pre Conditions: None
    //Post Conditions: Returns the Next Node in list
    Node* GetPrev() const;
    //Pre Conditions: None
    //Post Conditions: Returns Previous of linked list
    StuData GetData();
    //Pre Conditions: None
    //Post Conditions: Gets the Data of the node which is of the type Student

private:
    Node* Next;
    Node* Previous;
    StuData Data; //Data is of type Student
};
#endif //LINKEDLIST_NODE_H

