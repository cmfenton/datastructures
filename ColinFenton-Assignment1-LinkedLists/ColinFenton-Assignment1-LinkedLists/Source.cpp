#include <iostream>
#include <conio.h>
#include <string.h>
#include <regex>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

//////////////////////////////////////////////////////////
///Seperates the input integer from the command letter///
////////////////////////////////////////////////////////
int splitCommand(string command)
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

/////////////////////
///Implementation///
///////////////////
int main(int argc, char** argv) 
{
	string filePath;
	regex validPath("^[A-Z][:][\\\\](.+[\\\\])(\\w+\\.txt)$");
	regex validSubstitute("^[Ss][ ][0-9]$|^[Ss][ ][0-4][0-9]$");
	regex validGoto("^[Gg][ ][1-7]$");
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
	cout << list << endl;
	

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
		if (commandInput == "q" || commandInput == "Q")
		{
			//close the program
			exit(0);
		}
		///////////
		///Exit///
		/////////
		else if (commandInput == "e" || commandInput == "E")
		{
			//save the lock to a text file

			//close the program
			exit(0);
		}
		///////////
		///Goto///
		/////////
		else if (regex_match(commandInput, validGoto))
		{
			//G or g followed by a number from 1 to 7
			//split at space in commandInput and convert to int	
			int gotoNum = splitCommand(commandInput);
			
			//set position
			list.currentPosition = gotoNum;
			//reprint the display		
			system("cls");
			cout << "Current Combination: " << endl;
			cout << list << endl;
		}
		/////////////////
		///Substitute///
		///////////////
		else if (regex_match(commandInput, validSubstitute))
		{
			//S or s followed by 0 - 49
			//split at space in commandInput and convert to int	
			int insertNum = splitCommand(commandInput);

			//set the new number at the current position
			list.InsertAtPosition(list.currentPosition, insertNum);

			//reprint the display
			system("cls");
			cout << "Current Combination: " << endl;
			cout << list << endl;
		}
	}

	_getch();
}