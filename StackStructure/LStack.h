//Node.h: Node Header File
//***************************
//Author: Aaron Moss
//Student Number: c3282382
//Date Updated: 6/09/19
//Course: SENG1120- Data Structures
//Program Description: Contains methods / functions to be defined and implemented to give functionality of a stack for tower hanoi game

#ifndef C3282382_LSTACK_H
#define C3282382_LSTACK_H

#include <string>
#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
using namespace std;

template <typename value_type>
class LStack
{
public:
    //constructor
    LStack() {
        list = new LinkedList<value_type>; //new list is created when a stack is initialised
        used = 0; //amount of space used on the stack
    }

    //Destructor
    ~LStack() {
        delete list; //destructor deletes the list of the stack which removes the underlying data structure
    }

    void Push(const value_type& entry)
    {
        list->addToHead(entry);
        used++;
    }
	//Pre Conditions: Value type is valid
    //Post Conditions: A new item is added to the top of the stack

    value_type Pop()
    {
        if(!isEmpty()) {
            value_type RemovedHead = list->GetHeadData();
            list->RemoveFromHead();
            used--; //used decreases as a value is of the stack
            return RemovedHead; //returns the removed head value
        }
        else
            return ""; //returns empty string
    }
	//Pre Conditions: a value exists in the stack
    //Post Conditions: the value is removed from the stack and then returned

	//check if stack is empty
    bool isEmpty() const
    {
        if(Size() == 0)
            return true;
        else
            return false;
    }
	//Pre Conditions: None
    //Post Conditions: returns true if stack is empty, false if otherwise

    int Size() const
    {
        return used;
    }
	//Pre Conditions: None
    //Post Conditions: Size of the stack is returned

    value_type Peek()
    {
        if(!isEmpty())
        {
            return list->GetHeadData();
        }
        else
            return "";
    }
	//Pre Conditions: None
    //Post Conditions: data of the head of the stack is returned

private:
    LinkedList<value_type>* list;
    int used;
};

template <typename value_type>
ostream& operator << (ostream& out, LStack<value_type>* stack)
{
    LStack<value_type>* temp = new LStack<value_type>; //temp stack created
    int size = stack->Size(); //size is given the value of the size of the stack passed in
    for(int i = 0; i < size; i++) //iterating over the whole stack
    {
        temp->Push(stack->Pop()); //adding to temp, while deleting from stack, to then print the head of temp
        out << temp->Peek() << endl;
    }
    //place contents back into the stack
    for(int i = 0; i < size; i++)
    {
        stack->Push(temp->Pop());
    }
    delete temp;
    return out;
}

#endif //C3282382_LSTACK_H
