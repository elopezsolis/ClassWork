/*************************************************************************
 *  AUTHOR		 : Erick Lopez
 *  STUDEN ID    : 245600
 *  ASSIGNMENT #7: Searching Linked List
 *  CLASS        : CS1B
 *  SECTION      : MW: 10:00 - 11:50
 *  DUE DATE     : 11/03/13
 *  *********************************************************************/
#include "myheader.h"

int main()
{
	ofstream outFile;
	ifstream inFile;		//IN      - file used in the function

	string inFileName;		//IN      - name of file the user will enter
	string outFileName;

	MovieInfo *head;
//	MovieInfo *headPtr;
	bool validMenuChoice;
	int menuChoice;
	Menu commandMenu;
	bool quit;
	quit = false;

	head    = NULL;
	commandMenu = OUTPUT;

	GetFileNames(inFile,outFile,"Input");
	GetFileNames(inFile,outFile,"Output");

	head    = ReadInput(head,inFile);

//	PrintHeader("Searching Linked List",'A',7,cout);
//	PrintHeader("Searching Linked List",'A',7,outFile);

	while(commandMenu != EXIT)
	{
		cout << "DVD MENU OPTIONS"       << endl << endl;
		cout << "1 - Output Entire List" << endl;
		cout << "2 - Title Search"       << endl;
		cout << "3 - Genre Search"       << endl;
		cout << "4 - Actor Search"       << endl;
		cout << "5 - Year Search"        << endl;
		cout << "6 - Rating Search (0-9)"<< endl;
		cout << "0 - EXIT"               << endl;




		menuChoice = ErrorCheckingMenu
				   ("Enter an option (0 to exit): ",
				    "****Please input a number between 0 and 6****",
				    "****Please input a number between 0 and 6" );


		commandMenu = Menu(menuChoice);

		if (commandMenu == OUTPUT)
		{
			cout << endl <<"Listing all movies" << endl;
					ListAllMovies(head, outFile);

		}
		else
		{
			SearchLinkedList(head,commandMenu);
		}

	}
	cout <<"Done reading File";
	cout << "Done outputting File";

	inFile.close();
	outFile.close();



	return 0;
}

