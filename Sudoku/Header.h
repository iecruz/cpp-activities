#include <iostream>
#include <Windows.h>
#include <conio.h>

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

using namespace std;

void gotoxy(int x, int y)
{
	CursorPosition = { x, y };
	SetConsoleCursorPosition(handle, CursorPosition);
}

void color(int x, int y)
{
	SetConsoleTextAttribute(handle, (x*16 + y));
}

void bg()
{
	for (int y = 0; y < 3; y++){
		for (int x = 0; x < 3; x++){
			if ((y*x) % 2 == 0)
				color(8, 0);
			else
				color(7, 0);
			for (int i = 0; i < 6; i++){
				gotoxy(25 + (x * 9), 3 + i*(y + 1));
				cout << "	    ";
			}
		}
	}
}