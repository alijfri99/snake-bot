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
		if (gameover(s))
			break;
		Sleep(120);
	}
}