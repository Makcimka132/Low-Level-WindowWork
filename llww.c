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