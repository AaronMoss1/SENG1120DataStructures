//Node.h: Node Header File
//***************************
//Author: Aaron Moss
//Student Number: c3282382
//Date Updated: 6/09/19
//Course: SENG1120- Data Structures
//Program Description: Contains methods / functions to be defined and implemented to be used by the linked list template

#ifndef C3282382_NODE_H
#define C3282382_NODE_H
#include <iostream>
using namespace std;

template <typename value_type>
class Node
{
public:
    //Constructor
    Node()
    {
        Next = NULL;
        Previous = NULL;
    }
	
    //Destructor
    ~Node()
    {
        Next = NULL;
        Previous = NULL;
    }
	
    //Setters
    void SetNext(Node<value_type>* next)
    {
        Next = next;
    }
    //Pre Conditions: Node is passed in
    //Post Conditions: Whatever is passed in is created to be the next element of the current node

    void SetPrev(Node<value_type>* prev)
    {
        Previous = prev;
    }
    //Pre Conditions: Node is passed in
    //Post Conditions: Whatever is passed in is created to be the previous element of the current node

    void SetData(value_type& data)
    {
        Data = data;
    }
    //Pre Conditions: Node is passed in
    //Post Conditions: Whatever is passed in is setting data for the current node

    //Getters
    Node<value_type>* GetNext() const
    {
        return Next;
    }
    //Pre Conditions: None
    //Post Conditions: Returns the Next Node in list

    Node<value_type>* GetPrev() const
    {
        return Previous;
    }
    //Pre Conditions: None
    //Post Conditions: Returns Previous of linked list

    value_type GetData() const
    {
        return Data;
    }
    //Pre Conditions: None
    //Post Conditions: Gets the Data of the node
private:
    Node<value_type>* Next;
    Node<value_type>* Previous;
    value_type Data;
};
#endif //C3282382_NODE_H
