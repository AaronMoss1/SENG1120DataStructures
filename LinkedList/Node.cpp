//Node.cpp: Node Cpp file
//***************************
//Author: Aaron Moss
//Student Number: c3282382
//Date Updated: 6/09/19
//Course: SENG1120- Data Structures
//Program Description: Contains implementation of Node functionalities

#include "Node.h"
#include <cstdlib>

//Constructor
Node::Node()
{
    Next = NULL;
    Previous = NULL;
}

//Destructor
Node::~Node() {
    Next = NULL;
    Previous = NULL;
}

//Setters
void Node::SetData(Node::StuData data) //Student data type is passed in, and student data type is assigned to the node
{
    Data = data;
}

void Node::SetNext(Node *next) //Setting the next node in the list
{
    Next = next;
}

void Node::SetPrev(Node *prev) //Setting the previous node in the list
{
    Previous = prev;
}

//Getters
Node* Node::GetNext() const
{
    return Next;
}

Node* Node::GetPrev() const
{
    return Previous;
}

Node::StuData Node::GetData()
{
    return Data;
}

