// picshot_cpp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

bool indicator = false;

void autoshot()
{
	mouse_event(2, 0, 0, 0, 0);
	Sleep(75);
	mouse_event(4, 0, 0, 0, 0);
}

DWORD WINAPI KeyState(void* lpParam)
{
	while (1)
	{
		if (GetAsyncKeyState(VK_F3))
		{
			indicator = !indicator;
			Beep(500, 200);
		}
		Sleep(100);
	}
}

int main()
{
	SetProcessDPIAware();
	CreateThread(0, 0, &KeyState, 0, 0, 0);
	system("pause");

	HWND ActWin = 0;
	HDC hDC = 0;
	COLORREF color;

	int 
		y = 0,  x = 0,
		x1 = 0, x2 = 0,
		x3 = 0, x4 = 0;

	int R,  G,  B,
		R1, G1, B1,
		R2, G2, B2,
		R3, G3, B3,
		R4, G4, B4;

	int width, height;
	
	width = GetSystemMetrics(0);
	height = GetSystemMetrics(1);
	
	cout << "width : " << width << endl;
	cout << "height : " << height << endl;

	POINT pt;
	while (TRUE)
	{
		ActWin = GetDesktopWindow();
		//cout << "HWND : " << ActWin << endl;
		hDC = GetDC(ActWin);
		while (indicator)// все работает только с правами админа !
		{
			Sleep(5);
			//int Tic = GetTickCount();
			
			GetCursorPos(&pt);
			//ActWin = WindowFromPoint(pt);
			//ActWin = GetDesktopWindow();//вроде тоже норм
			
			//изменяем координаты
			pt.y += 75;
			x1 = pt.x + 5;
			//x2 = pt.x + 6;
			x3 = pt.x - 5;
			//x4 = pt.x - 6;

			color = GetPixel(hDC, pt.x, pt.y);

			R = static_cast<int>(GetRValue(color));
			G = static_cast<int>(GetGValue(color));
			B = static_cast<int>(GetBValue(color));

			if (R > 12)
			{
				if (R / 3 + 5 > G && R / 3 + 5 > B)
				{					
					autoshot();
					continue;
				}
			}

			color = GetPixel(hDC, x1, pt.y);

			R1 = static_cast<int>(GetRValue(color));
			G1 = static_cast<int>(GetGValue(color));
			B1 = static_cast<int>(GetBValue(color));

			if (R1 > 12)//pri x1
			{
				if (R1 / 3 + 5 > G1 && R1 / 3 + 5 > B1)
				{
					autoshot();
					continue;
				}
			}

			//color = GetPixel(hDC, x2, pt.y);
			//R2 = static_cast<int>(GetRValue(color));
			//G2 = static_cast<int>(GetGValue(color));
			//B2 = static_cast<int>(GetBValue(color));
			//if (R2 > 12)//pri x2
			//{
			//	if (R2 / 3 + 5 > G2 && R2 / 3 + 5 > B2)
			//	{
			//		autoshot();
			//		continue;
			//	}
			//}

			color = GetPixel(hDC, x3, pt.y);

			R3 = static_cast<int>(GetRValue(color));
			G3 = static_cast<int>(GetGValue(color));
			B3 = static_cast<int>(GetBValue(color));

			if (R3 > 12)//pri x3
			{
				if (R3 / 3 + 5 > G3 && R3 / 3 + 5 > B3)
				{
					autoshot();
					continue;
				}
			}

			//color = GetPixel(hDC, x4, pt.y);
			//R4 = static_cast<int>(GetRValue(color));
			//G4 = static_cast<int>(GetGValue(color));
			//B4 = static_cast<int>(GetBValue(color));
			//if (R4 > 12)//pri x4
			//{
			//	if (R4 / 3 + 5 > G4 && R4 / 3 + 5 > B4)
			//	{
			//		autoshot();
			//		continue;
			//	}
			//}

			//ReleaseDC(ActWin, hDC);
			//int Tac = GetTickCount();
			//cout << "time : " << Tac - Tic << endl;
		}

		Sleep(1000);
	}

	/*INPUT inp;
	inp.type = INPUT_MOUSE;
	inp.mi.dx = pt.x;
	inp.mi.dy = pt.y;
	//inp.mi.time = 0;
	inp.mi.mouseData = 0;


	inp.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	if (SendInput(1, &inp, sizeof(INPUT)) == NULL)
	{
	cout << "Eror1 : " << GetLastError();
	}
	Sleep(50);
	inp.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	if (SendInput(1, &inp, sizeof(INPUT)) == NULL)
	{
	cout << "Eror2 : " << GetLastError();
	}
	SetCursorPos(pt.x, pt.y);

	Sleep(1000);*/
	//system("pause");
    return 0;
}

