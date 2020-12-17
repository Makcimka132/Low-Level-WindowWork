#include "llww.h"

int main()
{
	DestroyConsole();
	InitWindow(10, 10, 640, 480, "Test");
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
		if ((msg.message == 161) && (msg.wParam == 20))
		{
			return 0;
		}
	}
    return 0;
}
