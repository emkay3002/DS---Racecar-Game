#pragma once
#include <iostream>
#include <windows.h>
#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>

//global variable for option selecton (other functions were not working, had to resort to this)
int prime = 0;
using namespace std;

void menu();
int navigateMenu(int currentOption, int totalOptions);


//FUNCTION TO START THE GAME
void gameLogic()
{
	cout << "STARTED";
}

void displayTestMessage()
{
	cout << "test" << endl;
}


//BEEP SOUND EFFECT
void startSound()
{
	Beep(500, 500);
	Sleep(500);
	Beep(500, 550);
	Sleep(500);
	Beep(501, 950);
}

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Reset to default color
}


//MENU FOR ARROW KEY SELECTION
void menuOption(int option)
{
	system("cls");

	if (option == 1)
	{
		menu();
		cout << ">START GAME" << endl;
		cout << " RESUME GAME" << endl;
		cout << " TEST BUTTON" << endl;
		cout << " TEST BUTTON" << endl;
		prime = 1;
	}

	if (option == 2)
	{
		menu();
		cout << " START GAME" << endl;
		cout << ">RESUME GAME" << endl;
		cout << " TEST BUTTON" << endl;
		cout << " TEST BUTTON" << endl;
		prime = 2;
	}

	if (option == 3)
	{
		menu();
		cout << " START GAME" << endl;
		cout << " RESUME GAME" << endl;
		cout << ">TEST BUTTON" << endl;
		cout << " TEST BUTTON" << endl;
		prime = 3;
	}
	
	if (option == 4)
	{
		menu();
		cout << " START GAME" << endl;
		cout << " RESUME GAME" << endl;
		cout << " TEST BUTTON" << endl;
		cout << ">TEST BUTTON" << endl;
	}

	char key = _getch();


	// FOR SELECTION OF OPTIONS
	if (key == 13 && prime == 1) 
	{
		startSound();
		system("cls");
		gameLogic();
	}


	if (key == 13 && prime == 2)
	{
		system("cls");
		displayTestMessage();
	}


	if (key == 13 && prime == 3)
	{
		displayTestMessage();
	}


	if (key == 13 && prime == 4)
	{
		displayTestMessage();
	}

}
	

void menu()
{
	int choice = 0;
	
	setColor(11); // Set text color to light cyan
	
	

	cout << "  ____             ____             _                                 " << endl;
	cout << "/ ____| __ _ _ __ |  _ \\ __ _  ___(_)_ __   __ _                    " << endl;
	cout << "| |   / _` | '__| | |_) / _` |/ __| | '_ \\ / _` |     ______        " << endl;
	cout << "| |__| (_| | |    |  _ < (_| | (__| | | | | (_| |    /|_||_\\` __    " << endl;
	cout << " \\____\\__,_|_|    |_| \\_\\__,_|\\___|_|_| |_|\\__, |   (   _    _ _||  " << endl;
	cout << "                                           |___/    =`-(_)--(_)-'   " << endl;
	cout << endl;
	cout << endl;
	cout << "==============================================================================" << endl;
	cout << endl;


}


//MAIN MENU
void mainMenu()
{
	int option = 1;
	const int totalOptions = 4;

	while (option != 99) {
		menu();
		menuOption(option);

		// Get user input and update the selected option
		option = navigateMenu(option, totalOptions);

	}
}



int navigateMenu(int currentOption, int totalOptions) 
{
	char key = _getch(); // Get a key press without displaying it on the console

	// Handle arrow key input
	switch (key) 
	{
	case 72: // Up arrow key
		return (currentOption > 1) ? currentOption - 1 : totalOptions;

	case 80: // Down arrow key
		return (currentOption < totalOptions) ? currentOption + 1 : 1;

	case 13:  //enter key
		return -1;
		 // Signal to exit the loop
	default:
		return currentOption; // No change
	}
}