#include <windows.h>
#include <gdiplus.h>
#include "Shape2D.h"
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
   HWND                hWnd;
   MSG                 msg;
   WNDCLASS            wndClass;
   GdiplusStartupInput gdiplusStartupInput;
   ULONG_PTR           gdiplusToken;
   
   // Initialize GDI+.
   GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
   
   wndClass.style          = CS_HREDRAW | CS_VREDRAW;
   wndClass.lpfnWndProc    = WndProc;
   wndClass.cbClsExtra     = 0;
   wndClass.cbWndExtra     = 0;
   wndClass.hInstance      = hInstance;
   wndClass.hIcon          = LoadIcon(NULL, IDI_APPLICATION);
   wndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);
   wndClass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
   wndClass.lpszMenuName   = NULL;
   wndClass.lpszClassName  = TEXT("Shapes");
   
   RegisterClass(&wndClass);
   
   hWnd = CreateWindow(
      TEXT("Shapes"),   // window class name
      TEXT("Shapes"),  // window caption
      WS_OVERLAPPEDWINDOW,      // window style
      400,            // initial x position
      400,            // initial y position
      800,            // initial x size
      800,            // initial y size
      NULL,                     // parent window handle
      NULL,                     // window menu handle
      hInstance,                // program instance handle
      NULL);                    // creation parameters
	  
   ShowWindow(hWnd, iCmdShow);
   UpdateWindow(hWnd);
   
   while(GetMessage(&msg, NULL, 0, 0))
   {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }
   
   GdiplusShutdown(gdiplusToken);
   return msg.wParam;
}  // WinMain

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, 
   WPARAM wParam, LPARAM lParam)
{
   Graphics graphics(hWnd);
   Pen pen( Color(255, 0, 0, 255) );
   Pen pen2( Color(255, 0, 0, 0) );
   Shape2D test;
   
   test.setPoint(0, 0);
   test.setPoint(0, 100);
   test.setPoint(100, 100);
   test.setPoint(100, 0);
  
   
   PointListElement * tmp = test.getPoint();
   PointListElement * tmp2 = tmp;
   
   switch(message){
   
   case WM_PAINT:
	
	   graphics.DrawLine(&pen2, 400, 0, 400, 800);
	   graphics.DrawLine(&pen2, 0, 400, 800, 400);
	   
	   do {
		   graphics.DrawLine(&pen, tmp->x + 400, tmp->y + 400, tmp->PNext->x + 400, tmp->PNext->y + 400);
		   tmp = tmp->PNext;
	   } while (tmp->PNext != nullptr);

	   graphics.DrawLine(&pen, tmp->x + 400, tmp->y + 400, tmp2->x + 400, tmp2->y + 400);
	
	return 0;
 
   case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
   default:
      return DefWindowProc(hWnd, message, wParam, lParam);
   }
} // WndProc