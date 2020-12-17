#include <windows.h>
void msgbox(char *name, char *str, short type);
void HideConsole();
void ShowConsole();
void DestroyConsole();
void InitWindow(int x, int y, int w, int h, char *name);
void DrawConsoleRectangle(int x, int y, int r, int g, int b);
void DrawConsoleEllipse(int x, int y, int r, int g, int b);