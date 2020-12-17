#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

HWND hwnd;

void msgbox(char *name, char *str){MessageBox(NULL,name,str,MB_OK);}

void HideConsole()
{
    HWND hwnds = GetConsoleWindow();ShowWindow(hwnds,0);
}

void ShowConsole()
{
    HWND hwnds = GetConsoleWindow();ShowWindow(hwnds,1);
}

void DestroyConsole()
{
	HWND hwnds = GetConsoleWindow();DestroyWindow(hwnds);
}

void InitWindow(int x,int y,int w,int h, char *name)
{
	WNDCLASSA wcl;
	  memset(&wcl, 0, sizeof(WNDCLASSA) );
	  wcl.lpszClassName = name;
	  wcl.lpfnWndProc = DefWindowProcA;
	RegisterClassA(&wcl);

	hwnd = CreateWindow(name, name, WS_OVERLAPPEDWINDOW,
		x, y, w, h, NULL, NULL, NULL, NULL);

	ShowWindow(hwnd, SW_SHOWNORMAL);
}

void DrawConsoleRectangle(int x, int y, int r, int g, int b)
{
	HWND hwnds = GetConsoleWindow();
	HDC dc = GetDC(hwnds);
	SelectObject(dc, GetStockObject(DC_BRUSH));
	SetDCBrushColor(dc, RGB(r, g, b));
	Rectangle(dc, x, x, y, y);
}

void DrawConsoleEllipse(int x, int y, int r, int g, int b)
{
	HWND hwnds = GetConsoleWindow();
	HDC dc = GetDC(hwnds);
	SelectObject(dc, GetStockObject(DC_BRUSH));
	SetDCBrushColor(dc, RGB(r, g, b));
	Ellipse(dc, x, x, y, y);
}