#pragma once
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>

int prime = 0;
using namespace std;
void menu();
int navigateMenu(int currentOption, int totalOptions);

void gameLogic()
{
    cout << "STARTED";
}

void displayTestMessage()
{
    // Implement the logic to display a test message
    cout << "Starting the game! (Test Message)\n";
    // You can replace this with the actual logic for starting the game
}

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

void menuOption(int option)
{
    prime = option;
    menu();
    switch (option)
    {
    case 1:
        cout << "\
>START GAME\n\
 RESUME GAME\n\
 TEST BUTTON\n\
 TEST BUTTON\n";
        prime = 1;
        break;
    case 2:
        cout << "\
 START GAME\n\
>RESUME GAME\n\
 TEST BUTTON\n\
 TEST BUTTON\n";
        prime = 2;
        break;
    case 3:
        cout << "\
 START GAME\n\
 RESUME GAME\n\
>TEST BUTTON\n\
 TEST BUTTON\n";
        prime = 3;
        break;
    case 4:
        cout << "\
 START GAME\n\
 RESUME GAME\n\
 TEST BUTTON\n\
>TEST BUTTON\n";
        prime = 4;
        break;
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
    system("cls");
    int choice = 0;
    cout << "\
  ____             ____             _                                 \n\
/ ____| __ _ _ __ |  _ \\ __ _  ___(_)_ __   __ _                    \n\
| |   / _` | '__| | |_) / _` |/ __| | '_ \\ / _` |     ______        \n\
| |__| (_| | |    |  _ < (_| | (__| | | | | (_| |    /|_||_\\` __    \n\
 \\____\\__,_|_|    |_| \\_\\__,_|\\___|_|_| |_|\\__, |   (   _    _ _||  \n\
                                           |___/    =`-(_)--(_)-'   \n\n\n\
==============================================================================\n\n";
}

void mainMenu()
{
    int option = 1;
    const int totalOptions = 4;
    char key = '0';
    while (option != 99)
    {
        menuOption(option);
        // Get user input and update the selected option
        option = navigateMenu(option, totalOptions);

        // Add a small delay for better visualization (optional)
        // Sleep(10);
    }
}

int navigateMenu(int currentOption, int totalOptions)
{
    char key = _getch(); // skip the [
    char arrow = _getch();
    switch (arrow)
    { // the real value
    case 'A':
    case 'H':
        // code for arrow up
        return (currentOption > 1) ? currentOption - 1 : totalOptions;
        break;
    case 'B':
    case 'P':
        return (currentOption < totalOptions) ? currentOption + 1 : 1;
        // code for arrow down
        break;
    default:
        cout << key;
        return currentOption; // No change
    }
}