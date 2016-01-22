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
	if (this->first == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
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
void LinkedList::DeleteAtValue(int value)
{
	Node *node = first;
	Node *prev = NULL;

	//loop through the nodes
	while (node != NULL)
	{
		//check if the value at that node is equal to the input value
		if (node->num == value)
		{
			break;
		}

		prev = node;
		node = node->next;
	}

	//if it's found, delete it
	if (node != NULL)
	{
		if (node == first)
		{
			first = node->next;
		}
		else
		{
			prev->next = node->next;
		}

		delete node;
	}
}

////////////////////////////////////
///Delete at a specific position///
//////////////////////////////////
void LinkedList::DeleteAtPosition(int nodenum)
{
	int index = -1;
	nodenum--;
	Node *node = first;

	//loop through until the position matches the input node number
	while (node != NULL)
	{
		index++;

		if (index == nodenum)
		{
			break;
		}

		node = node->next;
	}

	
	if (index >= 0)
	{
		node->num = 0;
	}
}

/////////////////////////////////////////////////
///Insert a new value after a specified value///
///////////////////////////////////////////////
void LinkedList::InsertAfterValue(int value, int num)
{
	Node *node = new Node();
	node->num = num;

	// search for node to insert after
	Node *prev = first;

	while (prev != NULL)
	{
		if (prev->num == value)
		{
			break;
		}

		prev = prev->next;
	}

	// insert node into list
	if (first == NULL)
	{
		first = node;
	}
	else
	{
		if (prev != NULL)
		{
			node->next = prev->next;
			prev->next = node;
		}
		else
		{
			// could not find the node to insert after
			// so defaulting to Add function
			Add(num);
		}
	}
}

/////////////////////////////////////////////////
///Insert a value at a specific node position///
///////////////////////////////////////////////
void LinkedList::InsertAtPosition(int nodenum, int num)
{
	int index = -1;
	nodenum--;
	Node *node = first;

	//start at first node, loop until the node number = the index
	while (node != NULL)
	{
		index++;

		if (index == nodenum)
		{
			//when found, break
			break;
		}

		node = node->next;
	}

	if (index >= 0)
	{
		//assign the input number to the node that was found
		node->num = num;
	}
}

////////////////////////////////
///Retrieve a specific value///
//////////////////////////////
int LinkedList::RetrieveValue(int value)
{
	Node *node = first;
	Node *prev = NULL;

	//loop through the nodes
	while (node != NULL)
	{
		//check if the value at that node is equal to the input value
		if (node->num == value)
		{
			break;
		}

		prev = node;
		node = node->next;
	}

	//if it's found, return it
	if (node != NULL)
	{
		return node->num;
	}
}

///////////////////////////////////////////////////
///Retrieve a value at a specific node position///
/////////////////////////////////////////////////
int LinkedList::RetrieveAtPosition(int nodenum)
{
	int index = -1;
	nodenum--;
	Node *node = first;

	//loop through until the position matches the input node number
	while (node != NULL)
	{
		index++;

		if (index == nodenum)
		{
			break;
		}

		node = node->next;
	}

	//return the number at the position
	if (index >= 0)
	{
		return node->num;
	}
}

//////////////////////////////////////////////////////////
///Seperates the input integer from the command letter///
////////////////////////////////////////////////////////
int LinkedList::splitCommand(string command)
{
	string delimiter = " ";
	size_t pos = 0;
	std::string token;
	while ((pos = command.find(delimiter)) != std::string::npos) {
		token = command.substr(0, pos);
		command.erase(0, pos + delimiter.length());
	}

	return stoi(command);
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
