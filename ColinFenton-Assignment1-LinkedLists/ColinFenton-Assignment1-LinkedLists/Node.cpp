#pragma once
#include <iostream>
#include <conio.h>
#include <string.h>
#include <regex>

using namespace std;

class Node
{
public:
	int data = 0;
	Node *next;

	Node() : next(NULL), data(-1) {}
};
