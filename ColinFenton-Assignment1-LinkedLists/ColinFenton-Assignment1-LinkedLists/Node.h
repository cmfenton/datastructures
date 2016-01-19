#pragma once
#include <iostream>
#include <conio.h>
#include <string.h>
#include <regex>

using namespace std;

class Node
{
public:
	int num;
	Node *next;

	Node() : next(NULL), num(-1) {}
};
