#include<iostream>
#include<Windows.h>
#include "tools.h"
#include "snake.h"

using namespace std;

int main()
{
	hideCursor();
	displayMap();
	snake s;
	s.print();
	while (true)
	{
		s.move();
		s.print();
		if (GetAsyncKeyState('W'))
			s.turn(direction::up);
		if (GetAsyncKeyState('S'))
			s.turn(direction::down);
		if (GetAsyncKeyState('A'))
			s.turn(direction::left);
		if (GetAsyncKeyState('D'))
			s.turn(direction::right);
		if (gameover(s))
			break;
		Sleep(120);
	}
}