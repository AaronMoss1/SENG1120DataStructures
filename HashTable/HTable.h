//HTable.h: Hash Table Header / Template File
//***************************
//Author: Aaron Moss
//Student Number: c3282382
//Date Updated: 8/11/19
//Course: SENG1120- Data Structures
//Program Description: Contains Methods/Functions to be used to create a functional Hash Table
#ifndef C3282382_HTABLE_H
#define C3282382_HTABLE_H

#include <string>
#include <cstdlib>
#include <iostream>
#include "MechPart.h"
using namespace std;

template <typename value_type>
class HTable
{
public:
	//constructor
    HTable()
    {
		TABLE_SIZE = 5000; //table size set to 5000 as per requirement
        MechPart part; //a mech part is created as a default value for the slots
        for(int i = 0; i < TABLE_SIZE; i++)
        {
            HTArray[i] = part; //adds the default part to all 5000 slots
        }
    }
	
	//destructor
    ~HTable() //empty table as everything is created on the stack
    { }
	
	//Method: hashfun
	//Pre Conditions: none
    //Post Conditions: returns the index value of the value that is to be passed in
    int hashfun(const value_type& value)
    {
        int position = 0;
        string temp = value.get_code(); //gets the code of the part
        for (int i=0; i<(int)temp.length(); i++) //for the length of the string
        {
            position += (i+1) * (i+1) * temp.at(i); //calculating position
        }
        return position % TABLE_SIZE; //returns position, modulus table size (5000)
    }
	
	//Method: InsertNewSpot
	//Pre Conditions: data exists in the previous array index the data was trying to enter
    //Post Conditions: A New mech part is added to an array index
    void InsertNewSpot(value_type const data, int indexVal)
    {
        MechPart part; //default part
        if(HTArray[indexVal] == part) //checks to see if the spot is empty, which is if there is a default part inside
        {
            HTArray[indexVal] = data; //data is added to array 
        }
        else if(data == HTArray[indexVal])
            return; //if the data already exists inside the array
        else
            InsertNewSpot(data, indexVal++); //iterate to new index to find new spot
    }
	
	//Method: add
	//Pre Conditions: none
    //Post Conditions: adds an item in to the Hash Table
    void add(value_type const data)
    {
        MechPart part; //default part
        int index = hashfun(data); //creates an index number
        if(HTArray[index] == part) //if index number is not filled
        {
            HTArray[index] = data;
        }
        else if(data == HTArray[index]) //prevents doubles being inserted
            return;
        else
            InsertNewSpot(data, index++); //recursion if spot filled
    }
	
	//Method: remove
	//Pre Conditions: none
    //Post Conditions: removes the specified item from the hash table
    void remove(value_type const data)
    {
        MechPart part; //default part
        int index = hashfun(data); //gets the index of the part to be added
        if(HTArray[index] == data)
        {
            HTArray[index] = part; //sets the index back to default
        }
    }
	
	//Method: calculateParts
	//Pre Conditions: none
    //Post Conditions: parts are calculated and returned
    int calculateParts() const
    {
        MechPart part; //default part
        int count = 0;
        for(int i = 0; i < TABLE_SIZE; i++) //iterate table
        {
            if(HTArray[i] == part) //if the array spot is default, continue
                continue;
            else
                count++;
        }
        return count;
    }
	
	//Method: calculateParts
	//Pre Conditions: none
    //Post Conditions: inventory is calculated and returned
    int calculateInventory() const
    {
        MechPart part; //default part
        int count = 0;
        for(int i = 0; i < TABLE_SIZE; i++) //iterate table
        {
            if(HTArray[i] == part) //if the array spot is default, continue
                continue;
            else
                count += HTArray[i].get_quantity();
        }
        return count; 
    }
	
	//Method: PrintHTable
	//Pre Conditions: none
    //Post Conditions: Prints the contents of the Hash Table
    void PrintHTable() const
    {
        MechPart part;
        for(int i = 0; i < TABLE_SIZE; i++) //iterate table
        {
            if(HTArray[i] == part) //if the array spot is default, continue
                continue;
            else
                cout << HTArray[i]; //print array value
        }

    }
private:
    value_type HTArray[5000]; //create array size of 5000
    int TABLE_SIZE; //to store array size
};

//Overload method to print hash table
template <typename value_type>
ostream&  operator <<(ostream& out, HTable<value_type>& table) //overload print
{
    table.PrintHTable();
    return out;
}
#endif //C3282382_HTABLE_H
