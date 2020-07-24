#include<iostream>
#include<Windows.h>
#include "tools.h"
#include "snake.h"

using namespace std;

void gotoij(int i, int j)
{
	COORD coord;
	coord.X = j;
	coord.Y = i;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = FALSE;
	info.dwSize = 10;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void displayMap()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (i == 0 || i == 19)
				cout << "#";
			else if (j == 0 || j == 39)
				cout << "#";
			else cout << " ";
		}
		cout << endl;
	}
}

bool gameover(snake s)
{
	if (s.head.i == 0 || s.head.i == 19 || s.head.j == 0 || s.head.j == 39)
		return true;
	return false;
}