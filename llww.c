#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void msgbox(char *name, char *str){MessageBox(NULL,name,str,MB_OK);}

void HideConsole()
{
    HWND hwnd = GetConsoleWindow();ShowWindow(hwnd,0);
}

void ShowConsole()
{
    HWND hwnd = GetConsoleWindow();ShowWindow(hwnd,1);
}

void DestroyConsole()
{
	HWND hwnd = GetConsoleWindow();DestroyWindow(hwnd);
}

void InitWindow(int x,int y,int w,int h, char *name)
{
	WNDCLASSA wcl;
	  memset(&wcl, 0, sizeof(WNDCLASSA) );
	  wcl.lpszClassName = name;
	  wcl.lpfnWndProc = DefWindowProcA;
	RegisterClassA(&wcl);

	HWND hwnd;
	hwnd = CreateWindow(name, name, WS_OVERLAPPEDWINDOW,
		x, y, w, h, NULL, NULL, NULL, NULL);

	ShowWindow(hwnd, SW_SHOWNORMAL);
}