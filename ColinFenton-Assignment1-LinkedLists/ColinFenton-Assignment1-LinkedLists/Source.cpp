#include <iostream>
#include <conio.h>
#include <string.h>
#include <regex>

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
			cout << "The export filepath parameter was not valid. The exported lock file will be saved to the default location.";
		}
	}
	//if no argument is given, the file is saved to a default location
	else
	{
		filePath = "C:\\Users\\NSCCSTUDENT\\Desktop\\datastructures\\datastructures\\ColinFenton - Assignment1 - LinkedLists\\Debug\\lock.txt";
		cout << "There was no export filepath parameter entered. The export lock file will be saved to the default location.";
	}

	cout << filePath;

	_getch();
}