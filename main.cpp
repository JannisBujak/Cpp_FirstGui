#include <windows.h>
#include <iostream>


LRESULT CALLBACK WindowProcedure(HWND, UINT , WPARAM , LPARAM );

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow){

	//MessageBox(NULL, "Hello", "My First Gui", MB_OK);

	WNDCLASSW w = {0};
	w.hbrBackground = (HBRUSH)COLOR_WINDOW;
	w.hCursor = LoadCursor(NULL, IDC_ARROW);
	w.hInstance = hInst;
	w.lpszClassName = L"MyWindowClass";
	w.lpfnWndProc = WindowProcedure;


	if(!RegisterClassW(&w)){
		return  -1;
	}
	CreateWindowW(L"MyWindowClass", L"MyWindow", WS_OVERLAPPED | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

	MSG msg = {0};
	
	while(GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;

}

LRESULT CALLBACK WindowProcedure(HWND hWind, UINT msg, WPARAM w, LPARAM lp) {
	switch (msg){
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProcW(hWind, msg, w, lp);
	}
}
