#include "LinkedList.h"
#include <iostream>
#include <conio.h>
#include <string.h>
#include <regex>
#include "Node.h";

using namespace std;

////////////////////////////////////
///Implementation of Linked List///
//////////////////////////////////

/////////////////
///Destructor///
///////////////
LinkedList::~LinkedList(){}

/////////////////////////////////
///Tests if the list is empty///
///////////////////////////////
bool LinkedList::empty() const
{
	return false;
}

/////////////////////////////////////////////
///Add a new entry to the end of the list///
///////////////////////////////////////////
void LinkedList::Add(int num)
{
	Node *node = new Node();
	node->data = num;

	if (first == NULL)
	{
		first = node;
	}
	else
	{
		Node *currNode = first;
		Node *prevNode = NULL;

		while (currNode != NULL)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}

		if (prevNode != NULL)
		{
			prevNode->next = node;
		}
	}
}

//////////////////////////////
///Delete a specific value///
////////////////////////////
void LinkedList::DeleteValue(int value)
{
}

////////////////////////////////////
///Delete at a specific position///
//////////////////////////////////
void LinkedList::DeletePosition(int nodenum)
{
}

/////////////////////////////////////////////////
///Insert a new value after a specified value///
///////////////////////////////////////////////
void LinkedList::InsertAfterValue(int value, int num)
{
}

/////////////////////////////////////////////////
///Insert a value at a specific node position///
///////////////////////////////////////////////
void LinkedList::InsertAtPosition(int nodenum, int num)
{
}

////////////////////////////////
///Retrieve a specific value///
//////////////////////////////
int LinkedList::RetrieveValue(int value)
{
	return 0;
}

///////////////////////////////////////////////////
///Retrieve a value at a specific node position///
/////////////////////////////////////////////////
int LinkedList::RetrievePosition(int nodenum)
{
	return 0;
}

/////////////////////////////////////////////////
///Custom output for items in the linked list///
///////////////////////////////////////////////
//ostream & operator<<(ostream & output, LinkedList& list)
//{
//
//}
