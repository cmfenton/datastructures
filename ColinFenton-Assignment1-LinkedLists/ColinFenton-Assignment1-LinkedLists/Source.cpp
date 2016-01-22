#include <iostream>
#include <conio.h>
#include <string.h>
#include <regex>
#include <fstream>
#include <cstdlib>
#include "LinkedList.h"
#include "Node.h"

using namespace std;
///////////////////////////////////////
///Driver File For Combination Lock///
/////////////////////////////////////

//////////////////////////////////////////
///Function to reprint the combination///
////////////////////////////////////////
void printDisplay(LinkedList list)
{
	system("cls");
	cout << "Current Combination: \n" << endl;
	cout << list << endl;
	cout << "\nPress H for Help.";
}

/////////////////
///Exception///
///////////////
struct FileOpenException : public exception
{
	const char * what() const throw ()
	{
		return "File Could Not Be Opened or Doesn't Exist";
	}
};

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
			cout << "**The export filepath parameter was not valid. The exported lock file will be saved to the default location.**" << endl;
		}
	}
	//if no argument is given, the file is saved to a default location
	else
	{
		filePath = "C:\\Users\\NSCCSTUDENT\\Desktop\\datastructures\\datastructures\\ColinFenton - Assignment1 - LinkedLists\\Debug\\lock.txt";
		cout << "**There was no export filepath parameter entered. The export lock file will be saved to the default location.**" << endl;
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
	printDisplay(list);

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
			
			//try to open a file
			try 
			{
				//will erase data if file already exists, then write new data
				ofstream lockFile(filePath, ios::trunc);

				if (lockFile.fail())
				{
					throw FileOpenException();
				}		
				
				//write the combination to the file
				lockFile << list;

				cout << "Lock file saved to " << filePath << endl << "Press enter to exit." << endl;

				_getch();

				//close the program
				lockFile.close();
				exit(0);
			}
			catch (FileOpenException &e)
			{
				cout << "Exception caught" << endl;
				cout << e.what() << endl;			
			}					
		}
		///////////
		///Goto///
		/////////
		else if (regex_match(commandInput, validGoto))
		{
			//G or g followed by a number from 1 to 7
			//split at space in commandInput and convert to int	
			int gotoNum = list.splitCommand(commandInput);
			
			//set position
			list.currentPosition = gotoNum;

			//reprint the display		
			printDisplay(list);
		}
		/////////////////
		///Substitute///
		///////////////
		else if (regex_match(commandInput, validSubstitute))
		{
			//S or s followed by 0 - 49
			//split at space in commandInput and convert to int	
			int insertNum = list.splitCommand(commandInput);

			//set the new number at the current position
			list.InsertAtPosition(list.currentPosition, insertNum);

			//reprint the display
			printDisplay(list);
		}
		/////////////
		///Delete///
		///////////
		else if (commandInput == "d" || commandInput == "D")
		{
			//'delete' the number by changing it to 0
			list.DeleteAtPosition(list.currentPosition);

			//reprint the display
			printDisplay(list);
		}
		////////////
		///Reset///
		//////////
		else if (commandInput == "r" || commandInput == "R")
		{
			//'delete' all number by changing all to 0
			for (int i = 1; i < 8; i++)
			{
				list.DeleteAtPosition(i);
			}

			//reprint the display
			printDisplay(list);
		}
		///////////
		///Help///
		/////////
		else if (commandInput == "h" || commandInput == "H")
		{
			cout << endl;
			cout << "---Help---" << endl;
			cout << endl;
			cout << "---Basic Information---" << endl;
			cout << endl;
			cout << "The values of the numbers can be changed, but the direction (R or L) always alternates and always starts with R." << endl;
			cout << "The combination value highlighted in green is the currently selected value. Substitute and Delete commands will affect \nthis value." << endl;
			cout << endl;
			cout << "--Commands---" << endl;
			cout << endl;
			cout << "Name / Command / Usage" << endl;
			cout << "Goto / 'G #' (where # = 1 to 7) / Use this command to change which lock value is highlighted." << endl;
			cout << "Substitute / 'S #' (where # = 0 to 49) / Use this command to change the lock value at the highligted position." << endl;
			cout << "Delete / 'D' / Use this command to delete the lock value at the highlighted position, setting it back to 0." << endl;
			cout << "Reset / 'R' / Use this command to delete all 7 lock values, setting them all back to 0." << endl;
			cout << "Exit / 'E' / Use this command to exit the program and write the current combination to a text file." << endl;
			cout << "Quit / 'Q' / Use this command to exit the program without saving the current combination to a text file." << endl;
		}
		else
		{
			cout << "Invalid Command \"" << commandInput << "\", Press H for Help." << endl;
		}
	}

	_getch();
}