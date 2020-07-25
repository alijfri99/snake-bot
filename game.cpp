#include<iostream>
#include<Windows.h>
#include "tools.h"
#include "snake.h"
#include "bfs.h"

using namespace std;

int main()
{
	hideCursor();
	displayMap();
	snake s;
	s.print();
	vector<string> v;
	v = bfs(s);
	while (true)
	{
		if (GetKeyState('F'))
			break;
	}
	while (true)
	{
		if (v.empty())
		{
			s.increaseSize();
			v = bfs(s);
		}
		else
		{
			string temp = v.back();
			v.pop_back();
			interpretmove(temp, s);
		}
		s.move();
		s.print();
		if (gameover(s))
			break;
		Sleep(100);
	}
}