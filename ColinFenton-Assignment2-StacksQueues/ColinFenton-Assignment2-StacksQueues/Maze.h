#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

class Maze
{
public:
	static int width;
	static int height;
	string test;
	char* maze;

	Maze();
	int getMazeWidth();
	int getMazeHeight();
	char* loadMaze();
	void solve();
};