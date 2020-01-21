//LinkedList.cpp: Linked List Cpp file
//***************************
//Author: Aaron Moss
//Student Number: c3282382
//Date Updated: 6/09/19
//Course: SENG1120- Data Structures
//Program Description: Contains implementation of linked list functionalities

#include "LinkedList.h"
#include "Node.h"
#include <cstdlib>

//Constructor of linked list
LinkedList::LinkedList()
{
    Head = NULL;
    Tail = NULL;
    Current = NULL;
    ListSize = 0; //All Data set to null and size set to 0 as its an empty list
}

//Destructor
LinkedList::~LinkedList()
{
    Node* ptr = Head; //Pointer to head of list
    Node* Temp;
    while(ptr != NULL)
    {
        Temp = ptr->GetNext(); //temp node points to the next node in list
        delete ptr; //deletes ptr
        ptr = Temp;
    }
    Head = NULL;
    Tail = NULL;
}

//Getters
Node* LinkedList::GetHead() const
{
    return Head;
}

Node* LinkedList::GetTail() const
{
    return Tail;
}

Node::StuData LinkedList::GetCurrentData() const
{
    return Current->GetData();
}

int LinkedList::GetListSize() const
{
    return ListSize;
}

//Current Sliders
void LinkedList::CurrentToHead()
{
    Current = Head;
}

void LinkedList::CurrentToTail()
{
    Current = Tail;
}

void LinkedList::CurrentToNext()
{
    Current = Current->GetNext();
}

void LinkedList::CurrentToPrevious()
{
    Current = Current->GetPrev();
}

//add to tail
void LinkedList::addToTail(Node::StuData data)
{
    if(GetListSize() == 0) //if the list is empty
    {
        Node* node = new Node(); //create blank node and add data to it
        Head = node;
        Tail = node;
        node->SetPrev(NULL); //previous and next are null, as this is the only node, meaning it is both head and tail
        node->SetNext(NULL);
        node->SetData(data);
        ListSize++; //increase list size as something has been added
    }
    else //if there is 1 or more items in the list
    {
        Node* node = new Node();
        node->SetData(data);
        Tail->SetNext(node);
        node->SetPrev(Tail); //Previous is tail because node being added is new tail
        Tail = node; //Initialising the tail to be the new node
        ListSize++;
    }
}

//add to head
void LinkedList::addToHead(Node::StuData data)
{
    if(GetListSize() == 0) //if list is empty
    {
        Node* node = new Node(); //empty node that will be head and tail of the list
        Head = node;
        Tail = node;
        node ->SetPrev(NULL);
        node ->SetNext(NULL);
        node ->SetData(data);
        ListSize++; //increase size due to another node being added
    }
    else //if there is 1 or more items in the list
    {
        Node* node = new Node();
        node ->SetData(data);
        Head ->SetPrev(node);
        node ->SetNext(Head); //Next node is head as the node created is the new head
        Head = node;
        ListSize++;
    }
}

//Removing Items
void LinkedList::RemoveFromHead()
{
    if(Head->GetNext() != NULL) //if there is more than 1 item in the list
    {
        Head = Head->GetNext(); //Next item in the list is the new head
        //delete Head->GetPrev();
        Head->SetPrev(NULL); //Previous of the head is now null, as the old head is deleted
		delete Head->GetPrev();
        ListSize--; //list size decrease
    }
    else
    {
        Tail = NULL;
        ListSize--;
    }
}

void LinkedList::RemoveFromTail()
{
    if(Tail->GetPrev() != NULL) //if list has more than one item
    {
        Tail = Tail->GetPrev(); //Tail is the previous node
        //delete Tail->GetNext();
        Tail->SetNext(NULL); //the next pointer of tail is null due to the old tail being removed
		delete Tail->GetNext();
        ListSize--; //list size decreases
    }
    else
    {
        RemoveFromHead(); //Removes from head as list is empty
    }
}

void LinkedList::RemoveFromCurrent() //Removes list item in between head and tail
{
    Node* Temp; //creates temp node
    Temp = Current->GetPrev(); //Temp is the previous of the current
    Temp->SetNext(Current->GetNext()); //Next of temp is the node after the current
    Temp = Current->GetNext(); //temp is now the next it was set to
    Temp->SetPrev(Current->GetPrev()); //and is now linked to a previous and next
    delete Current; //Node to be deleted is now removed, with temp taking its place / links
    Current = Temp;
	//delete Current; //Node to be deleted is now removed, with temp taking its place / links
    ListSize--; //Decreases list size
}

//Remove Function
void LinkedList::remove(string name)
{
    Current = Head; //Set current to point to head
    while (Current != NULL) {
        //for (int i = 0; i < GetListSize(); i++) { //loops over every item in the list
            if (name == Current->GetData().get_name()) { //if name parameter is equal to the data of the current node
                if (Current->GetPrev() == NULL) { //if its the head, call remove head function
                    RemoveFromHead();
                    CurrentToNext();
                } else if (Current->GetNext() == NULL) { //if its the tail call the remove tail function
                    RemoveFromTail();
                    CurrentToNext();
                } else { //if it is not the head or the tail it calls the function that deletes current
                    RemoveFromCurrent();
                    CurrentToNext();
                }
            } else { //if the name does not match with item current is moved to the next node
                CurrentToNext();
            }
        //}
    }
}

//Count Function
int LinkedList::count(string const name)
{
    int count = 0; //Set to 0
    Current = Head; //Current is at the start of the list
    for(int i = 0; i < GetListSize(); i++) { //loops through entire list
        if (name == Current->GetData().get_name()) {
            count++; //if the name passed in is equal to the current nodes name, increase count by 1
            CurrentToNext(); //move to next node
        } else {
            CurrentToNext();
        }
    }
    return count; //return the count
}

void LinkedList::operator+=(LinkedList& linkedList) {
    Node* temp = linkedList.Head; //temp node is the head of the right hand operator (linked list)
    while (temp != NULL) //While there is a next in the list
    {
        Node* newNode = new Node();
        newNode->SetData(temp->GetData());
        addToTail(newNode->GetData()); //add item from list to the tail of the left hand operator list
        temp = temp->GetNext(); //Temp is next item in list
    }
}

void LinkedList::operator-=(LinkedList& linkedList) {
    Node* temp = linkedList.Head; //Node temp is the start of the right hand operator list
    while (temp != NULL) //While there is a next node in the right hand list
    {
        Current = Head; //Current for the left hand list gets set to the start for each loop to go through it again
        for(int i = 0; i < GetListSize(); i++) //loop through whole list
        {
            if(temp->GetData() == Current->GetData()) //if the data from temp is equal to the data of current node
            {
                if(Current->GetNext() == NULL) //if its the tail
                {
                    RemoveFromTail();
                }
                else if(Current->GetPrev() == NULL) //if it is the head
                {
                    RemoveFromHead();
                    CurrentToNext(); //move to next node
                }
                else
                {
                    RemoveFromCurrent(); //if it is not head or tail, remove node from the middle
                    CurrentToNext();
                }
            }
            else //if data does not match, move to the next node
            {
                CurrentToNext();
            }
        }
        temp = temp->GetNext(); //Once for loop is completed and checked, move to the next item in the list
    }
}

//ostream Out
ostream&  operator <<(ostream& out, LinkedList& list) //overload print
{
    list.CurrentToHead();
    for(int i = 0; i < list.GetListSize(); i++) //loops through entire list
    {
        out << list.GetCurrentData(); //prints data from list
        list.CurrentToNext();
    }
    return out;
}



