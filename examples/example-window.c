#include "llww.h" // Include a library

int main()
{
	DestroyConsole(); // Destroy a console
	InitWindow(10, 10, 640, 480, "Test"); // Initialization a window
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) // if get a message...
	{
		DispatchMessage(&msg);
		if ((msg.message == 161) && (msg.wParam == 20)) // if press "Close"...
		{
			return 0; // Close a programm
		}
	}
    return 0;
}
