#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include <sstream>
#include <direct.h>
#include <math.h>
#include "CreateWorld.h"


using namespace std;

string file_displayed;
string messageStr;

char seedBase[10];

CreateWorld world;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

char szClassName[] = "TextEntry";

int currentPosition;
int maxPosition;

void generateText();
void updateText(int position);
void generateTextFromSeed(int seed);

HWND textBox, seedText;
HWND button, button1, button2, buttonSeed;
HWND seedEntry;
HWND scrollbarV;


/*  Make the class name into a global variable  */
//TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("World Generator"),       /* Title Text */
           WS_MINIMIZEBOX | WS_SYSMENU, /* not resize-able */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           800,                 /* The programs width */
           500,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:


            //Main
            textBox = CreateWindow("STATIC",
                                   "Error - Text did not load properly.",
                                   WS_BORDER | WS_CHILD | WS_VISIBLE,
                                   10,10,
                                   750,400,
                                   hwnd,
                                   NULL,
                                   NULL,
                                   NULL
                                   );

            button = CreateWindow("BUTTON",
                                  "New",
                                  WS_BORDER | WS_CHILD | WS_VISIBLE,
                                  10, 410,
                                  80, 20,
                                  hwnd,
                                  (HMENU) 1,
                                  NULL,
                                  NULL
                                  );

            //scrollbars

            button1 = CreateWindow("BUTTON",
                                  "Up",
                                  WS_BORDER | WS_CHILD | WS_VISIBLE,
                                  760, 10,
                                  25, 25,
                                  hwnd,
                                  (HMENU) 2,
                                  NULL,
                                  NULL
                                  );
            button2 = CreateWindow("BUTTON",
                                  "Dn",
                                  WS_BORDER | WS_CHILD | WS_VISIBLE,
                                  760, 35,
                                  25, 25,
                                  hwnd,
                                  (HMENU) 3,
                                  NULL,
                                  NULL
                                  );

            //Seeds
            seedText = CreateWindow("STATIC",
                                  "Enter seed (Must be a number):",
                                  WS_CHILD | WS_VISIBLE,
                                  100, 410,
                                  210, 20,
                                  hwnd,
                                  NULL,
                                  NULL,
                                  NULL
                                  );

            seedEntry = CreateWindow("EDIT",
                                  "",
                                  WS_BORDER | WS_CHILD | WS_VISIBLE,
                                  310, 410,
                                  80, 20,
                                  hwnd,
                                  NULL,
                                  NULL,
                                  NULL
                                  );

            buttonSeed = CreateWindow("BUTTON",
                                  "Go!",
                                  WS_BORDER | WS_CHILD | WS_VISIBLE,
                                  390, 410,
                                  30, 20,
                                  hwnd,
                                  (HMENU) 4,
                                  NULL,
                                  NULL
                                  );

            //Update Text

            generateText();
            currentPosition = 0;

            break;
        case WM_COMMAND:

            switch (LOWORD(wParam))
            {
                case 1:
                    cout << "Generate text - case 1." << endl;
                    generateText();
                    currentPosition = 0;
                    break;

                case 2:
                    cout << "Scroll detected - case 2." << endl;
                    if (currentPosition >= 10)
                        currentPosition -= 10;
                    updateText(currentPosition);
                    break;

                case 3:
                    cout << "Scroll detected - case 3." << endl;
                    if (currentPosition < maxPosition - 10)
                        currentPosition += 10;
                    updateText(currentPosition);
                    break;

                case 4:
                    cout << "Text from seed detected - case 4." << endl;
                    char *sText = &seedBase[0];
                    int length = 0;
                    length = GetWindowText(seedEntry, sText, 10);
                    int finalSeed = atoi(sText);

                    cout << "length = " << length << endl;
                    cout << "finalSeed = " << finalSeed << endl;

                    generateTextFromSeed(finalSeed);

                    break;
            }

            break;

        case WM_VSCROLL:
            cout << "Scroll detected - WM." << endl;
            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}


void generateText()
{
    world = CreateWorld();
    file_displayed = world.getFileName();
    messageStr = "You can find this world at " + file_displayed + "\n";

    ifstream incomingText;
    incomingText.open(file_displayed);
    string line;

    int index = 0;

    if (incomingText.is_open())
	{
		while (getline(incomingText, line))
		{
		    if(index >= 0 && index < 20)
            {
                messageStr += line;
                messageStr += "\n";
            }
			index++;
		}
		incomingText.close();
	}



    incomingText.close();
    maxPosition = index;
    SetWindowText(textBox, messageStr.c_str());
}

void updateText(int position)
{
    messageStr = "You can find this world at " + file_displayed + "\n";

    ifstream incomingText;
    incomingText.open(file_displayed);
    string line;
    int index = 0;

    if (incomingText.is_open())
	{
		while (getline(incomingText, line))
		{
		    if(index >= position && index < position + 20)
            {
                messageStr += line;
                messageStr += "\n";
            }
			index++;
		}
		incomingText.close();
	}


    incomingText.close();

    SetWindowText(textBox, messageStr.c_str());
}

void generateTextFromSeed(int seed)
{
    world = CreateWorld(seed);
    file_displayed = world.getFileName();
    messageStr = "You can find this world at " + file_displayed + "\n";

    ifstream incomingText;
    incomingText.open(file_displayed);
    string line;

    int index = 0;

    if (incomingText.is_open())
	{
		while (getline(incomingText, line))
		{
		    if(index >= 0 && index < 20)
            {
                messageStr += line;
                messageStr += "\n";
            }
			index++;
		}
		incomingText.close();
	}



    incomingText.close();
    maxPosition = index;
    SetWindowText(textBox, messageStr.c_str());
}
