#include <iostream>
#include "Header.h"
#include <windows.h>
#include <Windows.h>

using namespace std;

// Declare a global variable to store the mouse click event
//MOUSEHOOKSTRUCT mouseEvent;

// Declare a global variable to store the handle to the mouse hook
//HHOOK mouseHook;

 
 //FUCNTION TO LOG MOUSE MOVEMENT   NOT IMPLEMENTED
 
//LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
//{
//    if (nCode >= 0 && wParam == WM_LBUTTONDOWN)
//    {
//        // Store the mouse click event
//        mouseEvent = *(MOUSEHOOKSTRUCT*)lParam;
//
//        // Log the mouse click event to the console
//        std::cout << "Mouse clicked at (" << mouseEvent.pt.x << ", " << mouseEvent.pt.y << ")" << std::endl;
//    }
//
//    // Call the next hook in the hook chain
//    return CallNextHookEx(NULL, nCode, wParam, lParam);
//}


int main()
{
    

    //RESIZING CONSOLE ATTEMPTS UNSUCESSFUL

   // HWND console = GetConsoleWindow();
   // RECT rect;
   //// SetWindowPos(console, 0, 100, 100, 200, 200, SWP_NOSIZE | SWP_NOZORDER);
   // SetWindowPos(console, 0, 100, 100, 100, 100, SWP_NOSIZE | SWP_NOZORDER);

   // // Set the mouse hook
   // mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, NULL, 0);

   // // Enter the message loop
   // MSG msg;
   // while (GetMessage(&msg, NULL, 0, 0))
   // {
   //     TranslateMessage(&msg);
   //     DispatchMessage(&msg);
   // }
   // // Unhook the mouse hook
   // UnhookWindowsHookEx(mouseHook);

    //A:\University\Semester 3\Data science\project\project
    setColor(13); 
    mainMenu();
    
    //Beep(300, 500);
   

}