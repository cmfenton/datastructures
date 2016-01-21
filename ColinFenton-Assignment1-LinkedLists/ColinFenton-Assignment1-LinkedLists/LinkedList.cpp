#include "LinkedList.h"
#include <iostream>
#include <conio.h>
#include <string.h>
#include <regex>
#include <Windows.h>
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
	//create a node object
	Node *node = new Node();
	//assign the number value
	node->num = num;

	//add it to the end of the linked list
	//if there is no first value in the list, add it to the beginning
	if (first == NULL)
	{
		first = node;
	}	
	else
	{
		Node *currNode = first;
		Node *prevNode = NULL;

		//else, loop until the end of the list
		while (currNode != NULL)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}

		if (prevNode != NULL)
		{
			//add the node to the list
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
	int index = -1;

	Node *node = first;
	Node *prev = NULL;

	while (node != NULL)
	{
		index++;

		if (index == nodenum)
		{
			break;
		}

		prev = node;
		node = node->next;
	}

	if (index >= 0)
	{
		if (node == first)
		{
			first = node->next;
		}
		else
		{
			prev->next = node->next;
		}

		node->num = num;
	}
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
ostream & operator<<(ostream & output, LinkedList& list)
{
	Node *currNode = list.first;
	int count = 1;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//until the end of the list
	while (currNode != NULL)
	{
		
	
		//check if odd or even

		//if even
		if (count % 2 == 0)
		{
			//check if the current node is the current selected position in the console
			if (list.currentPosition == count)
			{
				//change the colour
				SetConsoleTextAttribute(hConsole, 23);
			}
			//put an L in front and output the number stored in this node
			output << "L" << currNode->num;
			//change the colour back (in case it had changed)
			SetConsoleTextAttribute(hConsole, 7);
			output << " ";
		}
		//if odd
		else
		{
			//check if the current node is the current selected position in the console
			if (list.currentPosition == count)
			{
				//change the colour
				SetConsoleTextAttribute(hConsole, 23);
			}
			//put an R in front and output the number stored in this node
			output << "R" << currNode->num;
			//change the colour back to default (in case it had changed)
			SetConsoleTextAttribute(hConsole, 7);
			output << " ";
		}

		//check if the current node is the current position

		//move on to the next node

		currNode = currNode->next;		
		count++;
	}

	return output;
}
