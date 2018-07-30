#include <windows.h>
#include <iostream>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow){

	MessageBox(NULL, "Hello", "My First Gui", MB_OK);
	
	return 0;

}