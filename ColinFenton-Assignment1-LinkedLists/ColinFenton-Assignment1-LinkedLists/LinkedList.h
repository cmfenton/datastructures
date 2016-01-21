#pragma once
#include <iostream>
#include <conio.h>
#include <string.h>
#include <regex>
#include "Node.h";
using namespace std; 

////////////////////////////////////////
///Header File for Linked List Class///
//////////////////////////////////////
class LinkedList
{
private:
	Node *first;
public:
	LinkedList() : first(NULL) {};
	int currentPosition;
	virtual ~LinkedList();
	bool empty() const;
	void Add(int num);
	void DeleteAtValue(int value);
	void DeleteAtPosition(int nodenum);
	void InsertAfterValue(int value, int num);
	void InsertAtPosition(int nodenum, int num);
	int RetrieveValue(int value);
	int RetrievePosition(int nodenum);

	friend ostream& operator <<(ostream &output, LinkedList& list);
};
