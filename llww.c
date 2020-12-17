#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

HWND hwnd;

void msgbox(char *name, char *str, short type){
	if (type == 0){MessageBox(NULL, name, str, MB_OK);}
	else if (type == 1) { MessageBox(NULL, name, str, MB_OK | MB_ICONERROR); }
	else if (type == 2) { MessageBox(NULL, name, str, MB_OK | MB_ICONWARNING); }
	else if (type == 3) { MessageBox(NULL, name, str, MB_OK | MB_ICONQUESTION); }
	else if (type == 4) { MessageBox(NULL, name, str, MB_OK | MB_ICONINFORMATION); }
	else {MessageBox(NULL, name, str, MB_OK);}
}

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