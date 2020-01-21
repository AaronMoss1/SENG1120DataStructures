//LinkedList.h: Linked List Header File
//***************************
//Author: Aaron Moss
//Student Number: c3282382
//Date Updated: 6/09/19
//Course: SENG1120- Data Structures
//Program Description: Contains Methods/Functions to be defined in the Linked List CPP

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <string>
#include <iostream>
#include <cstdlib>
#include "Node.h"
class LinkedList
{
public:
    //Constructor
    LinkedList();
    //Destructor
    ~LinkedList();

    //Remove Functions
    void remove(string name);
    //Pre Conditions: Recieves a string which will be the name of the item (Student) they wish to remove
    //Post Conditions: If the item is in the list, the item will be removed, if it is not in the list it will disregard the statement
    void RemoveFromHead();
    //Pre Conditions: A head exists
    //Post Conditions: Removes a header from the list
    void RemoveFromTail();
    //Pre Conditions: A tail exists
    //Post Conditions: Removes the tail from the list
    void RemoveFromCurrent();
    //Pre Conditions: An item exists that is not the head, or the tail
    //Post Conditions: Removes a Node from somewhere in between the Head and the Tail

    //Insert Functions
    void addToHead(Node::StuData data);
    //Pre Conditions: Student Data is passed in
    //Post Conditions: A Node of Student Data Type is inserted at the head of a list
    void addToTail(Node::StuData data);
    //Pre Conditions: Student Data is passed in
    //Post Conditions: A Node of Student Data Type is inserted at the tail of a list

    //Current Sliders
    void CurrentToNext();
    //Pre Conditions: None
    //Post Conditions: Current is moved to the next node
    void CurrentToPrevious();
    //Pre Conditions: None
    //Post Conditions: Current is moved to the previous node
    void CurrentToHead();
    //Pre Conditions: None
    //Post Conditions: Current is moved to the head of the list
    void CurrentToTail();
    //Pre Conditions: None
    //Post Conditions: Current is moved to the tail of the list

    //Getters
    Node* GetHead() const;
    //Pre Conditions: None
    //Post Conditions: Returns head of linked list
    Node* GetTail() const;
    //Pre Conditions: None
    //Post Conditions: Returns tail of linked list
    Node::StuData GetCurrentData() const;
    //Pre Conditions: None
    //Post Conditions: Returns data associated with the current node
    int GetListSize() const;
    //Pre Conditions: None
    //Post Conditions: Returns size of specified list

    //Count Function
    int count(string const name);
    //Pre Conditions: A name of the Node (Student) is passed in that the user wants counted
    //Post Conditions: Instances of the name are counted in the list, adds 1 for each instance found and returns an int with the total

    //Concat
    void operator +=(LinkedList& linkedList);
    //Pre Conditions: Existing linked list is passed in
    //Post Conditions: Element on the left of the operator has each right hand operator element added to the tail

    //Remove List Contents
    void operator -=(LinkedList& linkedList);
    //Pre Conditions: Existing linked list is passed in
    //Post Conditions: If an element that exists in the passed in linked list is found in the other list (left hand operator), it is removed


private:
    Node* Head; //Head of the linked list
    Node* Tail; //Tail of the linked list
    Node* Current; //Current to allow movement throughout items in the list
    int ListSize; //An integer type that stores the length of a list created
};
ostream& operator <<(ostream&, LinkedList& linkedList); //allows for printing of the linked list by overloading this operator

#endif //LINKEDLIST_LINKEDLIST_H

