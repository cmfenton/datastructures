#include <iostream>
#include <conio.h>
#include <string.h>
#include <regex>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

int main(int argc, char** argv) 
{
	string filePath;
	regex validPath("^[A-Z][:][\\\\](.+[\\\\])(\\w+\\.txt)$");

	//check if an argument is given
	if (argc > 1)
	{
		//check if the argument given is a valid file path
		if (regex_match(argv[1], validPath))
		{ 
			//store in variable
			filePath = argv[1];
		}
		//if the file is invalid, save to a default location
		else 
		{
			filePath = "C:\\Users\\NSCCSTUDENT\\Desktop\\datastructures\\datastructures\\ColinFenton - Assignment1 - LinkedLists\\Debug\\lock.txt";
			cout << "The export filepath parameter was not valid. The exported lock file will be saved to the default location." << endl;
		}
	}
	//if no argument is given, the file is saved to a default location
	else
	{
		filePath = "C:\\Users\\NSCCSTUDENT\\Desktop\\datastructures\\datastructures\\ColinFenton - Assignment1 - LinkedLists\\Debug\\lock.txt";
		cout << "There was no export filepath parameter entered. The export lock file will be saved to the default location." << endl;
	}

	//create a linked list
	LinkedList list;
	list.currentPosition = 1;

	//add the default 0's to the list
	for (int i = 1; i < 8; i++)
	{
		list.Add(0);
	}
	
	//print out starting combination
	cout << "Starting combination: " << endl;
	cout << list;
	

	//recieve command
	string commandInput;
	while (true)
	{
		cout << "\nEnter a command: ";
		getline(cin, commandInput);

		//check command input

		///////////
		///Quit///
		/////////
		if (commandInput == "q" || commandInput == "Q" || commandInput == "QQ")
		{
			//close the program
			exit(0);
		}
	}

	_getch();
}