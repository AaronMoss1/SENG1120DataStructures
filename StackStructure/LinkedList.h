//LinkedList.h: Linked List Header File
//***************************
//Author: Aaron Moss
//Student Number: c3282382
//Date Updated: 6/09/19
//Course: SENG1120- Data Structures
//Program Description: Contains Methods/Functions to be used by LStack class

#ifndef C3282382_LINKEDLIST_H
#define C3282382_LINKEDLIST_H

#include <string>
#include <cstdlib>
#include <iostream>
#include "Node.h"
using namespace std;

template <typename value_type>
class LinkedList
{
public:
	//constructor
    LinkedList()
    {
        Head = NULL;
        Tail = NULL;
        Current = NULL;
        ListSize = 0;
    }
	//destructor
    ~LinkedList()
    {
        Node<value_type>* ptr = Head; //Pointer to head of list
        Node<value_type>* Temp;
        while(ptr != NULL) //iterating nodes
        {
            Temp = ptr->GetNext(); //temp node points to the next node in list
            delete ptr; //deletes ptr
            ptr = Temp;
        }
        Head = NULL; //setting all linked list values to NULL
        Tail = NULL;
        Current = NULL;
        ListSize = 0;
    }

    value_type GetHeadData() const
    {
        return Head->GetData();
    }
	//Pre Conditions: None
    //Post Conditions: returns the data of the head node

    int GetListSize()
    {
        return ListSize;
    }
    //Pre Conditions: None
    //Post Conditions: Returns size of specified list size

    void addToHead(value_type data)
    {
        if(GetListSize() == 0) //if list is empty
        {
            Node<value_type>* node = new Node<value_type>(); //empty node that will be head and tail of the list
            Head = node;
            Tail = node;
            node ->SetPrev(NULL); //setting next and prev as null as this node is the only node in list
            node ->SetNext(NULL);
            node ->SetData(data);
            ListSize++; //increase size due to another node being added
        }
        else //if there is 1 or more items in the list
        {
            Node<value_type>* node = new Node<value_type>(); //new node is created
            node ->SetData(data);
            Head ->SetPrev(node);
            node ->SetNext(Head); //Next node is head as the node created is the new head
            Head = node;
            ListSize++;
        }
    }
    //Pre Conditions: value_type data is passed in, this is the data to be associated with this node
    //Post Conditions: adds the created node to the head of the list

    void RemoveFromHead()
    {
        if(Head != NULL)
        {
            if (Head->GetNext() != NULL) //if there is more than 1 item in the list
            {
                Head = Head->GetNext(); //Next item in the list is the new head
                //delete Head->GetPrev();
                Head->SetPrev(NULL); //Previous of the head is now null, as the old head is deleted
                delete Head->GetPrev();
                ListSize--; //list size decrease
            }
            else {
                Head = NULL; //all values set to null;
                Tail = NULL;
                ListSize--;
            }
        }
    }
    //Pre Conditions: A head exists
    //Post Conditions: Removes a header from the list

private:
    Node<value_type>* Head; //Head, tail and current all nodes with a specified value type
    Node<value_type>* Tail;
    Node<value_type>* Current;
    int ListSize;
};


//ostream Out
template <typename value_type>
ostream&  operator <<(ostream& out, LinkedList<value_type>& list) //overload print
{
    list.CurrentToHead();
    for(int i = 0; i < list.GetListSize(); i++) //loops through entire list
    {
        out << list.GetCurrentData(); //prints data from list
        list.CurrentToNext();
    }
    return out;
}
#endif //C3282382_LINKEDLIST_H
